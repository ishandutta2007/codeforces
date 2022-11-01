#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)
#define K ((ll)1001*1000)
#define INF ((ll)2e9)

ll n,k,dis[N],max_id;
vector <ll> e[N];
vector <pair<ll,ll> > res;

void add(ll x,ll y)
{
	e[x].push_back(y);
	e[y].push_back(x);
	res.push_back({min(x,y),max(x,y)});
}

void dfs(ll x,ll par=0)
{
	if(dis[x]>dis[max_id])max_id=x;
	for(auto u:e[x])
		if(u!=par)
			dis[u]=dis[x]+1,
			dfs(u,x);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=2;i<=k+1;i++)add(1,i);
	for(int i=k+2;i<=n;i++)add(i,i-k);
	dfs(1);
	dis[max_id]=0;
	dfs(max_id);
	cout<<dis[max_id]<<"\n";
	for(auto u:res)cout<<u.first<<" "<<u.second<<"\n";
	return 0;
}