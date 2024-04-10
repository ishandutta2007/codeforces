#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
#define INF ((ll)1e14)
ll n,m,last[N],d[N];
vector <pair <ll,ll> > e[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
		
	}
	
	for(int i=2;i<=n;i++)
		d[i]=INF;
	last[1]=-1;	
	set <pair<ll,ll> > st;
	st.insert({d[1],1});
	while(st.size())
	{
		ll v=st.begin()->second;
		st.erase({d[v],v});
		for(int i=0;i<e[v].size();i++)
			if(d[e[v][i].first]>d[v]+e[v][i].second)
			{
				st.erase({d[e[v][i].first],e[v][i].first});
				d[e[v][i].first]=d[v]+e[v][i].second;
				last[e[v][i].first]=v;
				st.insert({d[e[v][i].first],e[v][i].first});
			}
	}
	if(d[n]==INF)
		return cout<<-1,0;
	ll x=n;
	vector <ll> ans;
	while(x!=-1)
		ans.push_back(x),x=last[x];
	for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i]<<" ";		
    return 0;
}