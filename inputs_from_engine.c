/* *****************************************************************************
--------------------------------------------------------------------------------
 Software item:      Engine Control Software
 Software component: inputs_from_engine
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
 Firmware:  TBD
 Filename:  inputs_from_engine.c
 Author:    TBD
 Revision:  TBD
 Updated:   TBD

 Comments: Add more data
 Sayantan Demo Edit 04/09
***************************************************************************** */

/* *****************************************************************************
                                 Include Files                              
*/
#include "inputs_from_engine.h"    
/* ************************************************************************** */

/* *****************************************************************************
                                 Public Functions
***************************************************************************** */

/* -----------------------------------------------------------------------------
 Description:  
    Get engine speed value measured via Speed Sensor S1
 Function parameters:   
    None 
 Return value:       
    Speed value from S1   
 Requirement ID:
    SDR-80003
----------------------------------------------------------------------------- */ 
uint16 guint16_get_speed_n1(void)
{
  uint16 l_adc1_value = 0;
  uint16 l_speed_s1 = 0;
  
  /* get actual speed value from ADC1 */
  l_adc1_value = guint16_get_adc1_value();
  
  /* if value from ADC is lower or equal to ADC_MAX_VALUE then do linear interpolation */
  if (l_adc1_value <= ADC_MAX_VALUE) 
  {
	l_speed_s1 = SPEED_CALC_LIN_INT*l_adc1_value;	
  }
  /* if value from ADC is higher than ADC_MAX_VALUE then set it to high limit */
  else
  {
	l_speed_s1 = ADC_MAX_VALUE;
  }
  
  /* return speed value from S1 */
  return (l_speed_s1);
}

/* -----------------------------------------------------------------------------
 Description :  
    Get engine speed value measured via Speed Sensor S2
 Function parameters :   
    None
 Return value:       
    Speed value from S2   
 Requirement ID:
    SDR-94076
----------------------------------------------------------------------------- */ 
uint16 guint16_get_speed_n2(void)
{
  uint16 l_adc2_value = 0;
  uint16 l_speed_s2 = 0;
  
  /* get actual speed value from ADC2 */
  l_adc2_value = guint16_get_adc2_value();
  
  /* if value from ADC is lower or equal to ADC_MAX_VALUE then do linear interpolation */
  if (l_adc1_value <= ADC_MAX_VALUE) 
  {
	l_speed_s2 = SPEED_CALC_LIN_INT*l_adc2_value;	
  }
  /* if value from ADC is higher than ADC_MAX_VALUE then set it to high limit */
  else
  {
	l_speed_s2 = ADC_MAX_VALUE;
  }
  
  /* return speed value from S1 */
  return (l_speed_s2);
}

/* -----------------------------------------------------------------------------
 Description :  
    Get valid engine speed value
 Function parameters :   
    TBD 
 Return value:       
    TBD   
 Requirement ID:
    SDR-94077
----------------------------------------------------------------------------- */ 
uint16 guint16_get_engine_speed(void)
{
  ;	
}

