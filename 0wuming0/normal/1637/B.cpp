#include"bits/stdc++.h"
using namespace std;
int a[105];
int dp[105][105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=n;i++)if(a[i]==0)dp[i][i]=2;
        else dp[i][i]=1;
        for(int dis=1;dis<=n;dis++)for(int i=1,j=dis+1;j<=n;i++,j++)
        {
            dp[i][j]=0;
            set<int>mp;
            int mex=0;
            for(int k=j;k>=i;k--)
            {
                mp.insert(a[k]);
                while(mp.find(mex)!=mp.end())mex++;
                dp[i][j]=max(dp[i][k-1]+mex+1,dp[i][j]);
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)ans+=dp[i][j];
        cout<<ans<<endl;
    }
    return 0;
}