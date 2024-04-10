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
vector<ll> val, p, q;
vector<vector<pll>> all;
vector<vector<int>> e;
bool viv = false;

void DFS(int v) {
	q.push_back(v);
	for (auto u : e[v]) {
		if (p[u] == -1) {
			p[u] = v;
			DFS(u);
		}
	}
}

void work(int v) {
	if (p[v] != v)
		all[v] = all[p[v]];
	bool was = false;
	for (auto &p : all[v]) {
		if (p.F == val[v]) {
			p.S++;
			was = true;
		}
	}
	if (!was)
		all[v].push_back({val[v], 1});
	if (viv) {
		cout << v << ": ";
		for (auto p : all[v])
			cout << p.F << ' ' << p.S << endl;
	}
	for (auto &p : all[v]) {
		p.F = __gcd(p.F, val[v]);		
	}
	sort(all[v].begin(), all[v].end());

	for (int i = 1; i < all[v].size(); i++) {
		if (all[v][i].F == all[v][i - 1].F) {
			all[v][i].S += all[v][i - 1].S;
			all[v][i - 1].S = 0;
		}
	}

	vector<pll> help;
	for (auto p : all[v])
		if (p.S)
			help.push_back(p);
	all[v] = help;
}

void solve() {
	cin >> n;
	val.resize(n);
	all.resize(n);
	for (auto &i : val)
		cin >> i;
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	p.resize(n, -1);
	p[0] = 0;
	DFS(0);
	if (viv) {
		for (auto i : p)
			cout << i << ' ';
		cout << endl;
	}
	for (auto &i : q)
		work(i);

	ll ans = 0;
	for (auto vec : all) {
		for (auto p : vec) {
			p.S %= mod;
			p.F %= mod;
			ans += p.S * p.F;
			ans %= mod;
		}
	}
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