#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
struct BIT
{
	int N;
	vector<int> bit;
 
	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}
 
	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}
 
	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}
 
	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
 
	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}
 
	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};
 
int n, q, root = 0;
int level[N], chain[N], idx[N], depth[N];
BIT bit[N], global;
vector<int> g[N];
 
void dfs(int u, int par, int lvl, int ch)
{
	level[u] = lvl;
	chain[u] = ch;
	depth[ch] = max(depth[ch], lvl);
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u, lvl + 1, ch++);
	}
}
 
int32_t main()
{
	IOS;
	cin >> n >> q;
	global.init(n + 1);
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	dfs(1, 1, 0, 1);
	for(int i = 1; i <= n; i++)
	{
		if(depth[i])
			bit[i].init(depth[i]);
	}
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 0)
		{
			int v, x, d;
			cin >> v >> x >> d;
			if(v == 1)
			{
				root += x;
				global.update(1, x);
				global.update(d + 1, -x);
				continue;
			}
			int cNo = chain[v];
			int lvl = level[v];
			int lo = lvl - d;
			int hi = lvl + d;
			if(lo <= 0)
			{
				root += x;
				lvl = abs(lo);
				if(lvl > 0)
				{
					global.update(1, x);
					global.update(lvl + 1, -x);
					bit[cNo].update(1, -x);
					if(lvl + 1 <= depth[cNo])
						bit[cNo].update(lvl + 1, x);
				}
			}
			bit[cNo].update(max(1LL, lo), x);
			if(hi < depth[cNo])
				bit[cNo].update(hi + 1, -x);
		}
		else
		{
			int v;
			cin >> v;
			if(v == 1)
				cout << root << endl;
			else
			{
				int cNo = chain[v];
				int lvl = level[v];
				int ans = global.pref(lvl) + bit[cNo].pref(lvl);
				cout << ans << endl;
			}
		}
	}
	return 0;	
}