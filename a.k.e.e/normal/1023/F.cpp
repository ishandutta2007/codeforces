#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=500005;

int n,k,m;
struct Node
{
	int u,v,id;
	Node *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
void addEdge(int u,int v,int c)
{
	Node *p=&pool[++etot];
	p->v=v;p->id=c;p->next=h[u];h[u]=p;
}

struct Edge
{
	int u,v,c;
}e[MAXN];

int id[MAXN],up[MAXN],pa[MAXN],ans[MAXN],dep[MAXN];
int getup(int u)
	{return up[u]==u?u:up[u]=getup(up[u]);}

void dfs(int u)
{
	for(Node *p=h[u];p;p=p->next)
	{
		if(p->v==pa[u])continue;
		id[p->v]=p->id;
		pa[p->v]=u;
		dep[p->v]=dep[u]+1;
		dfs(p->v);
	}
}

int main()
{
	int u,v,c;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
		up[i]=i;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&u,&v);
		addEdge(u,v,i);
		addEdge(v,u,i);
		u=getup(u);v=getup(v);
		up[u]=v;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
		u=getup(e[i].u);v=getup(e[i].v);
		if(u==v)continue;
		up[u]=v;
		addEdge(e[i].u,e[i].v,0);
		addEdge(e[i].v,e[i].u,0);
		e[i].c=0;
	}
	for(int i=1;i<=n;i++)
		up[i]=i;
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		if(!e[i].c)continue;
		u=e[i].u;v=e[i].v;c=e[i].c;
		u=getup(u);v=getup(v);
		while(u!=v)
		{
			if(dep[u]<dep[v])swap(u,v);
			ans[id[u]]=c;
			up[u]=pa[u];
			u=getup(u);
		}
	}
	ll sum=0;
	for(int i=1;i<=k;i++)
	{
		if(!ans[i])return 0*printf("-1\n");
		sum+=ans[i];
	}
	cout<<sum<<endl;
	return 0;
}