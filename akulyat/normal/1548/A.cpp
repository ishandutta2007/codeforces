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

ll n, m;
vector<set<int>> e;
vector<bool> cool;
ll ans = 0;

bool viv = false;

bool is_cool(int v) {
	ans -= cool[v];
	if (e[v].empty()) {
		cool[v] = true;
	} else {
		int z = *e[v].begin();
		cool[v] = (z + v) > 0;
	}
	ans += cool[v];
	return cool[v];
}

void add(int v, int u) {
	e[v].insert(-u);
	e[u].insert(-v);
	is_cool(u);
	is_cool(v);
}

void del(int v, int u) {
	e[v].erase(-u);
	e[u].erase(-v);
	is_cool(u);
	is_cool(v);
}

void get_ans() {
	cout << ans << '\n';
}

void solve() {
	cin >> n >> m;
	e.resize(n);
	cool.resize(n, false);
	ans = 0;
	for (int i = 0; i < n; i++) {
		is_cool(i);
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		add(u, v);
	}

	int q;
	cin >> q;
	while (q--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			add(u, v);
		}
		if (tp == 2) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			del(u, v);
		}
		if (tp == 3) {
			get_ans();
		}
	}
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