#include"bits/stdc++.h"
using namespace std;
int dp[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            dp[a]=i-1;
        }
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            dp[a]=i-1;
        }
        for(int i=3;i<=2*n;i+=2)
        {
            dp[i]=min(dp[i],dp[i-2]);
        }
        for(int i=2*n-2;i>0;i-=2)
        {
            dp[i]=min(dp[i],dp[i+2]);
        }
        int ans=1e6;
        for(int i=1;i<=2*n;i+=2)
        {
            ans=min(ans,dp[i]+dp[i+1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}