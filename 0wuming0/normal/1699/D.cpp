#include"bits/stdc++.h"
using namespace std;
int a[5005];
int num[5005];
int dp[5005][5005];
bool tg[5005][5005];
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
            scanf("%d",a+i);
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)tg[i][j]=0;
        {
            for(int bg=0;bg<n;bg++)
            {
                int mx=0;
                for(int i=bg+1;i<=n;i++)
                {
                    num[a[i]]++;
                    mx=max(mx,num[a[i]]);
                    if((bg+i&1)==0)
                    {
                        if(mx<=i-bg-mx)
                        {
                            tg[bg][i]=1;
                        }
                    }
                }
                for(int i=bg+1;i<=n;i++)
                {
                    num[a[i]]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        {
            dp[i][j]=-1;
            if(tg[0][i])dp[i][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(dp[i-1][a[i]]!=-1)
            {
                dp[i][a[i]]=max(dp[i-1][a[i]]+1,dp[i][a[i]]);
                for(int j=i+1;j<=n;j++)
                {
                    if(tg[i][j])
                    {
                        dp[j][a[i]]=max(dp[j][a[i]],dp[i][a[i]]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,dp[n][i]);
        //for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",dp[i][j]," \n"[j==n]);
        cout<<ans<<endl;
    }
    return 0;
}
/*
12
1 4 3 3 3 3 4 4 4 4 4 4


*/