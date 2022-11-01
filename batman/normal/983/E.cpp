#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)
#define K ((ll)19)

ll n,m,q;
ll strt[N],fnsh[N],_cnt;
ll dis[N],par[K][N],dad[K][N];
vector <ll> e[N],vec[N],seg[4*N];

void pre_dfs(ll x)
{
	strt[x]=_cnt++;
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto u:e[x])
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

void dfs(ll x)
{
	dad[0][x]=x;
	for(auto u:vec[x])
		if(dis[u]<dis[dad[0][x]])
			dad[0][x]=u;
	for(auto u:e[x])
	{
		dfs(u);
		if(dis[dad[0][u]]<dis[dad[0][x]])
			dad[0][x]=dad[0][u];
	}
}

void update2(ll q,ll val,ll xl=0,ll xr=N,ll id=1)
{
	seg[id].push_back(val);
	if(xl==xr-1)return ;
	ll mid=(xl+xr)/2;
	if(q<mid)update2(q,val,xl,mid,id*2);
	else update2(q,val,mid,xr,id*2+1);
}

void build(ll xl=0,ll xr=N,ll id=1)
{
	sort(seg[id].begin(),seg[id].end());
	if(xl==xr-1)return ;
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
}

bool query2(ll ql,ll qr,ll st,ll fn,ll xl=0,ll xr=N,ll id=1)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)
	{
		ll it=lower_bound(seg[id].begin(),seg[id].end(),st)-seg[id].begin();
		if(it!=(ll)seg[id].size() && seg[id][it]<fn)return 1;
		return 0;
	}
	ll mid=(xl+xr)/2;
	return query2(ql,qr,st,fn,xl,mid,id*2)|query2(ql,qr,st,fn,mid,xr,id*2+1);
}

pair <ll,ll> query(ll x,ll y)
{
	ll res=0;
	for(int i=K-1;i>=0;i--)
		if(dis[dad[i][x]]>dis[y])
			res+=(1<<i),
			x=dad[i][x];
	return {x,res};
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		ll p;scanf("%d",&p);
		e[p].push_back(i);
	}
	pre_dfs(1);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		ll v,u,p;
		scanf("%d%d",&v,&u);
		p=lca(v,u);
		vec[v].push_back(p);
		vec[u].push_back(p);
		update2(strt[v],strt[u]);
		update2(strt[u],strt[v]);
	}
	build();
	dfs(1);
	for(int i=1;i<K;i++)
		for(int j=1;j<=n;j++)
			dad[i][j]=dad[i-1][dad[i-1][j]];
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		ll v,u,ans;
		scanf("%d%d",&v,&u);
		ll p=lca(v,u);
		if(dis[v]<dis[u])swap(v,u);
		if(p==u)ans=query(v,u).second+1;
		else
		{
			pair <ll,ll> ex=query(v,p),ex2=query(u,p);
			ans=ex.second+ex2.second+2;
			if(query2(strt[ex.first],fnsh[ex.first],strt[ex2.first],fnsh[ex2.first]))ans--;
		}
		if(ans>N)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}