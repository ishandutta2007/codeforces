#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 


ll n, m;
vector<vector<pll>> e;
vector<ll> v, d, ans, x, q;
vector<pll> p;
bool viv = false;

void bad() {
	cout << -1;
	exit(0);
}

bool check() {
	bool res = true;
	for (auto i : v)
		if (i != 0)
			res ^= true;
	return res;
}

void swap() {
	for (int i = 0; i < n; i++)
		if (v[i] == -1)
			return void(v[i] = 0);
}

void DFS(ll v, ll c) {
	d[v] = c;
	for (auto s : e[v])
		if (d[s.F] == -1)
			DFS(s.F, c + 1), p[s.F] = {v, s.S};
	q.push_back(v);
}

void build() {
	d.resize(n, -1);
	p.resize(n, {0, -2});
	DFS(0, 0);
	vector<ll> deg(n, 0);
	for (auto vr : q) {
		if (deg[vr] != v[vr]) {
			deg[vr] ^= 1;
			deg[p[vr].F] ^= 1;
			ans.push_back(p[vr].S);
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i + 1 << ' ';

}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	e.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back({b, i});
		e[b].push_back({a, i});
	}
	if (!check())
		swap();
	if (!check())
		bad();
	for (auto &i : v)
		i = abs(i);
	build();
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}