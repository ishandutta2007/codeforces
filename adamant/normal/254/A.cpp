#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n;
    
    in>>n;
    
    int*a=new int[2*n];
    vector<int>*nums=new vector<int>[5001];
    
    for(int i=0;i<2*n;i++)
    {
            in>>a[i];
            nums[a[i]-1].push_back(i+1);
    }
    
    for(int i=0;i<5001;i++)
    if(nums[i].size()%2)
    {
                     out<<-1<<endl;
                     return 0;
    }
    for(int i=0;i<5001;i++)
    if(nums[i].size())
    {
                   for(int j=0;j<nums[i].size();j+=2)               
    out<<nums[i][j]<<' '<<nums[i][j+1]<<endl;
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}