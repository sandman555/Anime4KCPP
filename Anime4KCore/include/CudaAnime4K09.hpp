#pragma once

#ifdef ENABLE_CUDA

#include"CudaInterface.hpp"
#include"FilterProcessor.hpp"

namespace Anime4KCPP
{
    namespace Cuda
    {
        class DLL Anime4K09;
    }
}

class Anime4KCPP::Cuda::Anime4K09 :public AC
{
public:
    Anime4K09(const Parameters& parameters = Parameters());
    virtual ~Anime4K09() = default;

    virtual std::string getInfo() override;
    virtual std::string getFiltersInfo() override;
private:
    void runKernelB(const cv::Mat& orgImg, cv::Mat& dstImg);
    void runKernelW(const cv::Mat& orgImg, cv::Mat& dstImg);
    void runKernelF(const cv::Mat& orgImg, cv::Mat& dstImg);

    virtual void processYUVImageB() override;
    virtual void processRGBImageB() override;
    virtual void processRGBVideoB() override;

    virtual void processYUVImageW() override;
    virtual void processRGBImageW() override;

    virtual void processYUVImageF() override;
    virtual void processRGBImageF() override;

    virtual Processor::Type getProcessorType() noexcept override;
};

#endif
