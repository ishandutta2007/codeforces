#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll pows[100005];
ll pows2[100005];
ll c[255][255];
ll save[255];
ll dp[255];
int main()
{
    ll n,k;
    cin>>n>>k;
    pows[0]=pows2[0]=1;
    for(int i=1;i<100005;i++)
    {
        pows[i]=pows[i-1]*k%mod;
        pows2[i]=pows2[i-1]*(k-1)%mod;
    }
    for(int i=0;i<255;i++)
    {
        c[i][i]=c[i][0]=1;
    }
    for(int i=2;i<255;i++)for(int j=1;j<254;j++)
    {
        c[i][j]=c[i-1][j-1]+c[i-1][j];
        c[i][j]%=mod;
    }
    save[0]=1;
    for(int k=1;k<=n;k++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(i==j)
                {
                    dp[j]+=save[i]*pows2[n-i]%mod*(pows[i]-pows2[i]+mod);
                    dp[j]%=mod;
                }
                else
                {//if(i==0&&j==1)cout<<save[i]<<" "<<c[n-i][j-i]<<" "<<pows[i]<<" "<<pows2[n-j]<<endl;
                    dp[j]+=save[i]*c[n-i][j-i]%mod*pows[i]%mod*pows2[n-j];
                    dp[j]%=mod;
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            save[i]=dp[i];
            dp[i]=0;
        }
    }
    cout<<save[n]<<endl;
    return 0;
}