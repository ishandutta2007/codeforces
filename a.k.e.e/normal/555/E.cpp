#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
//#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005,MAXK=19;
 
int n,m;
struct Edge
{
	int v,id;
	Edge *next;
}pool[MAXN<<2|1],*h[MAXN],*g[MAXN];
int etot=0;
inline void addEdge(Edge *h[],int u,int v,int id)
{
	Edge *p=&pool[++etot];
	p->v=v;p->id=id;p->next=h[u];h[u]=p;
}

int iden[MAXN],dfn[MAXN],low[MAXN],sta[MAXN],top,dfn_cnt,bcc[MAXN];
bool vis[MAXN];
void tarjan(int u,int pa,int id)
{
	iden[u]=id;
	dfn[u]=low[u]=++dfn_cnt;
	sta[++top]=u;
	for(Edge *p=h[u];p;p=p->next)
		if(!dfn[p->v])
		{
			vis[p->id]=1;
			tarjan(p->v,u,id);
			chkmin(low[u],low[p->v]);
		}
		else if(!vis[p->id])
			chkmin(low[u],dfn[p->v]);
	if(low[u]==dfn[u])
	{
		++m;
		do
		{
			u=sta[top--];
			bcc[u]=m;
		}while(low[u]!=dfn[u]);
	}
}

int anc[MAXN][MAXK],c[2][MAXN],dep[MAXN];
void dfs1(int u)
{
	vis[u]=1;
	for(int i=1;i<MAXK;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	for(Edge *p=g[u];p;p=p->next)
	{
		if(p->v==anc[u][0])continue;
		dep[p->v]=dep[u]+1;
		anc[p->v][0]=u;
		dfs1(p->v);
	}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	int t=dep[v]-dep[u];
	for(int i=0;i<MAXK;++i)
		if(t&(1<<i))v=anc[v][i];
	if(u==v)return u;
	for(int i=MAXK-1;i>=0;--i)
		if(anc[u][i]!=anc[v][i])
			u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}
void dfs2(int u)
{
	vis[u]=1;
	for(Edge *p=g[u];p;p=p->next)
	{
		if(p->v==anc[u][0])continue;
		dfs2(p->v);
		c[0][u]+=c[0][p->v];
		c[1][u]+=c[1][p->v];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	#endif
	int E,Q,u,v;
	readint(n);readint(E);readint(Q);
	for(int i=1;i<=E;++i)
	{
		readint(u);readint(v);
		addEdge(h,u,v,i);addEdge(h,v,u,i);
	}
	for(int i=1;i<=n;++i)
	{
		if(iden[i])continue;
		tarjan(i,-1,i);
	}
	for(int i=1;i<=n;++i)
		for(Edge *p=h[i];p;p=p->next)
			if(bcc[i]!=bcc[p->v])addEdge(g,bcc[i],bcc[p->v],0);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;++i)
		if(!vis[i])dfs1(i);
	while(Q--)
	{
		readint(u);readint(v);
		if(iden[u]!=iden[v])return 0*printf("No\n");
		u=bcc[u],v=bcc[v];
		int d=lca(u,v);
		++c[0][u];--c[0][d];
		++c[1][v];--c[1][d];
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;++i)
		if(!vis[i])dfs2(i);
	for(int i=2;i<=m;++i)
		if(c[0][i] && c[1][i])
			return 0*printf("No\n");
	return 0*printf("Yes\n");
}