#ifndef ___PID_H
#define ___PID_H

#include <stdio.h>
#include <stdint.h>
#include <Math.h>


typedef struct {
	float Target; 			        //设定目标值
	float Measured; 				    //测量值
	float err; 						      //本次偏差值
	float err_last; 				    //上一次偏差
	float err_beforeLast; 			//上上次偏差
	float Kp, Ki, Kd;				    //Kp, Ki, Kd控制系数
	float p_out, i_out, d_out;//各部分输出值
	float pwm; 						      //pwm输出
	uint32_t MaxOutput;				  //输出限幅
	uint32_t IntegralLimit;			//积分限幅 
}incrementalpid_t;

typedef struct {
	float Target; 					    //设定目标值
	float Measured; 				    //测量值
	float err; 						      //本次偏差值
	float err_last; 				    //上一次偏差
	float err_change; 				    //误差变化率
	float Kp, Ki, Kd;				    //Kp, Ki, Kd控制系数
	float p_out, i_out, d_out;//各部分输出值
	float pwm; 						      //pwm输出
	uint32_t MaxOutput;				  //输出限幅
	uint32_t IntegralLimit;			//积分限幅 
}positionpid_t;

void PositionPID_paraReset(positionpid_t *pid_t, float kp, float ki, float kd, uint32_t MaxOutput, uint32_t IntegralLimit);
void PositionPID_setPara(positionpid_t *pid_t, float kp, float ki, float kd);
float Position_PID(positionpid_t *pid_t, float target, float measured);

void IncrementalPID_paraReset(incrementalpid_t *pid_t, float kp, float ki, float kd, uint32_t MaxOutput, uint32_t IntegralLimit);
void IncrementalPID_setPara(incrementalpid_t *pid_t, float kp, float ki, float kd);
float Incremental_PID(incrementalpid_t *pid_t, float target, float measured);

#endif

