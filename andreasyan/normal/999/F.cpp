#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=100000;

int n,k;
int a[M+5];
int f[N];
int h[11];

int stg(int x)
{
    int t=0;
    for(int i=0;i<n;++i)
        if(f[i]==x)
            ++t;
    bool c[N*11]={};
    int dp[N*11]={};
    c[0]=true;
    while(t--)
    {
        for(int i=a[x];i>=0;--i)
        {
            if(!c[i])
                continue;
            for(int j=0;j<k;++j)
            {
                if(i+j+1<=a[x])
                {
                    c[i+j+1]=true;
                    dp[i+j+1]=max(dp[i+j+1],dp[i]+h[j]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=a[x];++i)
        ans=max(ans,dp[i]);
    return ans;
}

int32_t main()
{
    cin>>n>>k;
    for(int i=0;i<n*k;++i)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=0;i<n;++i)
        cin>>f[i];
    for(int i=0;i<k;++i)
        cin>>h[i];
    int ans=0;
    for(int i=1;i<=M;++i)
    {
        if(a[i])
        {
            ans+=stg(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}