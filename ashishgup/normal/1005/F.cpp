#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, reqd, ct=1;
int arrival[N], departure[N], vis[N], ans[N], vis2[N];
vector<pair<int, int> > g[N];
set<pair<int, int> > parent[N], son[N];
vector<string> answer;

void dijkstra(int source, int destination)
{
	for(int i=1;i<=n;i++)
	{
		arrival[i]=1e18;
		departure[i]=1e18;
	}
	arrival[source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + 1)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + 1;
				s.insert({arrival[it.first], it.first});
				parent[it.first].clear();
				parent[it.first].insert({x.second, it.second});
			}
			else if(arrival[it.first] == departure[x.second] + it.second)
			{
				parent[it.first].insert({x.second, it.second});
			}
		}
	}
}

void dfs(int k, int ans[])
{
	if(k==n+1)
	{
		string cur="";
		for(int i=1;i<=m;i++)
			cur+=(char)(ans[i]+'0');
		answer.push_back(cur);
		reqd--;
		if(reqd==0)
		{
			cout<<answer.size()<<endl;
			for(auto it:answer)
				cout<<it<<endl;
			exit(0);
		}
	}
	for(auto it:parent[k])
	{
		ans[it.second]=1;
		dfs(k+1, ans);
		ans[it.second]=0;
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>reqd;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	dijkstra(1, n);
	for(int i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			if(departure[it.first]<departure[i])
				parent[i].insert({it.first, it.second});
		}
	}
	dfs(2, ans);
	cout<<answer.size()<<endl;
	for(auto it:answer)
		cout<<it<<endl;
	return 0;
}