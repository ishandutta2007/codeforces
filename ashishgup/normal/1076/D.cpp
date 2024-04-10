#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;
const int inf=3e14;

int n, m, k, to_remove=0;
int w[N];
int arrival[N], departure[N], deg[N];
pair<int, int> parent[N];
vector<pair<int, int> > g[N], ng[N];
set<int> ans;
vector<int> v;

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
				parent[it.first]={x.second, it.second};
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		ans.insert(parent[i].second);
		deg[parent[i].first]++;
		ng[parent[i].first].push_back({i, parent[i].second});
	}
	int extra=max(0LL, k-(n-1));
	to_remove=max(0LL, n-1-k);
	for(int i=1;i<=m;i++)
	{
		if(!extra)
			break;
		if(ans.find(i)==ans.end())
		{
			ans.insert(i);
			extra--;
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	to_remove=m-k;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v>>w[i];
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	dijkstra(1, 1, arrival, departure);
	queue<int> q;
	for(int i=2;i<=n;i++)
	{
		if(deg[i]==0)
			q.push(i);
	}
	while(q.size() && to_remove>0)
	{
		int cur=q.front();
		q.pop();
		to_remove--;
		ans.erase(parent[cur].second);
		deg[parent[cur].first]--;
		if(parent[cur].first!=1 && deg[parent[cur].first]==0)
			q.push(parent[cur].first);
	}
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it<<" ";
	return 0;
}