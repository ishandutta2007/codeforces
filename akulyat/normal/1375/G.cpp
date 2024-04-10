#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef int     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, k;
vector<ll> col;
vector<vector<ll>> e;
bool viv = false;

ll DFS(ll v, bool c) {
	col[v] = c;
	ll res = !c;
	for (auto s : e[v])
		if (col[s] == -1)
			res += DFS(s, !c);
	return res;
}

pll far(ll v) {
	col.clear();
	col.resize(n, -1);
	DFS(v, 0);
	ll dist = -1;
	for (int i = 0; i < n; i++)
		dist = max(dist, col[i]);
	for (int i = 0; i < n; i++)
		if (col[i] == dist)
			return {i, dist};
	assert(false);
}

ll ran(ll mod) {
	ll res = 0;
	for (int i = 0; i < 5; i++) {
		ll a = rand() % kk;
		ll b = rand() % kk;
		res *= a;
		res += b;
		res %= mod;
	}
	return res;
}

ll get(ll v) {
	for (int i = 0; i < n; i++)
		col[i] = -1;
	return DFS(v, 0) - 1;
}

void solve() {
	cin >> n;
	e.resize(n);
	for (int i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	ll ans = n;
	col.resize(n, -1);
	for (int i = 0; i < 1; i++) {
		ll v = ran(n);
		ans = min(ans, get(v));
	}
	ans = min(ans, n - 2 - ans);
	cout << ans << '\n';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}