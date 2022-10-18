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
    int n;
    cin>>n;
    int sum[3];
    sum[0]=0;
    sum[1]=0;
    sum[2]=0;
    for(int i=0;i<n;i++)
    {
            int t;
            cin>>t;
            sum[i%3]+=t;
    }
    if(sum[0]>sum[1] && sum[0]>sum[2])
    cout<<"chest"<<endl;
    else if(sum[1]>sum[0] && sum[1]>sum[2])
    cout<<"biceps"<<endl;
    else cout<<"back"<<endl;
    
    
    return EXIT_SUCCESS;
}