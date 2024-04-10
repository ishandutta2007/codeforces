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

bool viv = false;

struct DSU {
	int n = 0;
	vector<int> p, sz;

	DSU() {}
	DSU(int _n) {
		build(_n);
	}

	void build(int _n) {
		n = _n;
		p.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i, sz[i] = 1;
	}

	int pp(int v) {
		if (p[v] == v) return v;
		return p[v] = pp(p[v]);
	}

	bool unit(int u, int v) {
		u = pp(u);
		v = pp(v);
		if (u == v)
			return false;
		if (sz[u] < sz[v]) swap(u, v);
		p[v] = u;
		sz[u] += sz[v];
		return true;
	}
};

int n, m;
vector<vector<pii>> e;
vector<set<int>> fr;
vector<pair<int, pii>> all;
vector<int> unused;
vector<int> comp;
int X = 0;
DSU mst;
DSU mst_pos;

void DFS_f(int v, int c) {
	comp[v] = c;
	vector<int> unused2;
	vector<int> cont;
	for (auto u : unused) {
		if (fr[v].find(u) != fr[v].end())
			unused2.push_back(u);
		else
			if (u != v)
				cont.push_back(u);
	}
	unused = unused2;
	for (auto u : cont) {
		mst.unit(v, u);
		DFS_f(u, c);
	}
}

void solve() {
	cin >> n >> m;
	e.resize(n);
	fr.resize(n);
	X = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
		all.push_back({c, {a, b}});
		fr[a].insert(b);
		fr[b].insert(a);
		X ^= c;
	}
	mst.build(n);
	mst_pos.build(n);

	for (int i = 0; i < n; i++)
		unused.push_back(i);

	comp.resize(n, -1);
	int nxt = 0;
	for (int i = 0; i < n; i++)
		if (comp[i] == -1)
			DFS_f(i, nxt), nxt++;

	if ((n - nxt) + m != (ll)n * (n - 1) / 2)
		X = 0;

	sort(all.begin(), all.end());
	ll ans = 0;
	for (auto pr : all) {
		int w = pr.F;
		int u = pr.S.F;
		int v = pr.S.S;
		if (mst.unit(u, v)) {
			ans += w;
			mst_pos.unit(u, v);
		}
	}
	for (auto pr : all) {
		int w = pr.F;
		int u = pr.S.F;
		int v = pr.S.S;
		if (mst_pos.unit(u, v))
			X = min(X, w);
	}

	ans += X;
	cout << ans << '\n';
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