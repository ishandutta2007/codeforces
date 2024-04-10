// #include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n, m;
vector<vector<int>> e;

struct DSU {
	int n;
	vector<int> p;

	DSU() {}
	DSU(int n): n(n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}

	int pp(int v) {
		if (p[v] == v)
			return v;
		return p[v] = pp(p[v]);
	}

	bool join(int a, int b) {
		a = pp(a);
		b = pp(b);
		if (a == b)
			return false;
		p[a] = b;
		return true;
	}
};

vector<int> par, d;
void DFS(int v, int dd = 0) {
	d[v] = dd;
	for (auto u : e[v]) {
		if (d[u] == -1) {
			par[u] = v;
			DFS(u, dd + 1);
		}
	}
} 

const int K = 19;
vector<vector<int>> pp;
void calc_LCA() {
	pp.assign(K, vector<int>(n, -1));
	pp[0] = par;
	for (int lr = 1; lr < K; lr++) {
		for (int i = 0; i < n; i++) {
			pp[lr][i] = pp[lr - 1][pp[lr - 1][i]];
		}
	}
}

int LA(int a, int up) {
	for (int i = K - 1; i >= 0; i--) {
		if (up >= (1 << i)) {
			a = pp[i][a];
			up -= (1 << i);			
		}
	}
	assert(up == 0);
	return a;
}

int LCA(int a, int b) {
	if (d[a] > d[b])
		swap(a, b);
	b = LA(b, d[b] - d[a]);
	if (a == b)
		return a;
	for (int i = K - 1; i >= 0; i--) {
		int pa = pp[i][a];
		int pb = pp[i][b];
		if (pa != pb)
			a = pa, b = pb;
	}
	return par[a];
}

vector<int> st_val;
vector<int> fin_val;
string ans;
void add_bad(int a, int b, int &imp) {
	int c = LCA(a, b);
	if (c == b)
		swap(a, b);

	if (c == a) {
		int dist = d[b] - d[a];
		int akid = LA(b, dist - 1);
		st_val[b] += 1;
		st_val[akid] -= 1;
		if (viv)
			cout << "UP\n";
	} else {
		st_val[a] += 1;
		st_val[b] += 1;
		if (viv)
			cout << "PAR\n";
		imp++;
	}
}

void work(int v) {
	if (v == par[v])
		fin_val[v] = 0;
	else {
		if (fin_val[par[v]] == -1)
			work(par[v]);
	}
	fin_val[v] = fin_val[par[v]];
	fin_val[v] += st_val[v];
}

void solve() {
	cin >> n >> m;
	e.assign(n, {});
	DSU dsu(n);

	vector<pii> bad;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (dsu.join(a, b)) {
			e[a].push_back(b);
			e[b].push_back(a);
		} else {
			bad.push_back({a, b});
		}
	}

	par.assign(n, -1);
	d.assign(n, -1);

	int ROOT = 0;
	DFS(ROOT);
	par[ROOT] = ROOT;
	calc_LCA();

	st_val.assign(n, 0);
	ans.assign(n, '1');
	int imp = 0;
	for (auto [a, b] : bad)
		add_bad(a, b, imp);


	fin_val.assign(n, -1);
	for (int i = 0; i < n; i++)
		work(i);

	for (int i = 0; i < n; i++)
		ans[i] = char('0' + int(fin_val[i] == imp));

	cout << ans << '\n';

	if (viv) {
		for (auto i : par)
			cout << i << ' ';
		cout << endl;
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}