#include <iostream>
#include <math.h>

#define ld long double
#define ll long long

using namespace std;

int main()
{
    ld x,y,n;
    ll a;
    cin>>x>>y>>n;
    ld min=2e9;
    ld mod=x/y;
    ld ax,ay,t1,i;
    for(i=1;i<=n;i++)
    {
            a=mod*i+0.4999;
            t1=fabs(a/i-mod);
            if(t1<min)
            min=t1,ax=a,ay=i;   
            
    }
    cout<<ax<<'/'<<ay<<endl;
}