#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int mod=1000000007;
    int n,m;
    scanf("%d%d",&n,&m);
    char s[n][m+1];
    for(int o=0;o<n;o++) scanf("%s",s[o]);
    if(n==1&&m==1)
    {
        printf("1\n");
        return 0;
    }
    int dp[n][m][2];
    dp[n-1][m-1][0]=dp[n-1][m-1][1]=(s[n-1][m-1]!='R');
    int cnt[n+1][m+1][2];
    int rock[n+1][m+1][2];
    for(int o=0;o<=n;o++) for(int i=0;i<=m;i++) for(int j=0;j<2;j++) cnt[o][i][j]=rock[o][i][j]=0;
    cnt[n-1][m-1][0]=cnt[n-1][m-1][1]=(s[n-1][m-1]!='R');
    for(int o=n-1;o>=0;o--)
    {
         for(int i=m-1;i>=0;i--)
         {
             rock[o][i][0]=rock[o+1][i][0]+(s[o][i]=='R');
             rock[o][i][1]=rock[o][i+1][1]+(s[o][i]=='R');
         }
    }
    for(int o=n-1;o>=0;o--)
    {
        for(int i=m-1;i>=0;i--)
        {
            if(o==n-1&&i==m-1) continue;
            dp[o][i][0]=(cnt[o+1][i][1]-cnt[n-rock[o+1][i][0]][i][1]+mod)%mod;
            cnt[o][i][0]=(cnt[o][i+1][0]+dp[o][i][0])%mod;
            dp[o][i][1]=(cnt[o][i+1][0]-cnt[o][m-rock[o][i+1][1]][0]+mod)%mod;
            cnt[o][i][1]=(cnt[o+1][i][1]+dp[o][i][1])%mod;
        }
    }
    printf("%d\n",(dp[0][0][0]+dp[0][0][1])%mod);
    return 0;
}