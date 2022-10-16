#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
cpnst ll mod=1e9+7;
int dp[2111111],ds[2111111],dl[2111111],tp[2111111];
int main()
{
	dp[1]=1;
	register int i;
	for(i=2;i<=2e6;i++)
	{
		dp[i]=(dp[i-1]+2ll*ds[i-1])%mod;
		ds[i]=dp[i-1];
		dl[i]=ds[i-1];
		tp[i]=(dl[i]+tp[i-3])%mod;
	}int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",tp[n]*4ll%mod);
	}
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/