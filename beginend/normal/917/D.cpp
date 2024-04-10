#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=105;
const int MOD=1000000007;

int n,size[N],cnt,last[N],jc[N],ny[N],f[N][N][N],g[N],tmp[N][N];
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

void mod(int &x) {x-=x>=MOD?MOD:0;}

int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

void dp(int x,int fa)
{
	size[x]=1;f[x][1][1]=1;
	for (int i=last[x],to=e[i].to;i;i=e[i].next,to=e[i].to)
	{
		if (to==fa) continue;
		dp(to,x);
		for (int j=1;j<=size[x];j++)
			for (int k=1;k<=size[x];k++)
			{
				if (!f[x][j][k]) continue;
				for (int j1=1;j1<=size[to];j1++)
					for (int k1=1;k1<=size[to];k1++)
					{
						mod(tmp[j+j1][k]+=(LL)f[x][j][k]*f[to][j1][k1]%MOD*k1%MOD);
						mod(tmp[j+j1-1][k+k1]+=(LL)f[x][j][k]*f[to][j1][k1]%MOD);
					}
			}
		size[x]+=size[to];
		for (int j=1;j<=size[x];j++)
			for (int k=1;k<=size[x];k++)
				f[x][j][k]=tmp[j][k],tmp[j][k]=0;
	}
}

int main()
{
	scanf("%d",&n);
	jc[0]=ny[0]=jc[1]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dp(1,0);
	g[n-1]=1;
	for (int i=0;i<n-1;i++)
	{
		for (int j=1;j<=n;j++)
			mod(g[i]+=(LL)f[1][n-i][j]*j%MOD);
		if (n-i-2>=0) g[i]=(LL)g[i]*ksm(n,n-i-2)%MOD;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
			if ((j-i)&1) mod(g[i]+=MOD-(LL)g[j]*C(j,i)%MOD);
			else mod(g[i]+=(LL)g[j]*C(j,i)%MOD);
		printf("%d ",g[i]);
	}
	return 0;
}