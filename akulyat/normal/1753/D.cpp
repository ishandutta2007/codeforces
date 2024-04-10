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
int n, m, p, q;
vector<string> f;

vector<vector<pair<pii, int>>> e;

int pair_to_num(int i, int j) {
	return i * m + j;
}

bool rook(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m)
		return true;
	return f[i][j] == '#';
}

bool emp(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m)
		return false;
	return f[i][j] == '.';
}

vector<ll> Dij(vector<int> st) {
	int N = n * m;
	vector<ll> res(N, inf);
	for (auto i : st)
		res[i] = 0;

	set<pll> d;
	for (auto i : st)
		d.insert({res[i], i});

	while (d.size()) {
		auto [lans, u] = *d.begin();
		d.erase({lans, u});

		for (auto [uv, len] : e[u]) {
			auto [u, v] = uv;
			if (res[u] + len < res[v]) {
				d.erase({res[v], v});
				res[v] = res[u] + len;
				d.insert({res[v], v});
			}
		}
	}
	return res;
}


void solve() {
	cin >> n >> m;
	cin >> p >> q;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		f.push_back(s);
	}

	e.resize(n * m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = pair_to_num(i, j);
			if (f[i][j] == 'L') {
				bool nice = false;
				if (!rook(i - 1, j + 1)) {
					int u = pair_to_num(i - 1, j + 1);
					e[u].push_back({{u, v}, p});
					// nice = true;
					nice = nice | (f[i - 1][j + 1] == '.');
				}
				if (!rook(i + 1, j + 1)) {
					int u = pair_to_num(i + 1, j + 1);
					e[u].push_back({{u, v}, p});
					// nice = true;
					nice = nice | (f[i + 1][j + 1] == '.');
				}
				if (!rook(i, j + 2)) {
					int u = pair_to_num(i, j + 2);
					int lq = nice ? min(2 * p, q) : q;
					e[u].push_back({{u, v}, lq});
				}
			}
			if (f[i][j] == 'R') {
				bool nice = false;
				if (!rook(i - 1, j - 1)) {
					int u = pair_to_num(i - 1, j - 1);
					e[u].push_back({{u, v}, p});
					// nice = true;
					nice = nice | (f[i - 1][j - 1] == '.');
				}
				if (!rook(i + 1, j - 1)) {
					int u = pair_to_num(i + 1, j - 1);
					e[u].push_back({{u, v}, p});
					// nice = true;
					nice = nice | (f[i + 1][j - 1] == '.');
				}
				if (!rook(i, j - 2)) {
					int u = pair_to_num(i, j - 2);
					int lq = nice ? min(2 * p, q) : q;
					e[u].push_back({{u, v}, lq});
				}
			}
			if (f[i][j] == 'U') {
				bool nice = false;
				if (!rook(i + 1, j - 1)) {
					int u = pair_to_num(i + 1, j - 1);
					e[u].push_back({{u, v}, p});
					// nice = true;
					nice = nice | (f[i + 1][j - 1] == '.');
				}
				if (!rook(i + 1, j + 1)) {
					int u = pair_to_num(i + 1, j + 1);
					e[u].push_back({{u, v}, p});
					// nice = true;
					nice = nice | (f[i + 1][j + 1] == '.');
				}
				if (!rook(i + 2, j)) {
					int u = pair_to_num(i + 2, j);
					int lq = nice ? min(2 * p, q) : q;
					e[u].push_back({{u, v}, lq});
				}
			}
			if (f[i][j] == 'D') {
				bool nice = false;
				if (!rook(i - 1, j - 1)) {
					int u = pair_to_num(i - 1, j - 1);
					e[u].push_back({{u, v}, p});
					// nice = true;
					nice = nice | (f[i - 1][j - 1] == '.');
				}
				if (!rook(i - 1, j + 1)) {
					int u = pair_to_num(i - 1, j + 1);
					e[u].push_back({{u, v}, p});
					// nice = true;
					nice = nice | (f[i - 1][j + 1] == '.');
				}
				if (!rook(i - 2, j)) {
					int u = pair_to_num(i - 2, j);
					int lq = nice ? min(2 * p, q) : q;
					e[u].push_back({{u, v}, lq});
				}
			}
		}
	}

	vector<int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (emp(i, j)) {
				int v = pair_to_num(i, j);
				st.push_back(v);
			}
		}
	}

	vector<ll> ans = Dij(st);

	ll res = inf;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			if (f[i][j] != 'L') {
				int u = pair_to_num(i, j);
				int v = pair_to_num(i, j + 1);
				if (!rook(i, j) && !rook(i, j + 1)) {
					ll lres = ans[u] + ans[v];
					res = min(res, lres);
					// cout << "See: " << lres << endl;
				}
			}
		}
	}
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < m; j++) {
			if (f[i][j] != 'U') {
				int u = pair_to_num(i, j);
				int v = pair_to_num(i + 1, j);
				if (!rook(i, j) && !rook(i + 1, j)) {
					ll lres = ans[u] + ans[v];
					res = min(res, lres);
					// cout << "See: " << lres << endl;
				}
			}
		}
	}

	if (res == inf)
		res = -1;

	cout << res << '\n';
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