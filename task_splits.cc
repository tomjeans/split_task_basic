#include <iostream>
#include <vector>
#include <thread>
#include <map>

class task_split
{
    public:
          std::vector<std::pair<int,int>> start_end;
          int task_size;
          int thread_nums;
          task_split(int threads_nums);
          ~task_split();
          std::vector<std::pair<int,int>> get_splits(int size_tasks);
          

};

task_split::task_split(int threads_nums)
{
    this->thread_nums=threads_nums;
}

task_split::~task_split()
{

}

std::vector<std::pair<int,int>> task_split::get_splits(int size_tasks)
{
    int per_thread_Sum = size_tasks/thread_nums;
   //std::cout<<"per_thread_Sum :"<<per_thread_Sum<<std::endl;
   
   int rest_task_Sum  = size_tasks-per_thread_Sum*thread_nums;
   //std::cout<<" rest task :"<<rest_task_Sum<<std::endl;


   for(int block_=0;block_<thread_nums;block_++)
   {
   		//std::cout<<block_*per_thread_Sum<<" "<<block_*per_thread_Sum+per_thread_Sum<<std::endl;
        start_end.push_back(std::pair<int,int>(block_*per_thread_Sum,block_*per_thread_Sum+per_thread_Sum-1));

        //std::cout<<tasks[block_*per_thread_Sum]<<" "<<tasks[block_*per_thread_Sum+per_thread_Sum-1]<<std::endl;
        //std::cout<<"\n";
   }

   int last_start = size_tasks-2;
   int last_end = size_tasks-2+rest_task_Sum;

   if(rest_task_Sum!=0)
   {
    start_end.push_back(std::pair<int,int>(last_start,last_end));
   }

   return start_end;

}
