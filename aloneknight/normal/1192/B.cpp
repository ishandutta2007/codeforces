#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
const int N=100005;
int n,Q,nn,ps[N],L[N],R[N];ll k,ans,w[N];
vector<pii>g[N];
struct st
{
	ll p,m,tg,lm,mr,lmr;
	inline void upd(ll v){p+=v;m-=2*v;lm-=v;mr-=v;tg+=v;}
	inline st operator+(const st&b)const
	{
		st c;c.p=max(p,b.p);c.m=max(m,b.m);
		c.lm=max(max(lm,b.lm),p+b.m);
		c.mr=max(max(mr,b.mr),m+b.p);
		c.lmr=max(max(lmr,b.lmr),max(lm+b.p,p+b.mr));
		return c;
	}
}T[N<<3];
void upd(int x,int l,int r,int tl,int tr,ll v)
{
	if(r<tl||tr<l)return;if(tl<=l&&r<=tr){T[x].upd(v);return;}
	T[x<<1].upd(T[x].tg);T[x<<1|1].upd(T[x].tg);T[x].tg=0;
	int mid=l+r>>1;upd(x<<1,l,mid,tl,tr,v);upd(x<<1|1,mid+1,r,tl,tr,v);
	T[x]=T[x<<1]+T[x<<1|1];
}
void dfs(int x,int p)
{
	L[x]=++nn;
	for(int i=0;i<g[x].size();i++)if(g[x][i].X!=p){ps[g[x][i].Y]=g[x][i].X;dfs(g[x][i].X,x);nn++;}
	R[x]=nn;
} 
int main()
{
	scanf("%d%d%lld",&n,&Q,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d%lld",&u,&v,&w[i]);
		g[u].pb(mp(v,i));g[v].pb(mp(u,i));
	}
	dfs(1,0);
	for(int i=1;i<n;i++)upd(1,1,2*n,L[ps[i]],R[ps[i]],w[i]);
	while(Q--)
	{
		ll x,v;scanf("%lld%lld",&x,&v);
		x=(x+ans)%(n-1)+1;v=(v+ans)%k;
		upd(1,1,2*n,L[ps[x]],R[ps[x]],v-w[x]);
		w[x]=v;printf("%lld\n",ans=T[1].lmr);
	}
	return 0;
}