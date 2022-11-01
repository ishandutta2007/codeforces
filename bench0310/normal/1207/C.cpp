#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        long long n,a,b;
        scanf("%I64d%I64d%I64d",&n,&a,&b);
        char s[n+5];
        scanf("%s",s+1);
        s[n+1]='0';
        long long dp[n+1][2];
        for(int o=0;o<=n;o++) for(int i=0;i<2;i++) dp[o][i]=1000000000000000000;
        dp[0][0]=b;
        for(int o=1;o<=n;o++)
        {
            if(s[o]=='0'&&s[o+1]=='0') dp[o][0]=min(dp[o-1][0]+a+b,dp[o-1][1]+2*a+b);
            dp[o][1]=min(dp[o-1][1]+a+2*b,dp[o-1][0]+2*a+2*b);
        }
        printf("%I64d\n",dp[n][0]);
    }
	return 0;
}