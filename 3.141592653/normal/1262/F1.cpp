#include<cstdio>
#include<cstring>
typedef long long ll;
typedef double db;
const ll mod=998244353;
ll __dp[2222][4444],*dp[2222];
int n,k;
int a[222222];
int main()
{
	scanf("%d%d",&n,&k);
	register int i,ii;
	for(i=0;i<=2200;i++)dp[i]=__dp[i]+2222;
	dp[0][0]=1;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=a[1];
	for(i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			for(ii=-i;ii<=i;ii++)
			dp[i][ii]=(dp[i-1][ii]*k)%mod;
			continue;	
		}
		for(ii=-i;ii<=i;ii++)
		{
			dp[i][ii]=(dp[i-1][ii]*(k-2)+
			dp[i-1][ii-1]+dp[i-1][ii+1])%mod;
		}
	}ll ans=0;
	for(i=1;i<=n;i++)ans+=dp[n][i];
	printf("%I64d\n",ans%mod);
}