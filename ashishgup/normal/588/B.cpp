#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    if(n<=10)
    {
        vector<bool> v(n+1,true);
        v[0]=v[1]=false;
        for(long long i=2;i<n+1;i++)
            {
                if(v[i]==true)
                {
                    for(long long j=2;i*j<n+1;j++)
                    {
                        v[i*j]=false;
                    }
                }
            }
        long long ans=1;
        for(long long i=2;i<n+1;i++)
        {
            if(v[i]==true)
            {
                if(n%i==0)
                {
                    ans*=i;
                }
            }
        }
        cout<<ans;
    }
    else
    {
        vector<bool> v((int)sqrt(n)+1,true);
        int num1=sqrt(n)+1;
        v[0]=v[1]=false;
        for(long long i=2;i*i<=num1;i++)
            {
                if(v[i]==true)
                {
                    for(long long j=2;i*j<=num1;j++)
                    {
                        v[i*j]=false;
                    }
                }
            }
        long long ans=1;
        long long num=n;
        for(long long i=2;i*i<=n;i++)
        {
            if(v[i]==true)
            {
                if(num%i==0)
                {
                    while(num%i==0)
                    {
                        num=num/i;
                    }
                    ans*=i;
                }
            }
        }
        cout<<ans*num;
    }
    return 0;
}