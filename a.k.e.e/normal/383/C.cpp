#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN=200005;
int n,a[MAXN];
struct Node
{
	int v;
	Node *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v)
{
	Node *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p;
}

int pa[MAXN],dep[MAXN],dfn[MAXN],son[MAXN],size[MAXN],top[MAXN],dfn_cnt;
void dfs1(int u)
{
	size[u]=1;
	for(Node *p=h[u];p;p=p->next)
	{
		if(p->v==pa[u])continue;
		dep[p->v]=dep[u]+1;
		pa[p->v]=u;
		dfs1(p->v);
		size[u]+=size[p->v];
		if(size[p->v]>size[son[u]])son[u]=p->v;
	}
}
void dfs2(int u)
{
	dfn[u]=++dfn_cnt;
	if(son[u])
	{
		top[son[u]]=top[u];
		dfs2(son[u]);
	}
	for(Node *p=h[u];p;p=p->next)
	{
		if(p->v==pa[u] || p->v==son[u])continue;
		top[p->v]=p->v;
		dfs2(p->v);
	}
}

int c[MAXN];
void modify(int u,int d)
{
	for(int i=u;i<=n;i+=(i&(-i)))
		c[i]+=d;
}
int query(int u)
{
	int ans=0;
	for(int i=u;i;i-=(i&(-i)))
		ans+=c[i];
	return ans;
}
int qlist(int u)
{
	int ans=0;
	for(;u;u=pa[top[u]])
		ans+=query(dfn[u])-query(dfn[top[u]]-1);
	return ans;
}

int main()
{
	int Q,op,u,v;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addEdge(u,v);addEdge(v,u);
	}
	top[1]=1;
	dfs1(1);
	dfs2(1);
	while(Q--)
	{
		scanf("%d%d",&op,&u);
		if(op==1)
		{
			scanf("%d",&v);
			if(dep[u]&1)modify(dfn[u],-v);
			else modify(dfn[u],v);
		}
		else
		{
			if(dep[u]&1)printf("%d\n",a[u]-qlist(u));
			else printf("%d\n",a[u]+qlist(u));
		}
	}
	return 0;
}