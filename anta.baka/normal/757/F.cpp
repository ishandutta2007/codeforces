#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <functional>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = 3e5;
const ll inf64 = 1e18L;

int n, m, s;
vector<pii> g[N];

struct dominator_tree {
	int n, root;
	vi tin, revin, sdom, idom;
	vector<vi> g, revg;
	vi par, dsu, min_v;

	int get(int v) {
		if (dsu[v] == v) {
			return v;
		}
		int next_v = get(dsu[v]);
		if (sdom[min_v[dsu[v]]] < sdom[min_v[v]]) {
			min_v[v] = min_v[dsu[v]];
		}
		return dsu[v] = next_v;
	}
	dominator_tree(int n, int root) : n(n), root(root) {
		tin.resize(n, -1);
		revin.resize(n, -1);
		sdom.resize(n);
		idom.resize(n);
		g.resize(n);
		revg.resize(n);
		dsu.resize(n);
		par.resize(n, -1);
		min_v.resize(n, -1);
		for (int i = 0; i < n; i++) {
			dsu[i] = min_v[i] = sdom[i] = idom[i] = i;
		}
	}
	void dfs(int v, const vector<vi>& cur_g, int& timer) {
		tin[v] = timer++;
		for (int to : cur_g[v]) {
			if (tin[to] == -1) {
				dfs(to, cur_g, timer);
				par[tin[to]] = tin[v];
			}
			revg[tin[to]].pb(tin[v]);
		}
	}
	vi get_tree(const vector<vi>& cur_g) {
		int timer = 0;
		dfs(root, cur_g, timer);
		for (int i = 0; i < n; i++) {
			if (tin[i] != -1) {
				revin[tin[i]] = i;
				for (int to : cur_g[i]) {
					g[tin[i]].pb(tin[to]);
				}
			}
		}
		vector<vi> buckets(n);
		for (int i = n - 1; i >= 0; i--) {
			for (int to : revg[i]) {
				get(to);
				sdom[i] = min(sdom[i], sdom[min_v[to]]);
			}
			if (revin[i] == -1) {
				continue;
			}
			if (i) {
				buckets[sdom[i]].pb(i);
			}
			for (int w : buckets[i]) {
				get(w);
				int v = min_v[w];
				if (sdom[v] == sdom[w]) {
					idom[w] = sdom[w];
				}
				else {
					idom[w] = v;
				}
			}
			for (int to : g[i]) {
				if (par[to] == i) {
					dsu[to] = i;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (revin[i] != -1 && idom[i] != sdom[i]) {
				idom[i] = idom[idom[i]];
			}
		}
		vi res(n, -1);
		for (int i = 0; i < n; i++) {
			if (revin[i] != -1) {
				res[revin[i]] = revin[idom[i]];
			}
		}
		return res;
	}
};

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m >> s; --s;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].pb({ v, w });
		g[v].pb({ u, w });
	}
	vector<ll> dist(n, inf64);
	dist[s] = 0;
	set<pair<ll, int>> setik;
	setik.insert({ 0, s });
	while (!setik.empty()) {
		int v = setik.begin()->second;
		setik.erase(setik.begin());
		for (const auto& e : g[v]) {
			int to = e.first;
			int w = e.second;
			if (dist[v] + w < dist[to]) {
				setik.erase({ dist[to], to });
				dist[to] = dist[v] + w;
				setik.insert({ dist[to], to });
			}
		}
	}
	vector<vi> G(n);
	for (int u = 0; u < n; u++) {
		for (const auto& e : g[u]) {
			if (dist[u] + e.second == dist[e.first]) {
				G[u].pb(e.first);
			}
		}
	}
	dominator_tree kek(n, s);
	vi idom = kek.get_tree(G);
	vector<vi> T(n);
	for (int i = 0; i < n; i++) {
		if (idom[i] != i && idom[i] != -1) {
			T[idom[i]].pb(i);
		}
	}
	vi Sz(n);
	function<int(int)> dfs_sz = [&T, &Sz, &dfs_sz](int v) {
		int ret = 0;
		Sz[v] = 1;
		for (int to : T[v]) {
			dfs_sz(to);
			Sz[v] += Sz[to];
			ret = max(ret, Sz[to]);
		}
		return ret;
	};
	cout << dfs_sz(s);
}