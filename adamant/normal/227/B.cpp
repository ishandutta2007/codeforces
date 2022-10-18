#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    int*a=new int[n];
    int*af=new int[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    af[i]=0;
    }
    int m;
    cin>>m;
    int*b=new int[m];
    for(int i=0;i<m;i++)
    {
    cin>>b[i];
    af[b[i]-1]++;
    }
    
    long long ans1=0,ans2=0;
    for(int i=0;i<n;i++)
    {
            int t=af[a[i]-1];
            if(t)
            {
                          ans1+=t*(i+1);
                          ans2+=t*(n-i);
                          
            }              
    }
    cout<<ans1<<' '<<ans2<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}