#include<bits/stdc++.h>

typedef long long LL;

const int N=3605;
const int MOD=998244353;

int n,m,k,jc[N],ny[N],f[N][N],g[N][N];
bool vis1[N],vis2[N];

int C(int n,int m)
{
	if (n<m) return 0;
	else return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=std::max(n,m);i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=std::max(n,m);i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	int ret1=n,ret2=m;
	for (int i=1;i<=k;i++)
	{
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		vis1[x1]=vis1[x2]=vis2[y1]=vis2[y2]=1;
		ret1-=2;ret2-=2;
		if (x1==x2) ret1++;
		else ret2++;
	}
	f[1][0]=f[0][0]=1;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=i/2;j++)
		{
			f[i][j]=f[i-1][j];
			if (j&&!vis1[i]&&!vis1[i-1]) (f[i][j]+=f[i-2][j-1])%=MOD;
		}
	g[1][0]=g[0][0]=1;
	for (int i=2;i<=m;i++)
		for (int j=0;j<=i/2;j++)
		{
			g[i][j]=g[i-1][j];
			if (j&&!vis2[i]&&!vis2[i-1]) (g[i][j]+=g[i-2][j-1])%=MOD;
		}
	int ans=0;
	for (int i=0;i<=n/2;i++)
		for (int j=0;j<=m/2;j++)
			(ans+=(LL)f[n][i]*g[m][j]%MOD*C(ret1-i*2,j)%MOD*jc[j]%MOD*C(ret2-j*2,i)%MOD*jc[i]%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}