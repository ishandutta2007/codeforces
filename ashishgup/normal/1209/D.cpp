#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k, cnt = 0;
int x[N], y[N], vis[N];
vector<int> g[N];

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u] = 1;
	cnt++;
	for(auto &it:g[u])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> x[i] >> y[i];
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			cnt = 0;
			dfs(i);
			ans += cnt - 1;
		}
	}
	cout << max(0LL, k - ans);
	return 0;
}