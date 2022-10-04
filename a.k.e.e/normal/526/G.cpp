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
const int MAXN=200005,MAXK=17;

int n;
struct Edge
{
	int v,c;
	Edge *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v,int c)
{
	Edge *p=&pool[++etot];
	p->v=v;p->c=c;p->next=h[u];h[u]=p;
}

int dis[MAXN];
void dfs_dia(int u,int pa)
{
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		dis[p->v]=dis[u]+p->c;
		dfs_dia(p->v,u);
	}
}
void get_dia(int &u,int &v)
{
	u=v=0;
	dis[1]=0;dfs_dia(1,-1);
	u=1;for(int i=2;i<=n;++i)if(dis[i]>dis[u])u=i;
	dis[u]=0;dfs_dia(u,-1);
	v=1;for(int i=2;i<=n;++i)if(dis[i]>dis[v])v=i;
}

struct Worker
{
	int m,a[MAXN],rt,tim[MAXN],ans[MAXN];
	int dis[MAXN],dfn[MAXN],size[MAXN],dfn_cnt,maxd[MAXN],dedfn[MAXN],pac[MAXN];
	int anc[MAXN][MAXK],dep[MAXN];
	pii sum[MAXN<<2|1];
	int lazy[MAXN<<2|1];
	int Min[MAXN<<2|1];
	
	void dfs(int u,int pa)
	{
		for(int i=1;i<MAXK;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
		dfn[u]=++dfn_cnt;
		dedfn[dfn_cnt]=u;
		size[u]=1;
		for(Edge *p=h[u];p;p=p->next)
		{
			if(p->v==pa)continue;
			dis[p->v]=dis[u]+p->c;
			pac[p->v]=p->c;
			anc[p->v][0]=u;
			dep[p->v]=dep[u]+1;
			dfs(p->v,u);
			size[u]+=size[p->v];
			chkmax(maxd[u],maxd[p->v]+p->c);
		}
	}
	int lca(int u,int v)const
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
	
	void build(int id,int l,int r)
	{
		if(l==r){sum[id]=mp(dis[dedfn[l]],dedfn[l]);return;}
		int mid=(l+r)>>1;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		sum[id]=max(sum[id<<1],sum[id<<1|1]);
	}
	inline void pushdown(int id)
	{
		if(!lazy[id])return;
		lazy[id<<1]+=lazy[id];sum[id<<1].x+=lazy[id];
		lazy[id<<1|1]+=lazy[id];sum[id<<1|1].x+=lazy[id];
		lazy[id]=0;
	}
	void modify(int id,int l,int r,int ql,int qr,int c)
	{
		if(l==ql && r==qr){lazy[id]+=c;sum[id].x+=c;return;}
		pushdown(id); 
		int mid=(l+r)>>1;
		if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
		else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
		else modify(id<<1,l,mid,ql,mid,c),modify(id<<1|1,mid+1,r,mid+1,qr,c);
		sum[id]=max(sum[id<<1],sum[id<<1|1]);
	}
	
	void get(int id,int l,int r)
	{
		if(l==r)
		{
			int u=dedfn[(l-1)%n+1];
			if(size[u]==1)Min[id]=tim[u];
			else Min[id]=1<<30;
			return;
		}
		int mid=(l+r)>>1;
		get(id<<1,l,mid);
		get(id<<1|1,mid+1,r);
		Min[id]=min(Min[id<<1],Min[id<<1|1]);
	}
	int qleft(int id,int l,int r,int ql,int qr,int c)
	{
		if(Min[id]>c)return 2*n+1;
		if(l==r)return l;
		int mid=(l+r)>>1;
		if(qr<=mid)return qleft(id<<1,l,mid,ql,qr,c);
		if(ql>mid)return qleft(id<<1|1,mid+1,r,ql,qr,c);
		int t=qleft(id<<1,l,mid,ql,mid,c);
		return t<=2*n?t:qleft(id<<1|1,mid+1,r,mid+1,qr,c);
	}
	int qright(int id,int l,int r,int ql,int qr,int c)
	{
		if(Min[id]>c)return 0;
		if(l==r)return l;
		int mid=(l+r)>>1;
		if(qr<=mid)return qright(id<<1,l,mid,ql,qr,c);
		if(ql>mid)return qright(id<<1|1,mid+1,r,ql,qr,c);
		int t=qright(id<<1|1,mid+1,r,mid+1,qr,c);
		return t?t:qright(id<<1,l,mid,ql,mid,c);
	}
	
	void init()
	{
		dfs(rt,-1);
		build(1,1,n);
		int cnt=n-1;
		while(cnt)
		{
			int u=sum[1].y;
			a[++m]=u;
			ans[m]=ans[m-1];
			for(;u!=rt && !tim[u];u=anc[u][0])
			{
				ans[m]+=pac[u];
				modify(1,1,n,dfn[u],dfn[u]+size[u]-1,-pac[u]);
				tim[u]=m;
				--cnt;
			}
		}
		get(1,1,2*n);
	}
	int adjca(int x,int y)
	{
		int u=qright(1,1,2*n,1,n+dfn[x]-1,y),v=qleft(1,1,2*n,dfn[x]+1,2*n,y);
		u=dedfn[(u-1)%n+1],v=dedfn[(v-1)%n+1];
		int du=lca(u,x),dv=lca(v,x);
		if(dep[du]<dep[dv])return v;
		return u;
	}
	ll solve(int x,int y)
	{
		chkmin(y,m);
		if(tim[x]<=y)return ans[y];
		if(y==1)return dis[x]+maxd[x];
		int u=adjca(x,y),d=lca(u,x);
		int res=ans[y]+dis[x]-dis[u]+maxd[x];
		u=adjca(x,y-1),d=lca(u,x);
		chkmax(res,ans[y-1]+dis[x]-dis[d]+maxd[x]);
		return res;
	}
}w1,w2;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	#endif
	int Q,u,v,c,x,y,lastans=0;
	readint(n);readint(Q);
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v),readint(c);
		addEdge(u,v,c),addEdge(v,u,c);
	}
	get_dia(u,v);
	w1.rt=u;w1.init();
	w2.rt=v;w2.init();
	while(Q--)
	{
		readint(x),readint(y);
		x=(x+lastans-1)%n+1,y=(y+lastans-1)%n+1;
		printf("%d\n",lastans=max(w1.solve(x,2*y-1),w2.solve(x,2*y-1)));
	}
	return 0;
}