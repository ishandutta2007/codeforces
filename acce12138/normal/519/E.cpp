#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=100005;
int f[maxn][20],depth[maxn],n,m,low[maxn],cnt[maxn];
vector<int> g[maxn];
void dfs(int x,int fa,int deep)
{
	f[x][0]=fa;
	depth[x]=deep;
	cnt[x]=1;
	for(int i=0;i<g[x].size();i++)
		if(g[x][i]!=fa)
		{
			dfs(g[x][i],x,deep+1);
			cnt[x]+=cnt[g[x][i]];
		}
}
int up(int x,int y)
{
	for(int i=0;i<20;i++)
		if((y>>i)&1)
			x=f[x][i];
	return x;
}
int LCA(int x,int y)
{
	int z=depth[x]-depth[y];
	x=up(x,z);
	if(x==y)
		return x;
	for(int i=19;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
void Q1(int x,int y)
{
	if((depth[x]-depth[y])&1)
	{
		puts("0");
		return;
	}
	int z=(depth[x]-depth[y]>>1)-1;
	x=up(x,z);
	printf("%d\n",cnt[f[x][0]]-cnt[x]);
}
void Q2(int x,int y,int lca)
{
	if(depth[x]==depth[y])
	{
		int z=depth[x]-depth[lca]-1;
		x=up(x,z);
		y=up(y,z);
		printf("%d\n",n-cnt[x]-cnt[y]);
		return;
	}
	if((depth[x]+depth[y]-depth[lca]*2)&1)
	{
		puts("0");
		return;
	}
	int zz=(depth[x]+depth[y]-depth[lca]*2)/2-1;
	x=up(x,zz);
	printf("%d\n",cnt[f[x][0]]-cnt[x]);
}
int main()
{
	scanf("%d",&n);
	int x,y,z;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=2;i<n;++i)
		low[i]=low[i>>1]+1;
	dfs(1,0,0);
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			printf("%d\n",n);
			continue;
		}
		if(depth[x]<depth[y])
			swap(x,y);
		z=LCA(x,y);
		if(y==z)
			Q1(x,y);
		else
			Q2(x,y,z);
	}
	return 0;
}