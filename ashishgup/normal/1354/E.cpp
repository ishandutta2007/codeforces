#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5005;

int n, m, n1, n2, n3, sz;
int c0, c1;
bool vis[N];
int col[N], answer[N];
vector<int> g[N];
vector<vector<int> > c0s, c1s;
vector<int> cur0, cur1;
vector<pair<int, int> > v;

void dfs(int u, int c)
{
	if(vis[u])
	{
		if(col[u] != c)
		{
			cout << "NO";
			exit(0);
		}
		return;
	}
	vis[u] = 1;
	col[u] = c;
	if(c == 0)
	{
		c0++;
		cur0.push_back(u);
	}
	else
	{
		c1++;
		cur1.push_back(u);
	}
	for(auto &it:g[u])
		dfs(it, c ^ 1);
}

int cache[N][N];

int dp(int idx, int c2, int other)
{
	if(c2 < 0)
		return 0;
	if(other < 0)
		return 0;
	if(idx == sz)
		return 1;
	int &ans = cache[idx][c2];
	if(ans != -1)
		return ans;
	ans = 0;
	ans = dp(idx + 1, c2 - v[idx].first, other - v[idx].second);
	if(!ans)
		ans = dp(idx + 1, c2 - v[idx].second, other - v[idx].first);
	return ans;
}


void path(int idx, int c2, int other)
{
	if(idx == sz)
		return;
	int &ans = cache[idx][c2];
	if(dp(idx + 1, c2 - v[idx].first, other - v[idx].second))
	{
		for(auto &it:c0s[idx])
			answer[it] = 2;
		for(auto &it:c1s[idx])
		{
			if(n1 > 0)
				answer[it] = 1, n1--;
			else
				answer[it] = 3, n3--;
		}
		return path(idx + 1, c2 - v[idx].first, other - v[idx].second);
	}
	else
	{
		for(auto &it:c1s[idx])
			answer[it] = 2;
		for(auto &it:c0s[idx])
		{
			if(n1 > 0)
				answer[it] = 1, n1--;
			else
				answer[it] = 3, n3--;
		}
		return path(idx + 1, c2 - v[idx].second, other - v[idx].first);
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	cin >> n1 >> n2 >> n3;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i])
			continue;
		c0 = 0, c1 = 0;
		cur0.clear();
		cur1.clear();
		dfs(i, 0);
		c0s.push_back(cur0);
		c1s.push_back(cur1);
		v.push_back({c0, c1});
	}
	sz = v.size();
	if(!dp(0, n2, n1 + n3))
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		path(0, n2, n1 + n3);
		for(int i = 1; i <= n; i++)
			cout << answer[i];
	}
	return 0;
}