#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=5005;
const int MOD=998244353;

int n,ny[N],f[N][N],g[N],a[N];

int main()
{
	scanf("%d",&n);
	ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		a[x]++;
	}
	f[n][0]=1;
	int ans=0;
	for (int i=n-1;i>=0;i--)
	{
		g[0]=f[i+1][0];
		for (int j=1;j<=n;j++) g[j]=(g[j-1]+f[i+1][j])%MOD;
		for (int j=1;j<=n;j++)
		{
			if (!a[j]) continue;
			f[i][j]=(LL)g[j-1]*a[j]%MOD*ny[i+1]%MOD;
			if (a[j]>1) (ans+=(LL)f[i][j]*(a[j]-1)%MOD*ny[i]%MOD)%=MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}