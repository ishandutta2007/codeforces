#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long 

const int N = 2e5 + 5;

int n, k, store;
int level[N], ans[N];
vector<int> g[N];
int curt = 0;
int subtree[N], subtreeMin[N];
int tin[N], tout[N];

void predfs(int u, int par, int lvl)
{
	level[u] = lvl;
	subtree[u] = 1;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		predfs(it, u, lvl + 1);
		subtree[u] += subtree[it];
	}
}

bool dfs(int u, int par, int x)
{
	bool ans = 1;
	int cnt = 0;
	subtreeMin[u] = u;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		ans &= dfs(it, u, x);
		subtreeMin[u] = min(subtreeMin[u], subtreeMin[it]);
		cnt += subtreeMin[it] <= x;
	}
	ans &= (cnt <= 1);
	return ans;
}

bool check(int x)
{
	vector<pair<int, int> > v; // {depth, node} to find one endpoint of the [0 - x] path
	for(int i = 0; i <= x; i++)
		v.push_back({level[i], i});
	sort(v.begin(), v.end());
	int node = v.back().second;
	store = node;
	return dfs(node, node, x);
}

int binary_search(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		if(check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	check(lo);
	return lo;
}

int parent[N];

void newdfs(int u, int par, int lvl)
{
	subtree[u] = 1;
	subtreeMin[u] = u;
	tin[u] = ++curt;
	level[u] = lvl;
	parent[u] = par;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		newdfs(it, u, lvl + 1);
		subtree[u] += subtree[it];
		subtreeMin[u] = min(subtreeMin[u], subtreeMin[it]);
	}
	tout[u] = curt;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		curt = 0;
		cin >> n;
		for(int i = 0; i <= n + 1; i++)
		{
			ans[i] = 0;
			g[i].clear();
		}
		for(int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		predfs(0, 0, 0);
		ans[0] = n * (n - 1) / 2;
		int val = 0, sum = 0, ct = 0;
		for(auto &it:g[0])
		{
			sum += subtree[it] * subtree[it];
			val += subtree[it];
		}
		ans[1] = (val * val - sum) / 2 + val;
		int x = binary_search(1, n - 1);
		newdfs(store, store, 0);
		set<pair<int, int> > s;
		s.insert({level[0], 0});
		for(int i = 1; i <= x; i++)
		{
			s.insert({level[i], i});
			int u = s.begin() -> second;
			int v = (--s.end()) -> second;
			if(level[u] > level[v])
				swap(u, v);
			int sz1 = subtree[v];
			int sz2 = n;
			for(auto &it:g[u])
			{
				if(subtreeMin[it] <= i)
				{
					if(it == parent[u])
						continue;
					sz2 -= subtree[it];
				}
			}
			ans[i + 1] = sz1 * sz2;
		}
		for(int i = 0; i <= n - 1; i++)
			ans[i] -= ans[i + 1];
		for(int i = 0; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}