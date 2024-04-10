#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[105],b[105];
long long s[105];
long long dp[11105];
long long save[11105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=a[i]*a[i]*(n-1);
            ans+=b[i]*b[i]*(n-1);
            int k=min(a[i],b[i]);
            a[i]-=k;
            b[i]-=k;
            if(a[i]<b[i])swap(a[i],b[i]);
            for(int j=0;j<n;j++)if(j!=i)
            {
                ans+=(a[j]+b[j])*k*2;
            }
        }
        s[0]=a[0];
        for(int i=1;i<n;i++)s[i]=s[i-1]+a[i];
        int mx=100*n+10;
        for(int i=0;i<mx;i++)
        {
            dp[i]=1e18;
        }
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mx;j++)
            {
                save[j]=dp[j];
                dp[j]=1e18;
            }
            for(int j=0;j<mx;j++)if(save[j]<1e18)
            {//cout<<"<<<"<<i<<" "<<j<<" "<<save[j]<<endl;
                dp[j]=min(save[j]+a[i]*((i==0?0:(s[i-1]))-j),dp[j]);
                dp[j+a[i]]=min(save[j]+a[i]*j,dp[j+a[i]]);
            }
        }//cout<<"<<"<<ans<<endl;
        long long kk=1e18;
        for(int i=0;i<mx;i++)kk=min(kk,dp[i]);
        cout<<ans+kk*2<<endl;
    }
    return 0;
}