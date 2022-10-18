#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    long long b[100000];
    b[0]=1;
    for(int i=2;i<=100000;i++)
    b[i-1]=b[i-2]+i;
    long long n,d;
    cin>>n>>d;
    long long a[n];
    long long ans=0;
    int st=0;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    for(int j=st;j<i-1;j++)
    {
            if(a[i]-a[j]>d)
            {
                           st=j+1;
            }
            else
            break;
    }
    if(i-st>=2)
    {
    //cout<<i<<' '<<st<<' '<<b[i-st-2]<<endl;
    ans+=b[i-st-2];
    }
    }
    
    cout<<ans<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}