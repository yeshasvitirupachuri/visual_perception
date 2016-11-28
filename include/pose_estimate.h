/*
 * Copyright (c) 2016, <copyright holder> <email>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> <email> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> <email> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef POSE_ESTIMATE_H
#define POSE_ESTIMATE_H

#include "frame_grabber.h"

namespace visual_perception
{
    class PoseEstimation
    {
        private:
            
            std::string eye_name_; 
            std::string robot_name_;
            iCub::iKin::iCubEye *eye_chain_;
            yarp::sig::Vector *head_state_;
            yarp::os::BufferedPort<yarp::sig::Vector> *head_state_input_port_;
            
            yarp::sig::Vector eye_pose_;
        public:
            visual_perception::FrameGrabber* frame_grabber_;
            //Default Constructor 
            PoseEstimation()
            {
                std::cout << "Pose estimation default constructor" << std::endl;
            }
            
            PoseEstimation(std::string,std::string);
            void eyePoseCompute();
            yarp::sig::Vector getEyePose(){return eye_pose_;};
            
            
            
            //Destructor
            ~PoseEstimation();
    };
}

#endif // POSE_ESTIMATE_H