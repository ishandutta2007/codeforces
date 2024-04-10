#include <iostream>
#include <cstdio>
#include <cmath>

const int maxn=107;

using namespace std;

int T,n,m,x;
int ls[maxn],f[maxn][maxn],g[maxn][maxn];
int nf[maxn][maxn][2],ng[maxn][maxn][3];

struct edge{
	int y,next;
}e[maxn];

void dfs(int x)
{
	f[x][1]=g[x][1]=0;
	for (int i=ls[x];i>0;i=e[i].next)
	{
		int y=e[i].y;
		dfs(y);
		for (int j=m;j>0;j--)
		{
			for (int k=j-1;k>0;k--)
			{
				if (f[x][k]+f[y][j-k]+2<f[x][j])
				{
					f[x][j]=f[x][k]+f[y][j-k]+2;
					nf[x][j][0]=y;
					nf[x][j][1]=j-k;
				}
				if (f[x][k]+g[y][j-k]+1<g[x][j])
				{
					g[x][j]=f[x][k]+g[y][j-k]+1;
					ng[x][j][0]=y;
					ng[x][j][1]=j-k;
					ng[x][j][2]=1;
				}
				if (g[x][k]+f[y][j-k]+2<g[x][j])
				{
					g[x][j]=g[x][k]+f[y][j-k]+2;
					ng[x][j][0]=y;
					ng[x][j][1]=j-k;
					ng[x][j][2]=0;
				}
			}
		}
	}
}

void solve(int n,int m,int op)
{
	if ((!op) || (!ng[n][m][2])) printf("%d ",n);
	if (m==1) return;
	if (!op)
	{
		solve(nf[n][m][0],nf[n][m][1],0);
		solve(n,m-nf[n][m][1],0);
	}
	else
	{
		if (!ng[n][m][2])
		{
			solve(ng[n][m][0],ng[n][m][1],0);
			solve(n,m-ng[n][m][1],1);
		}
		else
		{
			solve(n,m-ng[n][m][1],0);
			solve(ng[n][m][0],ng[n][m][1],1);
		}
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) ls[i]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				f[i][j]=g[i][j]=0x3f3f3f3f;
				nf[i][j][0]=nf[i][j][1]=0;
				ng[i][j][0]=ng[i][j][1]=ng[i][j][2]=0;
			}
		}
		for (int i=2;i<=n;i++)
		{
			scanf("%d",&x);
			e[i].y=i;
			e[i].next=ls[x];
			ls[x]=i;
		}
		
		dfs(1);
		printf("%d\n",g[1][m]);
		solve(1,m,1);
		printf("\n");
	}
}