/*
 * hw-pipeline.h
 *
 *  Created on: 13 Oct 2016
 *      Author: sugeshch
 */

#ifndef LIB_HW_PIPELINE_H_
#define LIB_HW_PIPELINE_H_
#include "unistd.h"
#include "stdio.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "errno.h"
#include "fcntl.h"
#include "flow.h"
#include "dpif-netdev.h"

#define HW_NO_FREE_FLOW_TAG 0xffffffff
#define HW_PIPELINE_MSGQ_TO 10000
#define HW_MAX_FLOW_TAG 65536
#define MSG_QUEUE_MAX_SIZE 65536

enum pipeline_id {
    DEFAULT_SW_PIPELINE = 0,
    HW_OFFLOAD_PIPELINE
};

typedef enum{
    HW_PIPELINE_NO_RULE,
    HW_PIPELINE_INSERT_RULE,
    HW_PIPELINE_REMOVE_RULE
}HW_pipeline_msgq_mode;

struct pipeline_md {
    uint16_t id; 
    uint32_t flow_tag;
};

#define OVS_GET_HANDLE_VALUE(x,s,w)     ((x>>s)&((1<<(w+1))-1))

#define OVS_FLOW_TAG_INDEX_W            16
#define OVS_FLOW_TAG_INDEX_S            0
#define OVS_FLOW_TAG_INDEX_M            ((1<<(OVS_FLOW_TAG_INDEX_W+1))-1)
#define OVS_FLOW_TAG_INDEX_GET(x) \
   OVS_GET_HANDLE_VALUE(x,OVS_FLOW_TAG_INDEX_S,OVS_FLOW_TAG_INDEX_W)

#endif /* LIB_HW_PIPELINE_H_ */
