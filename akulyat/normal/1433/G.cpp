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

ll n, m, q;
ll ans;
vector<vector<pll>> e;
vector<pll> c;
vector<vector<ll>> d;
bool viv = false;

void D(ll v) {
	set<pll> st;
	vector<ll> dist(n, mod);
	dist[v] = 0;
	for (int i = 0; i < n; i++)
		st.insert({dist[i], i});
	while (st.size()) {
		auto pr = *st.begin();
		st.erase(st.begin());
		int u = pr.S;
		for (auto p : e[u]) {
			int s = p.F;
			if (dist[u] + p.S < dist[s]) {
				st.erase({dist[s], s});
				dist[s] = dist[u] + p.S;
				st.insert({dist[s], s});
			}
		}
	}
	d.push_back(dist);
}

void counter() {
	for (int i = 0; i < n; i++)
		D(i);
}

void work(int v, int u) {
	ll res = 0;
	for (auto p : c) {
		ll d1 = d[p.F][p.S];
		ll d2 = d[p.F][v] + d[p.S][u];
		ll d3 = d[p.F][u] + d[p.S][v];
		res += min(d1, min(d2, d3));
	}
	ans = min(res, ans);
}

void solve() {
	cin >> n >> m >> q;
	e.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		c.push_back({a, b});
	}
	counter();

	ans = inf;
	for (int i = 0; i < n; i++) {
		for (auto p : e[i]) {
			int u = p.F;
			work(i, u);
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