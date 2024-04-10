#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
vector<vector<int> > g;

vector<int> Centroid(const vector<vector<int>> &g) 
{
	int n = g.size();
	vector<int> centroid;
	vector<int> sz(n);
	function<void (int, int)> dfs = [&](int u, int prev) 
	{
		sz[u] = 1;
		bool is_centroid = true;
		for (auto v : g[u]) if (v != prev) {
				dfs(v, u);
				sz[u] += sz[v];
				if (sz[v] > n / 2) is_centroid = false;
		}
		if (n - sz[u] > n / 2) is_centroid = false;
		if (is_centroid) centroid.push_back(u);
	};
	dfs(0, -1);
	return centroid;
}

int stu, stv;
pair<int, int> p;

void dfs(int u, int par)
{
	int leaf = 1;
	for(auto &it:g[u])
	{
		if(it == par || it == stv)
			continue;
		leaf = 0;
		dfs(it, u);
	}
	if(leaf)
		p = {u, par};
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		g = vector<vector<int> > (n);
		for(int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			stu = u, stv = v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> v = Centroid(g);
		if(v.size() == 1)
		{
			cout << stu + 1 << " " << stv + 1 << endl;
			cout << stu + 1 << " " << stv + 1 << endl;
		}
		else
		{
			stu = v[0], stv = v[1];
			dfs(stu, stu);
			cout << p.first + 1 << " " << p.second + 1 << endl;
			cout << p.first + 1 << " " << stv + 1 << endl;
		}
	}
	return 0;
}