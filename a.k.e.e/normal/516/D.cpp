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
const int MAXN=100005,MAXK=17;

int n,rt;
struct Edge
{
	int v;
	ll c;
	Edge *next;
}pool[MAXN<<2|1],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v,ll c)
{
	Edge *p=&pool[++etot];
	p->v=v;p->c=c;p->next=h[u];h[u]=p;
}

ll f[MAXN],g[MAXN],dis[MAXN],anc[MAXN][MAXK];
int c[MAXN];
void dfs1(int u,int pa)
{
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		dis[p->v]=dis[u]+p->c;
		dfs1(p->v,u);
		chkmax(f[u],f[p->v]+p->c);
	}
}
void dfs2(int u,int pa)
{
	ll maxf=0,secf=0;
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		if(f[p->v]+p->c>maxf)secf=maxf,maxf=f[p->v]+p->c;
		else if(f[p->v]+p->c>secf)secf=f[p->v]+p->c;
	}
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		g[p->v]=max(g[u],f[p->v]+p->c==maxf?secf:maxf)+p->c;
		dfs2(p->v,u);
	}
}
void dfs3(int u,int pa)
{
	for(int i=1;i<MAXK;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		anc[p->v][0]=u;
		dfs3(p->v,u);
	}
}
void dfs4(int u,int pa)
{
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		dfs4(p->v,u);
		c[u]+=c[p->v];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int Q,u,v;
	ll w;
	readint(n);
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v),readint(w);
		addEdge(u,v,w),addEdge(v,u,w);
	}
	
	dfs1(1,-1);
	dfs2(1,-1);
	rt=1;
	for(int i=1;i<=n;++i)
	{
		chkmax(f[i],g[i]);
		if(f[i]<f[rt])rt=i;
	}
	dfs3(rt,-1);
	
	readint(Q);
	while(Q--)
	{
		memset(c,0,sizeof(c));
		readint(w);
		for(int i=1;i<=n;++i)
		{
			u=i;
			for(int j=MAXK-1;j>=0;--j)
				if(anc[u][j] && f[i]-f[anc[u][j]]<=w)
					u=anc[u][j];
			++c[i];
			--c[anc[u][0]];
		}
		dfs4(rt,-1);
		int ans=0;
		for(int i=1;i<=n;++i)chkmax(ans,c[i]);
		printf("%d\n",ans);
	}
	return 0;
}