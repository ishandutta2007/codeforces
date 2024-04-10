#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

ll n,m,par[N];
pair <pair<ll,ll>,ll> shoe[N];
vector <ll> e[N];
bool mark[N];

bool dfs(ll x)
{
	mark[x]=1;
	for(auto u:e[x])
	{
		if(par[u]==-1)return par[u]=x,1;
		if(!mark[par[u]] && dfs(par[u]))return par[u]=x,1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>shoe[i].first.second>>shoe[i].first.first,shoe[i].second=i;
	sort(shoe,shoe+n);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		ll money,sz;
		cin>>money>>sz;
		pair <pair<ll,ll>,ll> ex;ex={{sz,-1},-1};
		ll id=lower_bound(shoe,shoe+n,ex)-shoe;
		if(shoe[id].first.first==sz && shoe[id].first.second<=money)e[shoe[id].second].push_back(i+1);
		ex={{sz+1,-1},-1};id=lower_bound(shoe,shoe+n,ex)-shoe;
		if(shoe[id].first.first==sz+1 && shoe[id].first.second<=money)e[shoe[id].second].push_back(i+1);
	}
	for(int i=0;i<n;i++)swap(shoe[i].first.first,shoe[i].first.second),shoe[i].first.first*=-1;
	sort(shoe,shoe+n);memset(par,-1,sizeof par);
	ll ans=0;
	for(int i=0;i<n;i++)
		memset(mark,0,sizeof mark),ans+=dfs(shoe[i].second)*shoe[i].first.first*-1;
	cout<<ans<<"\n";
	vector <pair<ll,ll> > res;
	for(int i=1;i<=m;i++)if(par[i]!=-1)res.push_back({i,par[i]+1});
	cout<<res.size()<<"\n";for(auto u:res)cout<<u.first<<" "<<u.second<<"\n";
    return 0;
}