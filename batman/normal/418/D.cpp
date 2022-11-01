#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)20)

ll n,m,par[K][N],dis[N],strt[N],fnsh[N],_cnt,ans[N],r_strt[N];
vector <ll> e[N];
vector <pair<ll,ll> > qu[N];
ll seg[4*N],lazy[4*N];

void pre_dfs(ll x)
{
	r_strt[_cnt]=x;
	strt[x]=_cnt++;
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto u:e[x])
		if(u!=par[0][x])
			par[0][u]=x,
			dis[u]=dis[x]+1,
			pre_dfs(u);
	fnsh[x]=_cnt;
}

ll iPar(ll x,ll num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=par[i][x];
	return x;
}

ll lca(ll x,ll y)
{
	if(dis[x]<dis[y])swap(x,y);
	x=iPar(x,dis[x]-dis[y]);
	if(x==y)return x;
	for(int i=K-1;i>=0;i--)
		if(par[i][x]!=par[i][y])
			x=par[i][x],y=par[i][y];
	return par[0][x];
}

void shift(ll id)
{
	lazy[id*2]+=lazy[id];
	seg[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	seg[id*2+1]+=lazy[id];
	lazy[id]=0;
}

void build(ll xl=0,ll xr=n,ll id=1)
{
	if(xl==xr-1)
	{
		seg[id]=dis[r_strt[xl]];
		return ;
	}
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}

void update(ll ql,ll qr,ll val,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id]+=val;
		lazy[id]+=val;
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(id);
	update(ql,qr,val,xl,mid,id*2);
	update(ql,qr,val,mid,xr,id*2+1);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}

ll query(ll ql,ll qr,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	shift(id);
	return max(query(ql,qr,xl,mid,id*2),query(ql,qr,mid,xr,id*2+1));
}

void dfs(ll x)
{
	for(auto u:qu[x])
	{
		if(u.second<0)ans[-u.second]=max(ans[-u.second],max(query(0,strt[u.first]),query(fnsh[u.first],n)));
		else ans[u.second]=max(ans[u.second],query(strt[u.first],fnsh[u.first]));
	}
	for(auto u:e[x])
		if(u!=par[0][x])
		{
			update(0,n,1);
			update(strt[u],fnsh[u],-2);
			dfs(u);
			update(0,n,-1);
			update(strt[u],fnsh[u],+2);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	pre_dfs(1);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		ll v,u;
		cin>>v>>u;
		ll p=lca(v,u);
		if(dis[v]<dis[u])swap(v,u);
		ll len=dis[v]+dis[u]-2*dis[p];
		if(dis[v]==dis[u])qu[v].push_back({iPar(u,(dis[u]-dis[p])-(len/2-(dis[v]-dis[p]))-1),-i});
		else qu[v].push_back({iPar(v,len/2),i});
		qu[u].push_back({iPar(v,(dis[v]-dis[p])-(len/2-(dis[u]-dis[p]))-1),-i});
	}
	build();
	dfs(1);
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}