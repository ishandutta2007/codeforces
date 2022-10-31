#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)20)
#define INF ((ll)2e9)

ll n,m;
bool block[N];
vector <pair<ll,ll> > e[N];
pair <ll,ll> dp_down[N],dp_up[N];

ll par[K][N],dis[N];
ll prt[N],ans,cnt;

void pre_dfs(ll x)
{
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto u:e[x])
		if(u.first!=par[0][x])
			dis[u.first]=dis[x]+1,
			par[0][u.first]=x,
			pre_dfs(u.first);
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

void dfs_down(ll x,ll par=0)
{
	dp_down[x]={-INF,x};
	if(block[x])dp_down[x].first=0;
	for(auto u:e[x])
		if(u.first!=par)
		{
			dfs_down(u.first,x);
			if(dp_down[u.first].first+u.second>dp_down[x].first)
				dp_down[x]=dp_down[u.first],dp_down[x].first+=u.second;
			else if(dp_down[u.first].first+u.second==dp_down[x].first)
				dp_down[x].second=x;
		}
}

void dfs_up(ll x,ll par=0)
{
	if(block[x] && dp_up[x].first<0)dp_up[x]={0,x};
	vector <pair<ll,ll> > ex;
	ex.push_back({dp_up[x].first,0});
	for(auto u:e[x])
		if(u.first!=par)
			ex.push_back({dp_down[u.first].first+u.second,u.first});
	sort(ex.begin(),ex.end());
	ll num=ex.size();
	for(auto u:e[x])
		if(u.first!=par)
		{
			pair<ll,ll> p=ex[num-1],q=ex[num-2];
			if(p.second==u.first)p=q,q=ex[num-3];
			else if(q.second==u.first && num>=3)q=ex[num-3];
			
			dp_up[u.first].first=p.first+u.second;
			if(p.second==0)dp_up[u.first].second=dp_up[x].second;
			else dp_up[u.first].second=dp_down[p.second].second;
			if(num>2 && p.first==q.first)
				dp_up[u.first].second=x;
			dfs_up(u.first,x);
		}
}

void dfs(ll x)
{
	for(auto u:e[x])
		if(u.first!=par[0][x])
			dfs(u.first),prt[x]+=prt[u.first];
	if(!block[x])
	{
		if(prt[x]>ans)ans=prt[x],cnt=1;
		else if(prt[x]==ans)cnt++;
	}
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	ll x;
    	cin>>x;
    	block[x]=1;
	}
	for(int i=0;i<n-1;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	pre_dfs(1);
	dfs_down(1);
	dp_up[1]={-INF,1};
	dfs_up(1);
	for(int i=1;i<=n;i++)
	{
		if(!block[i])continue;
		ll x;
		if(dp_up[i].first>dp_down[i].first)x=dp_up[i].second;
		else if(dp_up[i].first<dp_down[i].first)x=dp_down[i].second;
		else x=i;
		ll p=lca(x,i);
		prt[x]++;prt[i]++;
		prt[par[0][p]]--;prt[p]--;
	}
	dfs(1);
	cout<<ans<<" "<<cnt<<"\n";
    return 0;
}