#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll dp[1000005];
ll sum[1000005];
ll mod=998244353;
int num[1000005];
int prime[1000005];
int main()
{
    for(int i=2;i<=1000000;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2;i*j<=1000000;j++)
            {
                prime[i*j]=i;
            }
        }
    }
    //for(int i=2;i<=30;i++)if(prime[i]==0)cout<<i<<endl;
    num[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(prime[i]==0)num[i]=2;
        else
        {
            int k=i;
            int p=prime[k];
            int s=0;
            while(k%p==0)
            {
                k/=p;
                s++;
            }
            num[i]=num[k]*(s+1);
        }
    }
    //for(int i=2;i<=30;i++)cout<<i<<" "<<num[i]<<endl;
    dp[1]=sum[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        dp[i]=num[i]+sum[i-1];
        dp[i]%=mod;
        sum[i]=(sum[i-1]+dp[i])%mod;

    }
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
    return 0;
}