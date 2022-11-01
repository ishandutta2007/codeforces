#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,m,cnt,last[N],ls[N],top,stack[N],tot,a[N],dep[N],fa[N][20],val[N],tim,dfn[N],low[N],f[N];
bool vis[N],flag;
struct edge{int to,next,w;}e[N*4];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void add(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=ls[u];ls[u]=cnt;
}

void work(int rt)
{
	flag=0;
	for (int i=1;i<=tot;i++)
	{
		int x=e[a[i]].to;
		for (int j=ls[x];j;j=e[j].next)
			if (x!=rt&&dep[x]==dep[e[j].to]) flag=1;
		x=e[a[i]^1].to;
		for (int j=ls[x];j;j=e[j].next)
			if (x!=rt&&dep[x]==dep[e[j].to]) flag=1;
	}
	if (flag)
	{
		for (int i=1;i<=tot;i++)
			e[a[i]].w=e[a[i]^1].w=1;
	}
}

void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tim;dep[x]=dep[fa]^1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		if (!dfn[e[i].to])
		{
			stack[++top]=i;
			tarjan(e[i].to,x);
			low[x]=std::min(low[x],low[e[i].to]);
			if (low[e[i].to]>=dfn[x])
			{
				int y=0;tot=0;
				while (y!=i)
				{
					y=stack[top];top--;
					a[++tot]=y;
				}
				work(x);
			}
		}
		else
		{
			low[x]=std::min(low[x],dfn[e[i].to]);
			if (dfn[e[i].to]<dfn[x]) add(x,e[i].to);
		}
	}
}

void pre(int x)
{
	vis[x]=1;
	dep[x]=dep[fa[x][0]]+1;
	for (int i=1;i<=16;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=last[x];i;i=e[i].next)
		if (!vis[e[i].to])
		{
			fa[e[i].to][0]=x;
			val[e[i].to]=val[x]+e[i].w;
			pre(e[i].to);
		}
}

int get_lca(int x,int y)
{
	if (dep[x]<dep[y]) std::swap(x,y);
	for (int i=16;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=16;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int main()
{
	scanf("%d%d",&n,&m);cnt=1;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
		if (find(x)!=find(y)) f[find(x)]=find(y);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i,0);
	for (int i=1;i<=n;i++) if (!vis[i]) pre(i);
	int q;scanf("%d",&q);
	while (q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		int lca=get_lca(x,y);
		if (find(x)!=find(y)) puts("No");
		else if ((dep[x]&1)!=(dep[y]&1)) puts("Yes");
		else if (val[x]+val[y]-val[lca]*2) puts("Yes");
		else puts("No");
	}
	return 0;
}