#include <bits/stdc++.h>
using namespace std;
const int MAXN=505050;
struct Edge{
	int y, next;
	long long l;
}edge[MAXN<<1];
struct Node{
	int x,y;
	long long w;
}a[MAXN];
int n,k,m,tot;
int top[MAXN],deep[MAXN],fa[MAXN],f[MAXN],size[MAXN],mson[MAXN],son[MAXN];
long long val[MAXN];
inline void add(int x,int y,long long l)
{
	edge[++tot].y = y; edge[tot].l = l;
	edge[tot].next = son[x]; son[x] = tot;
}

int getf(int u)
{
	if(u == f[u])return u;
	return f[u] = getf(f[u]);
}

void dfs(int x)
{
	size[x] = 1;
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(y == fa[x])continue;
		fa[y] = x;
		deep[y] = deep[x] + 1;
		val[y] = edge[i].l;
		dfs(y);
		size[x] += size[y];
		if(size[y] > size[mson[x]])mson[x] = y;
	}
}

void dfs(int x, int y)
{
	top[x] = y;
	if(mson[x])dfs(mson[x], y);
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(y == fa[x] || y == mson[x])continue;
		dfs(y, y);
	}
}

int lca(int u, int v)
{
	while(top[u] != top[v])
	{
		if(deep[top[u]] < deep[top[v]])swap(u, v);
		u = fa[top[u]];
	}
	if(deep[u] > deep[v])swap(u, v);
	return u;
}

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<= n; i++)
		f[i]=i;
	for(int i=1;i<=k;i++)
	{
		int x, y;
		scanf("%d%d",&x, &y);
		int u = getf(x), v = getf(y);
		if(u < v)swap(u, v);
		f[u] = v;
		add(x, y, 1e18);
		add(y,x,1e18);
	}
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%I64d", &a[i].x, &a[i].y, &a[i].w);
		int u = getf(a[i].x), v = getf(a[i].y);
		if(u == v)continue;
		f[u] = v;
		add(a[i].x,a[i].y,a[i].w);
		add(a[i].y,a[i].x,a[i].w);
		a[i].w=0;
	}
	dfs(1);
	dfs(1,1);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int Lca=lca(a[i].x,a[i].y);
		int u=getf(a[i].x);
		while(deep[u]>deep[Lca])
		{
			val[u]=min(val[u],a[i].w);
			f[u]=getf(fa[u]);
			u=getf(u);
		}
		u=getf(a[i].y);
		while(deep[u]>deep[Lca])
		{
			val[u]=min(val[u],a[i].w);
			f[u]=getf(fa[u]);
			u=getf(u);
		}
	}
	long long ans=0;
	for(int i=2;i<=n;i++)
	if(val[i]==1e18)
	{
		puts("-1");
		return 0;
	}
	else
		ans+=val[i];
	printf("%I64d\n",ans);
	return 0;
}