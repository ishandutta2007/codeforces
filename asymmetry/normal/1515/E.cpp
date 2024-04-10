//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>
#pragma GCC optimize "O3"

using namespace std;

#define N 410

int n, mod;
long long nk[N][N];
long long dp[N][N];
long long pd[N];

int main()
{
	scanf("%d%d", &n, &mod);
	for(int i=0; i<=n; ++i) nk[i][0]=nk[i][i]=1;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<i; ++j)
		{
			nk[i][j]=nk[i-1][j]+nk[i-1][j-1];
			if(nk[i][j]>=mod) nk[i][j]-=mod;
		}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			pd[i]+=nk[i-1][j-1];
		}
		pd[i]%=mod;
		//~ printf("%d: %lld\n", i, pd[i]);
	}
	dp[1][1]=1;
	for(int i=2; i<=n; ++i)
	{
		dp[i][i]=pd[i];
		for(int j=1; j<=i; ++j)
		{
			for(int k=2; k<i; ++k)
			{
				dp[i][j]+=dp[k-1][j-i+k]*nk[j][i-k]%mod*pd[i-k];
				dp[i][j]%=mod;
			}
			//~ printf("%d %d -> %lld\n", i, j, dp[i][j]);
		}
	}
	long long odp=0;
	for(int i=1; i<=n; ++i) odp+=dp[n][i];
	printf("%lld\n", odp%mod);
	return 0;
}