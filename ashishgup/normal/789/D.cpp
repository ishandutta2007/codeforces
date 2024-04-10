#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e6 + 5;
 
int n, m, self = 0;
bool vis[N], check[N];
vector<int> g[N];
 
void dfs(int u)
{	
	if(vis[u])
		return;
	vis[u] = 1;
	for(auto &it:g[u])
		dfs(it);
}
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if(u == v)
		{
			check[u] = 1;
			self++;
		}
		else
		{
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	m -= self;
	for(int i = 1; i <= n; i++)
	{
		if(g[i].size() || check[i])
		{
			dfs(i);
			break;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i] && (g[i].size() || check[i]))
		{
			cout << 0;
			return 0;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int sz = g[i].size() + check[i];
		ans += sz * (sz - 1) / 2;
	}
	ans += self * (self - 1) / 2;
	ans += self * m;
	for(int i = 1; i <= n; i++)
	{
		if(check[i])
		{
			int sz = g[i].size();
			ans -= sz;
		}
	}
	cout << ans;
	return 0;
}