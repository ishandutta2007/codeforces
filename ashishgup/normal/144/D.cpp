#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int inf=1e9;

int n, m, s, l, ans=0;
int arrival[N], departure[N], w[N];
vector<pair<int, int> > g[N];

void dijkstra(int source, int destination, int arrival[], int departure[])
{
	for(int i=1;i<=n;i++)
	{
		arrival[i]=inf;
		departure[i]=inf;
	}
	arrival[source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + w[it.second])
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + w[it.second];
				s.insert({arrival[it.first], it.first});
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v>>w[i];
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}	
	cin>>l;
	dijkstra(s, s, arrival, departure);
	for(int i=1;i<=n;i++)
		ans+=(arrival[i]==l);
	set<pair<int, int> > s;
	for(int i=1;i<=n;i++)
	{
		for(auto &it:g[i])
		{
			if(arrival[i]<l && arrival[i]+w[it.second]>l && arrival[it.first] + w[it.second] - (l - arrival[i]) >= l)
			{
				if(i<it.first)
					s.insert({it.second, l-arrival[i]});
				else
					s.insert({it.second, w[it.second]-(l-arrival[i])});
			}
		}
	}
	ans+=s.size();
	cout<<ans;
	return 0;
}