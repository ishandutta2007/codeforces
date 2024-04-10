#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
bool isLeaf[N];
vector<int> g[N];

int dfs(int u, int par)
{
	isLeaf[u] = 1;
	int ct = 0, ctLeaves = 0, val = 0;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		isLeaf[u] = 0;
		val += dfs(it, u);
		if(isLeaf[it])
			ctLeaves++;
		else
			ct++;
	}
	ctLeaves = min(ctLeaves, 1LL);
	return val + ctLeaves + ct;
}

int have[N][2];
int flag = 0;

void dfs2(int u, int par)
{
	if(isLeaf[u])
		have[u][0] = 1;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs2(it, u);
		have[u][0] |= have[it][1];
		have[u][1] |= have[it][0];
	}
	if(have[u][0] && have[u][1])
		flag = 1;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	int mn, mx;
	for(int i = 1; i <= n; i++)
	{
		if(g[i].size() > 1)
		{
			mx = dfs(i, i);
			dfs2(i, i);
			mn = 1;
			if(flag)
				mn += 2;
			break;
		}
	}
	cout << mn << " " << mx;
	return 0;
}