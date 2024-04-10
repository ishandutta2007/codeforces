#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef int       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
const int C = 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, nxt, root;
vector<ll> p, comp, sz, edges;
set<pair<ll, pll>> e;
vector<vector<ll>> kids;
bool viv = false;

bool big = false;

const ld PI = 3.1415926535897932384626433;
typedef complex<ld> base;

inline int rev(int val, int b) {
	int res = 0;
	for (int i = 0; i < b; i++) 
		if (val & (1 << i))
			res |= (1 << (b - 1 - i));
	return res;
}

vector<ll> mul_stpd(const vector<ll> &a, const vector<ll> &b) {
	vector<long long> res(a.size() + b.size() - 1);
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			res[i + j] += (long long)a[j] * b[i];
			res[i + j] %= mod;
		}
	}	
	return vector<ll>(res.begin(), res.end());
}


ll pp(ll v) {
	if (p[v] == v)
		return v;
	return p[v] = pp(p[v]);
}

bool full(ll v) {
	if (viv)
		cout << "at " << v << " with sz = " << sz[v] << " see " << edges[v] << endl;
	return ((ll)sz[v] - 1) * (sz[v]) == 2 * edges[v];
}

void unit(ll v, ll u) {
	v = pp(v);
	u = pp(u);
	if (v == u) {
		edges[v]++;
		return;
	}
	if (full(v) && full(u)) {
		if (viv)
			cout << "Fully" << endl;
		if (sz[v] < sz[u])
			swap(v, u);
		sz[v] += sz[u];
		edges[v] += edges[u];
		p[u] = v;
		edges[v]++;

		kids[nxt].push_back(comp[v]);
		kids[nxt].push_back(comp[u]);
		comp[v] = nxt++;
	} else {
		if (viv)
			cout << "Not Fully" << endl;
		if (sz[v] < sz[u])
			swap(v, u);
		if (full(v) && !full(u))
			swap(v, u);
		sz[v] += sz[u];
		edges[v] += edges[u];
		p[u] = v;
		edges[v]++;

		assert(comp[v] >= n);
		if (full(u))
			kids[comp[v]].push_back(comp[u]);
		else {
			for (auto s : kids[comp[u]])
				kids[comp[v]].push_back(s);
		}
	}

	root = comp[v];
}

void work(ll v, ll u) {
	unit(v, u);
}

void show() {
	for (int i = nxt - 1; i >= 0; i--) {
		cout << i << ": ";
		for (auto s : kids[i])
			cout << s << ' ';
		cout << endl;
	}
}

vector<int> get(ll v) {
	if (viv) {
		cout << "get(" << v << ")" << endl;
	}
	if (v < n) {
		return vector<int>({0, 1});
	}
	vector<int> lres(1, 1);
	for (auto s : kids[v]) {
		// get(s);
		lres = mul_stpd(lres, get(s));
		if (viv) {
			cout << "\tnow " << v << ": ";
			for (auto i : lres)
				cout << i << ' ';
			cout << endl;
		}
	}
	while (lres.size() < 2)
		lres.push_back(0);
	lres[1]++;
	if (viv) {
		cout << v << ": ";
		for (auto i : lres)
			cout << i << ' ';
		cout << endl;
	}
	return lres;
}

void solve() {
	cin >> n;
	nxt = n;
	sz.resize(n, 1);
	comp.resize(n);
	p.resize(n);
	edges.resize(n, 0);
	for (int i = 0; i < n; i++)
		p[i] = i, comp[i] = i;
	kids.resize(2 * n);
	vector<pll> use(n * (n - 1) / 2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll w;
			cin >> w;
			if (i < j) {
				use[w - 1] = {i, j};
				// e.insert({w, {i, j}});
			}
		}
	}
	for (auto p : use)
		work(p.F, p.S);
	// root = nxt - 1;
	if (viv)
		show();
	auto res = get(root);
	while(res.size() < n + 1)
		res.push_back(0);
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
	cout << endl;
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