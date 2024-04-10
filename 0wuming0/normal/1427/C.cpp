#include"bits/stdc++.h"
using namespace std;
int dp[100005];
int ans[100005];
int t[100005],x[100005],y[100005];
int main()
{
    int r,n;
    cin>>r>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",t+i,x+i,y+i);
    }
    t[0]=0;x[0]=y[0]=1;
    int best,ed;
    for(int i=1;i<=n;i++)
    {
        if(i<=1002)best=-1000005;
        else best=ans[i-1001]+1;
        for(int j=max(0,i-1002);j<i;j++)if(t[j]+abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i])
        {
            best=max(best,dp[j]+1);
        }
        dp[i]=best;
        ans[i]=max(ans[i-1],best);
    }
    cout<<ans[n]<<endl;
    return 0;
}