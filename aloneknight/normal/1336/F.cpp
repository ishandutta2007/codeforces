#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define db long double
#define mp make_pair
#define X first
#define Y second
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<(a).size();++i)
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
#define gc getchar
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=150005;
int n,m,K,tt,dep[N],sz[N],hs[N],dl[N],dr[N],fa[N][19],rt[N];
ll ans;vi e[N],V[N];vector<pii>p[N];
struct BIT
{
	int c[N];
	inline void upd(int x,int v){for(;x<=n;x+=x&-x)c[x]+=v;}
	inline void upd(int l,int r,int v){upd(l,v);upd(r+1,-v);}
	inline int qry(int x){int s=0;for(;x;x-=x&-x)s+=c[x];return s;}
}B;
struct seg
{
	int tt;
	struct st{int l,r,s;}T[N*40];
	void ins(int&x,int l,int r,int p)
	{
		if(!x){x=++tt;T[x]=(st){0,0,0};}T[x].s++;if(l==r)return;
		int m=l+r>>1;p<=m?ins(T[x].l,l,m,p):ins(T[x].r,m+1,r,p);
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x|y;
		T[x].l=merge(T[x].l,T[y].l);
		T[x].r=merge(T[x].r,T[y].r);
		T[x].s+=T[y].s;return x;
	}
	int qry(int x,int l,int r,int tl,int tr)
	{
		if(!x)return 0;if(tl<=l&&r<=tr)return T[x].s;int m=l+r>>1;
		return (tl<=m?qry(T[x].l,l,m,tl,tr):0)+(tr>m?qry(T[x].r,m+1,r,tl,tr):0);
	}
}T;
void dfs1(int x,int p)
{
	sz[x]=1;dep[x]=dep[p]+1;fa[x][0]=p;rep(i,1,18)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int y:e[x])if(y!=fa[x][0]){dfs1(y,x);sz[x]+=sz[y];hs[x]=sz[y]>sz[hs[x]]?y:hs[x];}
}
void dfs2(int x)
{
	dl[x]=++tt;
	for(int y:e[x])if(y!=fa[x][0]&&y!=hs[x])dfs2(y);
	if(hs[x])dfs2(hs[x]);dr[x]=tt;
}
inline int anc(int x,int d){per(i,18,0)if(d>>i&1)x=fa[x][i];return x;}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);u=anc(u,dep[u]-dep[v]);if(u==v)return u;
	per(i,18,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];return fa[u][0];
}
void dfs3(int x,int o)
{
	rt[x]=0;int w=max(0,K-(dep[x]-dep[o]));
	for(int y:V[x])
	{
		if(dep[y]>=dep[o]+w){int z=anc(y,dep[y]-dep[o]-w);ans+=T.qry(rt[x],1,n,dl[z],dr[z]);}
		T.ins(rt[x],1,n,dl[y]);
	}
	for(int y:e[x])if(y!=fa[x][0]&&(y!=hs[x]||x!=o))
	{
		dfs3(y,o);if(V[y].size()>V[x].size())V[x].swap(V[y]),swap(rt[x],rt[y]);
		for(int z:V[y])if(dep[z]>=dep[o]+w){int t=anc(z,dep[z]-dep[o]-w);ans+=T.qry(rt[x],1,n,dl[t],dr[t]);}
		for(int z:V[y])V[x].pb(z);V[y].clear();rt[x]=T.merge(rt[x],rt[y]);
	}
}
void dfs(int x)
{
	for(int y:e[x])if(y!=fa[x][0])dfs(y);
	fore(i,p[x])ans+=B.qry(dl[p[x][i].Y]);
	fore(i,p[x])
	{
		int y=p[x][i].Y;if(dep[y]<dep[x]+K)continue;
		int t=anc(y,dep[y]-dep[x]-K);B.upd(dl[t],dr[t],1);
	}
	fore(i,p[x])ans+=B.qry(dl[p[x][i].X]);
	fore(i,p[x])
	{
		int y=p[x][i].X;if(dep[y]<dep[x]+K)continue;
		int t=anc(y,dep[y]-dep[x]-K);B.upd(dl[t],dr[t],1);
	}
	fore(i,p[x])V[p[x][i].X].pb(p[x][i].Y);
	dfs3(x,x);V[x].clear();T.tt=0;
}
int main()
{
	n=rd();m=rd();K=rd();
	rep0(i,1,n){int u=rd(),v=rd();e[u].pb(v);e[v].pb(u);}
	dfs1(1,0);dfs2(1);
	rep(i,1,m)
	{
		int u=rd(),v=rd(),t=lca(u,v);
		if(dl[u]>dl[v])swap(u,v);p[t].pb(mp(u,v));
	}
	dfs(1);printf("%lld\n",ans);return 0;
}