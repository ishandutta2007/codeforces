#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, mod=998244353;
int v[18][18];
long long dp[262144];
bitset <262144> bt, ok;
 
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		--a;
		--b;
		v[a][b]=v[b][a]=1;
	}
	for(int i=1; i<1<<n; ++i)
	{
		bt[i]=bt[(i-1)&i]^1;
		ok[i]=1;
		for(int j=0; j<n; ++j)
		{
			if(!ok[i])
			{
				break;
			}
			if(!(i>>j&1))
			{
				continue;
			}
			for(int k=0; k<n; ++k)
			{
				if((i>>k&1) && v[j][k])
				{
					ok[i]=0;
					break;
				}
			}
		}
	}
	dp[0]=1;
	for(int i=1; i<1<<n; ++i)
	{
		for(int j=i; j; j=(j-1)&i)
		{
			if(ok[j])
			{
				if(bt[j])
				{
					dp[i]+=dp[i^j];
				}
				else
				{
					dp[i]-=dp[i^j];
				}
			}
		}
		if(dp[i]>0)
		{
			dp[i]%=mod;
		}
		else
		{
			dp[i]=(mod-abs(dp[i])%mod)%mod;
		}
	}
	printf("%lld\n", (long long)dp[(1<<n)-1]*m%mod*499122177%mod);
	return 0;
}