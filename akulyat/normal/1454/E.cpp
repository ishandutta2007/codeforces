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
vector<ll> p, d, c, path;
vector<bool> used, in_c;
vector<vector<int>> e;
bool viv = false;

ll cnt = 0;

void DFS(int v, int cc = 0) {
	d[v] = cc;
	path.push_back(v);
	for (auto u : e[v]) {
		if (d[u] == -1) {
			p[u] = v, DFS(u, cc + 1);
		} else {
			if (u != p[v] && !used[u]) {
				// cout << "\t";
				// cout << v << ' ' << u << endl;
				// cout << "\t";
				// for (auto i : path)
				// 	cout << i << ' ';
				// cout << endl;

				int pl = path.size() - 1;
				while (c.empty() || c.back() != u)
					c.push_back(path[pl]), pl--;
			}
		}
	}
	path.pop_back();
	used[v] = true;
}

void DFS2(int v, int cc = 0) {
	d[v] = cc;
	cnt++;
	for (auto u : e[v])
		if (!in_c[u] && d[u] == -1)
			DFS2(u, cc + 1);
}

void solve() {
	cin >> n;
	e.clear();
	e.resize(n);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}	
	d.assign(n, -1);
	p.assign(n, -1);
	used.assign(n, false);
	c.clear();
	DFS(0);
	if (viv) {
		for (auto i : c)
			cout << i << ' ';
		cout << endl;
	}

	d.assign(n, -1);
	ll ans = n * (n - 1);
	in_c.assign(n, false);
	for (auto i : c)
		in_c[i] = true;
	for (auto v : c) {
		cnt = 0;
		DFS2(v);
		// cout << cnt << '\n';
		ans -= cnt * (cnt - 1) / 2;
	}
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