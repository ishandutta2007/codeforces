#include"bits/stdc++.h"
using namespace std;
int dp[3503];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<3503;i++)dp[i]=i;
        while(n--)
        {
            int a;
            scanf("%d",&a);
            for(int i=3502;i>=a;i--)
            {
                dp[i]=max(dp[i-a],i);
            }
            for(int i=0;i<a;i++)dp[i]=100000;
            for(int i=0;i<3503;i++)if(dp[i]-i<3503)
            {
                dp[dp[i]-i]=min(dp[i],dp[dp[i]-i]);
            }
        }
        int ans=100000;
        for(int i=0;i<3503;i++)ans=min(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}
/*
4000
20
1000 1000
*/