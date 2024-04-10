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
vector<ll> l, r, d, ansl, ansr;
bool viv = false;

void DFS(int v, int c) {
	d[v] = c;
	for (auto u : e[v])
		if (d[u] == -1)
			DFS(u, c + 1);
	for (auto u : e[v]) {
		if (d[u] > d[v]) {
			ll add = max(abs(l[v] - r[u]) + ansr[u], abs(l[v] - l[u]) + ansl[u]);
			ansl[v] += add;
		}
		if (d[u] > d[v]) {
			ll add = max(abs(r[v] - r[u]) + ansr[u], abs(r[v] - l[u]) + ansl[u]);
			ansr[v] += add;
		}
	}
}

void solve() {
	cin >> n;
	e.assign(n, {});
	l.resize(n);
	r.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	ansl.assign(n, 0);
	ansr.assign(n, 0);
	d.assign(n, -1);
	DFS(0, 0);
	ll ans = max(ansl[0], ansr[0]);
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