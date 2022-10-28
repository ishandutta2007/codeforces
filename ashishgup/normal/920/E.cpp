#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m, sz = 0;
set<int> unvisited;
set<int> g[N];
vector<int> v;

void dfs(int u)
{
	sz++;
	unvisited.erase(u);
	vector<int> next;
	for(auto &it:unvisited)
	{
		if(g[u].find(it) == g[u].end())
			next.push_back(it);
	}
	for(auto &it:next)
		unvisited.erase(it);
	for(auto &it:next)
		dfs(it);
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		unvisited.insert(i);
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i = 1; i <= n; i++)
	{	
		if(unvisited.find(i) != unvisited.end())
		{
			sz = 0;
			dfs(i);
			v.push_back(sz);
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for(auto &it:v)
		cout << it << " ";
	return 0;
}