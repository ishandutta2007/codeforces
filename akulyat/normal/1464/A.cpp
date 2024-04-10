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
vector<pll> v;
vector<vector<int>> e;
vector<int> d;
bool viv = false;

void DFS(int v, int c) {
	d[v] = c;
	for (auto u : e[v])
		if (d[u] == -1)
			DFS(u, c);
}

void solve() {
	cin >> n >> m;
	v.clear();
	e.clear();
	d.clear();

	v.resize(m);
	e.resize(n);
	for (auto &p : v) {
		cin >> p.F >> p.S, p.F--, p.S--;
		e[p.F].push_back(p.S);
		e[p.S].push_back(p.F);
	}
	int c = 0;
	d.resize(n, -1);
	for (int i = 0; i < n; i++) 
		if (d[i] == -1)
			DFS(i, c), c++;
	vector<ll> cnt_v(c), cnt_e(c);
	for (auto i : d)
		cnt_v[i]++;
	for (auto p : v)
		cnt_e[d[p.F]]++;
	ll ans = m;	
	for (int i = 0; i < c; i++) {
		if (cnt_v[i] == cnt_e[i] && cnt_v[i] > 1)
			ans++;
	}
	for (auto p : v)
		ans -= (p.F == p.S);
	cout << ans << '\n';
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