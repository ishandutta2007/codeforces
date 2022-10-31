#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,m,c[N],sz[N],cnt[N],fen[N],ans[N];
vector <ll> e[N];
vector <pair<ll,ll> > q[N];
bool big[N];

void update(ll x,ll num){for(;x<N;x+=x&-x)fen[x]+=num;}
ll query(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}

void pre_dfs(ll x,ll par=0)
{
	sz[x]=1;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			pre_dfs(e[x][i],x),sz[x]+=sz[e[x][i]];
}

void add(ll x,ll par,ll num)
{
	if(cnt[c[x]])
		update(cnt[c[x]],-1);
	cnt[c[x]]+=num;
	if(cnt[c[x]])
		update(cnt[c[x]],1);
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par && !big[e[x][i]])
			add(e[x][i],x,num);
}

void dfs(ll x,ll par=0,bool mark=0)
{
	ll big_child=0;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par && sz[e[x][i]]>sz[big_child])
			big_child=e[x][i];
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par && e[x][i]!=big_child)
			dfs(e[x][i],x);
	if(big_child)dfs(big_child,x,1);
	big[big_child]=1;
	add(x,par,1);
	
	for(int i=0;i<q[x].size();i++)
		ans[q[x][i].second]=query(N-1)-query(q[x][i].first-1);
	
	big[big_child]=0;
	if(!mark)add(x,par,-1);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=0;i<m;i++)
	{
		ll v,k;
		cin>>v>>k;
		q[v].push_back({k,i});
	}
	pre_dfs(1);
	dfs(1);
	for(int i=0;i<m;i++)cout<<ans[i]<<"\n";
	return 0;
}