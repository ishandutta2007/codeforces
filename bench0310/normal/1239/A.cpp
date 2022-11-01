#include <bits/stdc++.h>

using namespace std;

const long long mod=1000000007;

long long solve(int n)
{
    long long dp[n][2][2]; //0-white, 1-black || 0-first,1-second
    dp[0][0][0]=dp[0][1][0]=1;
    dp[0][0][1]=dp[0][1][1]=0;
    for(int i=1;i<n;i++)
    {
        dp[i][0][0]=(dp[i-1][1][0]+dp[i-1][1][1])%mod;
        dp[i][0][1]=dp[i-1][0][0];
        dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][0][1])%mod;
        dp[i][1][1]=dp[i-1][1][0];
    }
    return ((dp[n-1][0][0]+dp[n-1][0][1]+dp[n-1][1][0]+dp[n-1][1][1]-2+mod)%mod);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long res=(2+solve(n)+solve(m))%mod;
    printf("%I64d\n",res);
	return 0;
}