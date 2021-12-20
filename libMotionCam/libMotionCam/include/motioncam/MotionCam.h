#ifndef MotionCam_hpp
#define MotionCam_hpp

#include <string>

#include "motioncam/ImageProcessorProgress.h"
#include "motioncam/DngProcessorProgress.h"

namespace motioncam {
    class RawContainer;

    float ConvertVideoToDNG(const std::string& inputFile,
                            const DngProcessorProgress& progress,
                            const int numThreads=4,
                            const int mergeFrames=0);

    float ConvertVideoToDNG(const int fd,
                            const DngProcessorProgress& progress,
                            const int numThreads=4,
                            const int mergeFrames=0);

    void ProcessImage(RawContainer& rawContainer, const std::string& outputFilePath, const ImageProcessorProgress& progressListener);
    void ProcessImage(const std::string& containerPath, const std::string& outputFilePath, const ImageProcessorProgress& progressListener);

    void GetMetadata(const int fd, float& outFrameRate, int& outNumFrames);
}

#endif /* MotionCam_hpp */
