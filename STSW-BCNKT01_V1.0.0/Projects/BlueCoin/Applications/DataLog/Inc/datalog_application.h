/**
  ******************************************************************************
  * @file    DataLog/Inc/datalog_application.h
  * @author  Central Labs
  * @version V1.0.0
  * @date    27-April-2017
  * @brief   Header for datalog_application.c module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DATALOG_APPLICATION_H
#define __DATALOG_APPLICATION_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32f4xx_hal.h"
#include "BlueCoin.h"
#include "stm32f4xx_hal_conf.h"
#include "stm32f4xx_hal_def.h"

 /* comment out the sampling frenquency chosen */ 
#define SAMPLING_25Hz 
//#define SAMPLING_50Hz 
//#define SAMPLING_100Hz 
  
#if defined( SAMPLING_25Hz)
  #define DEFAULT_uhCCR1_Val 390
  #define ACCELERO_ODR 25.0f
  #define GYRO_ODR 26.0f
  #define MAGNETO_ODR 20.0f
  #define PRESSURE_ODR 25.0f
  #define DATA_PERIOD_MS     (2)

#elif defined( SAMPLING_50Hz)
  #define DEFAULT_uhCCR1_Val 190
  #define ACCELERO_ODR 50.0f
  #define GYRO_ODR 52.0f
  #define MAGNETO_ODR 50.0f
  #define PRESSURE_ODR 50.0f
  #define DATA_PERIOD_MS     (20)

#elif defined( SAMPLING_100Hz)
  #define DEFAULT_uhCCR1_Val 100
  #define ACCELERO_ODR 100.0f
  #define GYRO_ODR 104.0f
  #define MAGNETO_ODR 100.0f
  #define PRESSURE_ODR 50.0f
  #define DATA_PERIOD_MS     (10)
#endif

#define TEMPERATURE_ODR 12.5f
#define HUMIDITY_ODR 12.5f
  
typedef enum
{
  USB_Datalog = 0,
  SDCARD_Datalog
} LogInterface_TypeDef;


typedef struct
{
  uint32_t ms_counter;
  float pressure;
  float humidity;
  float temperature;
  SensorAxes_t acc;
  SensorAxes_t gyro;
  SensorAxes_t mag;
  uint16_t range;
} T_SensorsData;
  
extern LogInterface_TypeDef LoggingInterface;
extern volatile uint8_t SD_Log_Enabled;

void DATALOG_SD_Init(void);
uint8_t DATALOG_SD_Log_Enable(void);
uint8_t DATALOG_SD_writeBuf(char *s, uint32_t size);
void DATALOG_SD_Log_Disable(void);
void DATALOG_SD_DeInit(void);
void DATALOG_SD_NewLine(void);
DrvStatusTypeDef getSensorsData( T_SensorsData *mptr);

#ifdef __cplusplus
}
#endif

#endif /* __DATALOG_APPLICATION_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
