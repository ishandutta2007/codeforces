#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
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
const int MAXN=200005,MAXK=18;

int n,m,x[MAXN],y[MAXN];
struct Edge
{
	int v,id;
	Edge *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v,int id)
{
	Edge *p=&pool[++etot];
	p->v=v;p->id=id;p->next=h[u];h[u]=p;
}

bool vis[MAXN],itr[MAXN];
int c[MAXN],dep[MAXN],anc[MAXN][MAXK];
void dfs1(int u,int pa)
{
	vis[u]=1;
	for(int i=1;i<MAXK;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	for(Edge *p=h[u];p;p=p->next)
		if(!vis[p->v])
		{
			anc[p->v][0]=u;
			itr[p->id]=1;
			dep[p->v]=dep[u]+1;
			dfs1(p->v,u);
		}
}
void dfs2(int u,int pa)
{
	vis[u]=1;
	for(Edge *p=h[u];p;p=p->next)
		if(p->v!=pa && itr[p->id])
		{
			dfs2(p->v,u);
			c[u]+=c[p->v];
		}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	int t=dep[v]-dep[u];
	for(int i=MAXK-1;i>=0;--i)
		if(t&(1<<i))v=anc[v][i];
	if(u==v)return u;
	for(int i=MAXK-1;i>=0;--i)
		if(anc[u][i]!=anc[v][i])
			u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}
void work(int u,int v)
{
	for(;u!=v;u=anc[u][0])printf("%d ",u);
	printf("%d ",v);
}
void work2(int u,int v)
{
	vector<int> ans;
	swap(u,v);
	for(;u!=v;u=anc[u][0])ans.pb(u);
	ans.pb(v);
	reverse(ans.begin(),ans.end());
	for(auto i:ans)printf("%d ",i);
}
void solve(int i,int j)
{
	printf("YES\n");
	memset(vis,0,sizeof(vis));
	int u1=x[i],v1=y[i],u2=x[j],v2=y[j];
	int u=lca(u1,u2),v=(dep[v1]>dep[v2]?v1:v2);
	printf("%d ",dep[u]-dep[v]+1);
	work(u,v);putchar('\n');
	printf("%d ",dep[u1]-dep[u]+1+dep[v]-dep[v1]+1);
	work2(u,u1);work2(v1,v);putchar('\n');
	printf("%d ",dep[u2]-dep[u]+1+dep[v]-dep[v2]+1);
	work2(u,u2);work2(v2,v);putchar('\n');
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n),readint(m);
	for(int i=1;i<=m;++i)
	{
		readint(x[i]),readint(y[i]);
		addEdge(x[i],y[i],i),addEdge(y[i],x[i],i);
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])dfs1(i,-1);
	for(int i=1;i<=m;++i)
	{
		if(dep[x[i]]<dep[y[i]])swap(x[i],y[i]);
		if(!itr[i])++c[x[i]],--c[y[i]];
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
		if(!vis[i])dfs2(i,-1);
	u=v=0;
	for(int i=1;i<=m;++i)
		if(itr[i] && c[x[i]]>=2){u=x[i],v=y[i];break;}
	if(!u)return 0*printf("NO\n");
	for(int i=1;i<=m;++i)
	{
		if(itr[i])continue;
		if(lca(x[i],u)!=u || lca(y[i],v)!=y[i])continue;
		for(int j=i+1;j<=m;++j)
		{
			if(itr[j])continue;
			if(lca(x[j],u)!=u || lca(y[j],v)!=y[j])continue;
			solve(i,j);
			return 0;
		}
	}
	return 0*printf("NO\n");
}