#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<vector<int>> e;
vector<int> d, sz;
bool viv = false;

void DFS(int v, int c = 0) {
	d[v] = c;
	sz[v] = 1;
	for (auto u : e[v])
		if (d[u] == -1) {
			DFS(u, c + 1);
			sz[v] += sz[u];
		}
}

bool centroid(int v) {
	vector<int> sz_fr;
	for (auto u : e[v])
		if (d[u] > d[v])
			sz_fr.push_back(sz[u]);
	int all = n;
	for (auto i : sz_fr)
		all -= i;
	all--;
	sz_fr.push_back(all);
	for (auto s : sz_fr)
		if (2 * s > n)
			return false;
	return true;
}

void clean(int u, int v) {
	cout << u + 1 << ' ' << v + 1 << '\n';
}

void solve() {
	cin >> n;
	e.assign(n, {});
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	d.assign(n, -1);
	sz.assign(n, -1);
	DFS(0);
	vector<int> c;
	for (int i = 0; i < n; i++)
		if (centroid(i))
			c.push_back(i);
	if (c.size() == 1) {
		clean(0, e[0][0]);
		clean(0, e[0][0]);
		return;
	}
	int v = c[0];
	int u = c[1];
	
	for (auto t : e[v])
		if (t != u) {
			clean(v, t);
			clean(u, t);
			return;
		}
	assert(false);
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}