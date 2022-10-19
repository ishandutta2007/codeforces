#include"bits/stdc++.h"
using namespace std;
int dp[4][100005];
char s[2][100005];
int main()
{
    int t;
    cin>>t;
    dp[1][0]=-1000000;
    dp[2][0]=-1000000;
    dp[3][0]=-1000000;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        for(int i=1;i<=n;i++)
        {
            int a=s[0][i]-'0'+1;
            int b=s[1][i]-'0'+1;
            dp[0][i]=dp[1][i]=dp[2][i]=dp[3][i]=-1000000;
            for(int j=0;j<4;j++)dp[j|a|b][i]=max(dp[j|a|b][i],dp[j][i-1]);
            dp[0][i]=max(dp[0][i],dp[1][i]+1);
            dp[0][i]=max(dp[0][i],dp[2][i]);
            dp[0][i]=max(dp[0][i],dp[3][i]+2);//cout<<"<<<"<<i<<"  "<<a<<b<<" "<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<" "<<dp[3][i]<<endl;
        }
        printf("%d\n",dp[0][n]);
    }
    return 0;
}