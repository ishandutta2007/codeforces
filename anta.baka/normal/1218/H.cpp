#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cassert>
#include <set>
#include <cstring>
#include <map>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using vi = vector<int>;

int n;
vi a;
vector<vi> g;
vector<vi> cycles;
vi color;
vector<bool> on_cycle;
vi roots;
vi d_root;
vi what_cycle;
vector<vector<vi>> dists_by_rem;
vi ans;
vector<vector<pair<int, ll>>> to_ask;
vector<vi> keko;
vector<vi*> lnk;
vector<vector<pair<int, ll>>> to_ask2;
vector<vi> subtree;
vector<map<int, int>> cnt;

void dfs_subtree(int v, int p, int root) {
	subtree[root].pb(v);
	for (int to : g[v]) {
		if (to != p && !on_cycle[to]) {
			dfs_subtree(to, v, root);
		}
	}
}

void dfs_dist(int v, int cycle) {
	what_cycle[v] = cycle;
	for (int to : g[v]) {
		if (d_root[to] == -1) {
			d_root[to] = d_root[v] + 1;
			dfs_dist(to, cycle);
		}
	}
}

void dfs(int v, int p, int dep) {
	int kid = -1;
	for (int to : g[v]) {
		if (to != p && !on_cycle[to]) {
			dfs(to, v, dep + 1);
			if (kid == -1 || lnk[to]->size() > lnk[kid]->size()) {
				kid = to;
			}
		}
	}
	if (kid == -1) {
		lnk[v] = &keko[v];
	}
	else {
		lnk[v] = lnk[kid];
	}
	for (int to : g[v]) {
		if (to != p && !on_cycle[to] && to != kid) {
			for (int i = 0; i < lnk[to]->size(); i++) {
				(*lnk[v])[lnk[v]->size() - 1 - (lnk[to]->size() - i - 1)] += (*lnk[to])[i];
			}
			vi().swap(*lnk[to]);
		}
	}
	lnk[v]->pb(1);
	for (auto query : to_ask[v]) {
		if (query.second < lnk[v]->size()) {
			ans[query.first] += (*lnk[v])[lnk[v]->size() - 1 - query.second];
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	a.resize(n);
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		--a[i];
		g[a[i]].pb(i);
	}
	color.resize(n, -1);
	on_cycle.resize(n, false);
	for (int start = 0; start < n; start++) {
		if (color[start] != -1) continue;
		int u = start;
		vi path;
		while (color[u] == -1) {
			path.pb(u);
			color[u] = start;
			u = a[u];
		}
		if (color[u] == start) {
			reverse(all(path));
			while (path.back() != u) {
				path.pop_back();
			}
			cycles.emplace_back(path);
			for (auto v : path) {
				on_cycle[v] = true;
			}
		}
	}
	
	subtree.resize(n);
	for (int u = 0; u < n; u++) {
		if (on_cycle[u]) {
			dfs_subtree(u, -1, u);
		}
	}

	d_root.resize(n, -1);
	roots.resize(sz(cycles));
	what_cycle.resize(n);
	for (int i = 0; i < sz(cycles); i++) {
		roots[i] = cycles[i][0];
		d_root[roots[i]] = 0;
		dfs_dist(roots[i], i);
	}
	
	dists_by_rem.resize(sz(cycles));
	for (int i = 0; i < sz(cycles); i++) {
		dists_by_rem[i].resize(sz(cycles[i]));
	}
	for (int u = 0; u < n; u++) {
		dists_by_rem[what_cycle[u]][d_root[u] % sz(cycles[what_cycle[u]])].pb(d_root[u]);
	}
	for (int i = 0; i < sz(cycles); i++) {
		for (auto& v : dists_by_rem[i]) {
			sort(all(v));
		}
	}

	/*
	10
	3 1 2 5 6 4 2 10 7 1
	5
	10 1
	5 7
	10 6
	1 1
	10 8

	*/

	int q;
	cin >> q;
	ans.resize(q, 0);
	to_ask.resize(n);
	to_ask2.resize(n);
	for (int i = 0; i < q; i++) {
		ll m;
		int y;
		cin >> m >> y;
		--y;
		if (on_cycle[y]) {
			int cyc = what_cycle[y];
			int len = sz(cycles[cyc]);
			int rem = (m + d_root[y]) % len;
			ans[i] = upper_bound(all(dists_by_rem[cyc][rem]), m - (len - d_root[y]) % len) - dists_by_rem[cyc][rem].begin();
			if (d_root[y] > 0) {
				to_ask2[y].emplace_back(i, m + d_root[y]);
			}
		}
		else {
			to_ask[y].emplace_back(i, m);
		}
	}

	cnt.resize(sz(cycles));
	for(int i = 0; i < sz(cycles); i++) {
		reverse(all(cycles[i]));
		for (int j = 0; j < sz(cycles[i]) - 1; j++) {
			for (int u : subtree[cycles[i][j]]) {
				cnt[i][d_root[u]]++;
			}
			for (auto query : to_ask2[cycles[i][j]]) {
				ans[query.first] += cnt[i][query.second];
			}
		}
	}

	keko.resize(n);
	lnk.resize(n);
	for (int i = 0; i < n; i++) {
		if (on_cycle[i]) {
			dfs(i, -1, 0);
		}
	}
	for (auto x : ans) cout << x << '\n';
}