#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

#define ll long long
#define ld long double

int main(int argc, char *argv[])
{
     int n;
     cin>>n;
     int*a=new int[n];
     int*ans=new int[n];
     for(int i=0;i<n;i++)
     {
     cin>>a[i];
     ans[i]=a[i];
     }
     int m;
     cin>>m;
     int*x=new int[m];
     int*y=new int[m];
     for(int i=0;i<m;i++)
     {
     cin>>x[i]>>y[i];
     if(x[i]>1)
     ans[x[i]-2]+=y[i]-1;
     if(x[i]<n)
     ans[x[i]]+=ans[x[i]-1]-y[i];
     ans[x[i]-1]=0;
     }
     
     
     
     for(int i=0;i<n;i++)
     cout<<ans[i]<<' ';
     cout<<endl;

     return 0;
}