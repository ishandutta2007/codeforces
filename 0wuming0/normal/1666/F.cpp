#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
int a[5005];
int num[5005];
ll dp[5005];
ll save[5005];
ll inv[5005];
int main()
{
    inv[1]=1;
    for(int i=2;i<5005;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)cin>>a[i];
        if(a[n-1]==a[n])
        {
            cout<<0<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<1<<endl;
            continue;
        }
        if(a[n-2]==a[n-1])
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n-2;i++)num[a[i]]++;
        dp[2]=1;
        int s=2;
        for(int i=n;i>=1;i--)if(num[i])
        {
            memset(save,0,sizeof(save));
            for(int c=1;c<=num[i];c++)
            {
                if(c==num[i])
                {
                    for(int j=1;j<=(n>>1);j++)
                    {
                        save[j]=dp[j-1];
                    }
                }
                for(int j=2;j<=(n>>1);j++)
                {
                    if(j==(n>>1))dp[j]=dp[j]*(n-s)%mod*inv[c]%mod;
                    else if(2*j-1<=s)dp[j]=0;
                    else dp[j]=dp[j]*(2*j-1-s)%mod*inv[c]%mod;
                }
                s++;
            }
            for(int j=0;j<5005;j++)
            {
                dp[j]+=save[j];
                if(dp[j]>=mod)dp[j]-=mod;
            }
        }
        cout<<dp[n/2]<<endl;
    }
    return 0;
}