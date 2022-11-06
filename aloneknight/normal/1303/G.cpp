#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<ll,int>
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
inline int rd()
{
	int x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=150005;
const ll inf=150000000100ll,INF=1e18;
int n,S,Rt,tt,rt,nn,w[N],mx[N],sz[N],a[N],vis[N],ls[N*60],rs[N*60];ll ans,k[N*60],b[N*60];vi g[N];
void gtsz(int x,int p)
{
	sz[x]=1;
	for(int y:g[x])if(!vis[y]&&y!=p){gtsz(y,x);sz[x]+=sz[y];}
}
void gtrt(int x,int p)
{
	sz[x]=1;mx[x]=0;
	for(int y:g[x])if(!vis[y]&&y!=p){gtrt(y,x);sz[x]+=sz[y];mx[x]=max(mx[x],sz[y]);}
	mx[x]=max(mx[x],S-sz[x]);if(mx[x]<mx[Rt])Rt=x;
}
void upd(int&x,ll l,ll r,ll K,ll B)
{
	if(!x){x=++nn;ls[x]=rs[x]=0;k[x]=K;b[x]=B;return;}
	ll m=l+r>>1;
	if(K*m+B>k[x]*m+b[x])swap(k[x],K),swap(b[x],B);
	if(l==r)return;
	if(K<=k[x])upd(ls[x],l,m,K,B);else upd(rs[x],m+1,r,K,B);
}
ll qry(int x,ll l,ll r,ll p)
{
	if(!x)return -INF;if(l==r)return k[x]*p+b[x];ll m=l+r>>1;
	return max(p<=m?qry(ls[x],l,m,p):qry(rs[x],m+1,r,p),k[x]*p+b[x]);
}
void dfs1(int x,int p,int d,ll v,ll s)
{
	d++;v+=w[x];s+=v;int ff=1;
	for(int y:g[x])if(!vis[y]&&y!=p)dfs1(y,x,d,v,s),ff=0;
	if(ff)upd(rt,0,inf,d,s);
}
void dfs2(int x,int p,int d,ll v,ll s)
{
	d++;v+=w[x];s+=1ll*d*w[x];int ff=1;
	for(int y:g[x])if(!vis[y]&&y!=p)dfs2(y,x,d,v,s),ff=0;
	if(ff)ans=max(ans,qry(rt,0,inf,v)+s);
}
void sol(int x)
{
	vis[x]=1;gtsz(x,0);
	tt=0;for(int y:g[x])if(!vis[y])a[++tt]=y;
	rt=0;nn=0;upd(rt,0,inf,1,w[x]);
	rep(i,1,tt)dfs2(a[i],x,0,0,0),dfs1(a[i],x,1,w[x],w[x]);
	ans=max(ans,qry(rt,0,inf,0));rt=nn=0;
	per(i,tt,1)dfs2(a[i],x,0,0,0),dfs1(a[i],x,1,w[x],w[x]);
	for(int y:g[x])if(!vis[y]){S=sz[y];Rt=0;gtrt(y,x);sol(Rt);}
}
int main()
{
	n=rd();
	rep(i,1,n-1){int u=rd(),v=rd();g[u].pb(v);g[v].pb(u);}
	rep(i,1,n)w[i]=rd();
	mx[0]=n;S=n;Rt=0;gtrt(1,0);sol(Rt);
	printf("%lld\n",ans);return 0;
}