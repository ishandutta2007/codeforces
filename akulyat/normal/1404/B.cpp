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

int n, a, b, da, db;
vector<ll> v;
vector<vector<int>> e;
vector<int> d, down, q;
bool viv = false;

void DFS(int v, int c = 0) {
	d[v] = c;
	for (auto u : e[v])
		if (d[u] == -1)
			DFS(u, c + 1);
	q.push_back(v);
}

int work(int v) {
	pii res = {0, 0};
	down[v] = 1;
	for (auto u : e[v]) {
		if (d[u] > d[v])
			down[v] = max(down[v], 1 + down[u]);
		if (down[u] >= res.F)
			res.S = res.F, res.F = down[u];
		else
			res.S = max(res.S, down[u]);
	}
	// cout << v + 1 << ": " << res.F << ' ' << res.S << endl;
	return res.F + res.S;
}

int diam() {
	int res = 0;
	for (auto v : q)
		res = max(res, work(v));
	return res;
}

void solve() {
	cin >> n;
	cin >> a >> b >> da >> db;
	e.clear();
	e.resize(n);
	d.clear();
	d.resize(n, -1);
	down.clear();
	down.resize(n, 0);
	q.clear();
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}	
	a--, b--;
	DFS(a);

	if (d[b] <= da) {
		cout << "Alice\n";
		return;
	}

	int dm = diam();
	// cout << "See: " << dm << endl;
	db = min(db, dm);
	if (db >= 2 * da + 1) {
		cout << "Bob\n";
		return;
	}
	cout << "Alice\n";
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