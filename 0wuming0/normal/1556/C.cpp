#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[100005];
ll dp[1005][1005][2];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int dis=0;dis<n;dis++)for(int i=1;i<=n;i++)
    {
        int j=i+dis;
        dp[i][j][0]=dp[i][j-1][0];
        dp[i][j][1]=dp[i][j-1][1];
        if(j%2==1)
        {
            dp[i][j][0]+=a[j];
        }
        else
        {
            int k=min(a[j],dp[i][j][0]);
            int ad=a[j]-k;
            dp[i][j][0]-=k;
            dp[i][j][1]+=ad;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i+=2)for(int j=i+1;j<=n;j+=2)
    {
        ll l=a[i];
        ll r=a[j];//cout<<"<<"<<i<<" "<<j<<" "<<l<<" "<<r<<"  "<<dp[i+1][j-1][0]<<" "<<dp[i+1][j-1][1]<<endl;
        r-=dp[i+1][j-1][0];
        l-=dp[i+1][j-1][1];
        if(r>=0&&l>=0)
        {
            ans+=min(r,l)+1;
        }//cout<<"??"<<min(r,l)+1<<endl;
    }
    cout<<ans-n/2<<endl;
    return 0;
}