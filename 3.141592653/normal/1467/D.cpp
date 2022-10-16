#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
const ll mod=1e9+7;
ll dp[5055][5055],v[5055],x[5055];
int n,k,q;
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	register int i,ii;
	for(i=1;i<=n;i++)dp[0][i]=1;
	for(i=1;i<=k;i++)
		for(ii=1;ii<=n;ii++)
			dp[i][ii]=(dp[i-1][ii-1]+dp[i-1][ii+1])%mod; 
	for(i=0;i<=k;i++)
		for(ii=1;ii<=n;ii++)
		{
			(v[ii]+=dp[i][ii]*dp[k-i][ii])%=mod;
		}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",x+i);
		(ans+=v[i]*x[i])%=mod;
	}
	for(i=1;i<=q;i++)
	{
		int p,g;
		scanf("%d%d",&p,&g);
		(ans+=v[p]*(g+mod-x[p]))%=mod;
		x[p]=g;
		printf("%lld\n",ans);
	}
}
/*
Please don't let me down.
*/