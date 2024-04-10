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
vector<vector<int>> e;
vector<pair<ll, vector<int>>> s;
bool viv = false;

ll ans = 0;

void del(int v) {
	ans -= s[v].F * s[v].S.size();
}
void add(int v) {
	ans += s[v].F * s[v].S.size();
}

void up(int v, int u, int all = false) {
	del(v);
	if (all)
		s[v].F--;
	s[v].S.push_back(u);
	add(v);
}

void down(int v, int u, int all = false) {
	del(v);
	if (all)
		s[v].S.clear();
	s[v].F++;
	add(v);
}

void work() {
	int v;
	cin >> v;
	v--;
	vector<int> upf;
	for (auto u : s[v].S)
		upf.push_back(u);
	for (auto u : upf) {
		down(v, u, true);
		up(u, v, true);
	}
	cout << ans << '\n';
}

void solve() {
	cin >> n >> m;
	e.resize(n);
	s.resize(n);
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		e[v].push_back(u);
		e[u].push_back(v);
		if (v > u)
			swap(v, u);
		up(v, u);
		down(u, v);
	}
	cout << ans << '\n';

	cin >> q;
	while (q--)
		work();
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