#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

int n, m, x;
vector<ll> a;
vector<int> sz;
vector<int> par;
vector<set<int>> out;
vector<set<int>> roots(3);
vector<pair<int, int>> e;
vector<int> ans;

int get(int v) {
	while (par[v] != v) {
		v = par[v];
	}
	return v;
}

int get_lvl(ll val) {
	return (val >= x ? 0 : (2 * val >= x ? 1 : 2));
}

void merge(int u, int v, int i) {
	if (u != v && a[u] + a[v] >= x) {
		roots[get_lvl(a[u])].erase(u);
		roots[get_lvl(a[v])].erase(v);
		if (sz[u] < sz[v]) {
			swap(u, v);
		}
		par[v] = u;
		sz[u] += sz[v];
		a[u] += a[v] - x;
		for (auto x : out[v]) {
			out[u].insert(x);
		}
		roots[get_lvl(a[u])].insert(u);
		ans.push_back(i);
	}
	out[u].erase(i);
	out[v].erase(i);
}

void yep() {
	cout << "YES\n";
	for (auto e : ans) {
		cout << e + 1 << '\n';
	}
	exit(0);
}

void nope() {
	cout << "NO\n";
	exit(0);
}

int get_other(int u, int i) {
	return (get(e[i].first) == u ? e[i].second : e[i].first);
}

void solve() {
	cin >> n >> m >> x;
	a.resize(n);
	for (int u = 0; u < n; u++) {
		cin >> a[u];
		roots[get_lvl(a[u])].insert(u);
	}
	sz.resize(n, 1);
	par.resize(n);
	iota(par.begin(), par.end(), 0);
	out.resize(n);
	e.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> e[i].first >> e[i].second;
		--e[i].first;
		--e[i].second;
		out[e[i].first].insert(i);
		out[e[i].second].insert(i);
	}

	while (!roots[0].empty()) {
		int u = *roots[0].begin();
		if (out[u].empty()) {
			yep();
		}
		int i = *out[u].begin();
		merge(u, get(get_other(u, i)), i);
	}
	if (roots[2].size() > 1) {
		nope();
	}
	while (roots[1].size() + roots[2].size() > 1) {
		int u = (!roots[2].empty() ? *roots[2].begin() : *roots[1].begin());
		if (out[u].empty()) {
			nope();
		}
		int i = *out[u].begin();
		merge(u, get(get_other(u, i)), i);
	}
	yep();
}

int main() {
	ios::sync_with_stdio(false);
	solve();
}