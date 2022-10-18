#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    int max=0;
    
    for(int i=0;i<n;i++)
    {
            int cur=a[i];
    if(cur>max)
    max=cur;
    for(int j=i+1;j<n;j++)
    {
    cur^=a[j];
    if(cur>max)
    max=cur;
    }
    if(cur>max)
    max=cur;
    }
    cout<<max<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}