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

ll n, m, ans;
vector<ll> a, b;
set<pair<ll, pll>> e;
vector<ll> p, sz;
bool viv = false;

ll pp(ll v) {
	if (v == p[v])
		return v;
	return p[v] = pp(p[v]);
}

void unit(ll v, ll u, ll to_add) {
	v = pp(v);
	u = pp(u);
	if (v == u) {
		ans -= to_add;
		return;
	}
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	p[u] = v;
}

void adder() {
	auto mini = *e.begin();
	e.erase(mini);
	unit(mini.S.F, mini.S.S, mini.F);
}

void solve() {
	cin >> m >> n;
	a.resize(m);
	b.resize(n);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;
	for (int i = 0; i < m; i++) {
		ll k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			ll v = i;
			ll u;
			cin >> u; u--;
			e.insert({-(a[v] + b[u]), {v, u + m}});
			// ans += (a[i] + b[u]);
			// cout << ans << endl;
		}
	}
	p.resize(n + m);
	sz.resize(n + m, 1);
	for (int i = 0; i < p.size(); i++)
		p[i] = i;
	while (e.size())
		adder();
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