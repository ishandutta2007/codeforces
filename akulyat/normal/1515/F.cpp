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

ll n, m, x;
vector<ll> sz;
bool viv = false;


struct DSU {
	int n;
	vector<int> p;
	void build(int _n) {
		n = _n;
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	int pp(int v) {
		if (p[v] == v)
			return v;
		return p[v] = pp(p[v]);
	}

	bool uni(int v, int u) {
		v = pp(v);
		u = pp(u);
		if (u == v)
			return false;

		p[v] = u;
		sz[u] += sz[v];
		sz[u] -= x;
		return true;
	}

} dsu;


void solve() {
	cin >> n >> m >> x;
	sz.resize(n);
	for (auto &i : sz)
		cin >> i;
	dsu.build(n);
	vector<pll> all;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		all.push_back({u, v});
	}

	vector<int> ans;
	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < m; i++) {
			int u = all[i].F;
			int v = all[i].S;
			int pu = dsu.pp(u);
			int pv = dsu.pp(v);
			if (pu != pv && sz[pu] + sz[pv] >= x) {
				ans.push_back(i);
				dsu.uni(u, v);
			}
		}
		for (int i = m - 1; i >= 0; i--) {
			int u = all[i].F;
			int v = all[i].S;
			int pu = dsu.pp(u);
			int pv = dsu.pp(v);
			if (pu != pv && sz[pu] + sz[pv] >= x) {
				ans.push_back(i);
				dsu.uni(u, v);
			}
		}
	}
	if (ans.size() != n - 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (auto i : ans)
		cout << i + 1 << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}