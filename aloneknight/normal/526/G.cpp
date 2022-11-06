#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=100005;
int n,Q,cc,tt,mxv,rt,res,hd[N],fa[N][20],dep[N],md[N],dfn[N],dl[N],dr[N],vis[N],ans[N],tg[N*4];pii mx[N*4];
struct E{int v,nxt,w;}e[N*2];
inline void add(int u,int v,int w){e[++cc]=(E){v,hd[u],w};hd[u]=cc;}
inline void up(int x){mx[x]=max(mx[x<<1],mx[x<<1|1]);}
inline void cov(int x,int v){mx[x].X+=v;tg[x]+=v;}
inline void dn(int x){if(!tg[x])return;cov(x<<1,tg[x]);cov(x<<1|1,tg[x]);tg[x]=0;}
void build(int x,int l,int r)
{
	if(l==r){mx[x]=mp(dep[dfn[l]],dfn[l]);return;}
	int m=l+r>>1;build(ls);build(rs);up(x);
}
void upd(int x,int l,int r,int tl,int tr,int v)
{
	if(tl<=l&&r<=tr){cov(x,v);return;}int m=l+r>>1;dn(x);
	if(tl<=m)upd(ls,tl,tr,v);if(tr>m)upd(rs,tl,tr,v);up(x);
}
void gtrt(int x,int p,int d)
{
	if(d>mxv)mxv=d,rt=x;
	for(int i=hd[x],y;i;i=e[i].nxt)if((y=e[i].v)!=p)gtrt(y,x,d+e[i].w);
}
void pre(int x,int p)
{
	fa[x][0]=p;dfn[++tt]=x;dl[x]=tt;md[x]=dep[x];
	rep(i,1,18)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=hd[x],y;i;i=e[i].nxt)if((y=e[i].v)!=p){dep[y]=dep[x]+e[i].w;pre(y,x);md[x]=max(md[x],md[y]);}
	dr[x]=tt;
}
void calc(int o)
{
	pre(o,0);build(1,1,n);
	rep(i,2,n)
	{
		ans[i]=ans[i-1]+mx[1].X;
		for(int x=mx[1].Y;x&&!vis[x];x=fa[x][0])vis[x]=i,upd(1,1,n,dl[x],dr[x],dep[fa[x][0]]-dep[x]);
	}
}
int sol(int x,int y)
{
	if(vis[x]<=y)return ans[y];
	int t=x;per(i,18,0)if(vis[fa[t][i]]>y)t=fa[t][i];t=fa[t][0];
	return ans[y]+md[x]-dep[t]-min(dep[t],min(ans[y]-ans[y-1],md[t]-dep[t]));
}
int main()
{
	n=rd();Q=rd();
	rep(i,1,n-1){int u=rd(),v=rd(),w=rd();add(u,v,w);add(v,u,w);}
	mxv=0;gtrt(1,0,0);calc(rt);
	while(Q--)
	{
		int x=(rd()+res-1)%n+1,v=(rd()+res-1)%n+1;
		printf("%d\n",res=sol(x,min(v*2,n)));
	}
	return 0;
}