#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200005*2;
int n,m,q;
struct qq{int x,y,last;}e[N];
int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int belong[N],cnt;
int dfn[N],low[N],id;
int sta[N],top;
void dfs (int x,int fa)
{
/*	printf("YES:%d %d\n",x,fa);
	system("pause");*/
	low[x]=dfn[x]=++id;sta[++top]=x;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (u==fa) continue;
		if (dfn[y]==-1)
		{
			dfs(y,u^1);
			low[x]=min(low[x],low[y]);
		}
		else low[x]=min(low[x],dfn[y]);
	}
	if (low[x]==dfn[x])
	{
		cnt++;int i;
		do
		{
			i=sta[top--];
			belong[i]=cnt;
		}while (i!=x);
	}
}
int f[N][21];
int dep[N];
void dfs1 (int x,int fa)
{
	f[x][0]=fa;
	for (int u=1;u<=20;u++)	f[x][u]=f[f[x][u-1]][u-1];
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dep[y]=dep[x]+1;
		dfs1(y,x);
	}
}
int get (int x,int y)
{
	if (dep[x]>dep[y]) swap(x,y);
	for (int u=20;u>=0;u--)
		if (dep[f[y][u]]>=dep[x]) 
			y=f[y][u];
	if (x==y) return x;
	for (int u=20;u>=0;u--)
		if (f[y][u]!=f[x][u])
		{
			x=f[x][u];y=f[y][u];
		}
	return f[x][0];
}
int c[N],c1[N];//    
bool tf=true;
void solve (int x,int fa)
{
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		solve(y,x);
		c[x]+=c[y];
		c1[x]+=c1[y];
	}
	if (c[x]*c1[x]!=0) tf=false;
}
int main()
{
	memset(dfn,-1,sizeof(dfn));
	num=1;memset(last,-1,sizeof(last));
	scanf("%d%d%d",&n,&m,&q);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	for (int u=1;u<=n;u++)
	{
		if (dfn[u]==-1)
			dfs(u,0);
	}
	num=0;memset(last,-1,sizeof(last));
	for (int u=2;u<=m*2+1;u+=2)
	{
		int x=e[u].x,y=e[u].y;
		if (belong[x]!=belong[y])	
		{
		//	printf("%d %d\n",belong[x],belong[y]);
			init(belong[x],belong[y]);
			init(belong[y],belong[x]);
		}
	}
	for (int u=1;u<=cnt;u++)
	{
		if (dep[u]==0)
		{
			dep[u]=1;
			dfs1(u,0);
		}
	}
	for (int u=1;u<=q;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=belong[x];y=belong[y];
		if (x==y) continue;
		int lca=get(x,y);
		if (lca==0) {printf("No\n");return 0;}// 
		c[x]++;c1[y]++;
		c[lca]--;c1[lca]--;
	}
	solve(belong[1],0);
	if (tf) printf("Yes\n");
	else printf("No\n");
	return 0;
}