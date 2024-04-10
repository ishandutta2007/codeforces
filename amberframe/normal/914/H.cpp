#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 205;
typedef long long LL;

int f[maxn][maxn];
int s[maxn][maxn];
int c[maxn][maxn],ans,n,m,mod;
int main()
{
	#ifndef ONLINE_JUDGE
//		freopen("trees.in","r",stdin);
	#endif
	scanf("%d %d %d",&n,&m,&mod);
	for (int i=0;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++)
			c[i][j]=((LL)c[i-1][j-1]+c[i-1][j])%mod;
	}
	f[1][0]=1;
	for (int i=0;i<=m;i++) s[1][i]=1;
	
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		for (int k=1;k<i;k++)
			f[i][j]=(f[i][j]+(LL)f[i-k][j-1]*(LL)s[k][m-1]%mod*(LL)c[i-2][k-1])%mod;
		for (int j=1;j<=m;j++)
			s[i][j]=((LL)s[i][j-1]+f[i][j])%mod;
	}
	
	int ans=0;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=m;j++)
	for (int k=0;j+k<=m;k++)
		if (k!=1) ans=(ans+(LL)f[i][j]*f[n-i+1][k])%mod;
	ans=(LL)ans*n%mod*(n-1)%mod*2ll%mod;
	printf("%d",ans%mod);
	return 0;
}