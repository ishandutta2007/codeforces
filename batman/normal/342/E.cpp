#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll N=101*1000;
const ll K=20;
const ll SQ=300;

ll n,m,ans[N],par[K][N],dis[N],dis2[N];
vector <ll> ver,e[N];

void pre_dfs(ll x)
{
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto v:e[x])
		if(v!=par[0][x])
			dis[v]=dis[x]+1,
			par[0][v]=x,
			pre_dfs(v);
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

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	memset(ans,31,sizeof ans);
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	pre_dfs(1);
	ver.push_back(1);
	while(m--)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll v;
			cin>>v;
			ver.push_back(v);
		}
		if(t==2)
		{
			ll v,res;
			cin>>v;
			res=ans[v];
			for(auto x:ver)
			{
				ll p=lca(x,v);
				res=min(res,dis[x]+dis[v]-2*dis[p]);
			}
			cout<<res<<"\n";
		}
		if((ll)ver.size()>SQ)
		{
			queue <ll> q;
			memset(dis2,31,sizeof dis2);
			for(auto x:ver)q.push(x),dis2[x]=0;
			while(q.size())
			{
				ll x=q.front();q.pop();
				for(auto u:e[x])
					if(dis2[u]>dis2[x]+1)
						dis2[u]=dis2[x]+1,q.push(u);
			}
			for(int i=1;i<=n;i++)ans[i]=min(ans[i],dis2[i]);
			ver.clear();
		}
	}
	return 0;
}