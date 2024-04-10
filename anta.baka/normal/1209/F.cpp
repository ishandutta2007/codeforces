#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <random>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

const int mod = 1e9 + 7;

const int N = 6e5 + 100;
const int LG = 20;

int tsz = 1;
int to[N][10];
int dep[N];

int up[LG][N];

int n, m;
vector<vector<pii>> g;
vi in_trie;

vi ans;

bool add(int v, int c) {
	if (to[v][c] == -1) {
		to[v][c] = tsz++;
		int u = to[v][c];
		dep[u] = dep[v] + 1;
		up[0][u] = v;
		for (int i = 1; i < LG; i++) {
			up[i][u] = up[i - 1][up[i - 1][u]];
		}
		return true;
	}
	return false;
}

int pw[9];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	pw[0] = 1;
	for (int i = 1; i < 9; i++) pw[i] = 10 * pw[i - 1];
	memset(to, -1, sizeof(to));
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back({ v, i + 1 }); g[v].push_back({ u, i + 1 });
	}
	in_trie.resize(n + 1, -1);
	in_trie[0] = 0;
	ans.resize(n, -1);
	ans[0] = 0;


	auto cmp = [](int u, int v) { // in real g
			if (u == v) return false;
			u = in_trie[u];
			v = in_trie[v];
			if (dep[u] != dep[v]) return dep[u] < dep[v];
			for (int i = LG - 1; i >= 0; i--) {
				if (up[i][u] != up[i][v]) {
					u = up[i][u];
					v = up[i][v];
				}
			}
			int lca = up[0][u];
			int c1 = -1, c2 = -1;
			for (int c = 0; c < 10; c++) {
				if (to[lca][c] == u) return true;
				if (to[lca][c] == v) return false;
			}
			if (c1 < c2) return true;
			return false;
	};



	multiset<int, decltype(cmp)> setik(cmp);
	setik.insert(0);
	vector<bool> duno(n, false);
	while (!setik.empty()) {
		int v = *setik.begin();
		duno[v] = true;
		setik.erase(setik.begin());
		for (auto edge : g[v]) {
			int vto = edge.first;
			if (duno[vto]) continue;
			int w = edge.second;
			vi kek;
			int mem_w = w;
			while (w) {
				kek.pb(w % 10);
				w /= 10;
			}
			reverse(all(kek));
			int node = in_trie[v];
			int mem_del = -1;
			for (int i = 0; i < sz(kek); i++) {
				if (add(node, kek[i]) && mem_del == -1) {
					mem_del = i;
				}
				node = to[node][kek[i]];
			}
			if (ans[vto] == -1) {
				in_trie[vto] = node;
				setik.insert(vto);
				ans[vto] = (1LL * ans[v] * pw[sz(kek)] + mem_w) % mod;
			}
			else {
				in_trie[n] = node;
				if (cmp(n, vto)) {
					setik.erase(setik.find(vto));
					in_trie[vto] = node;
					setik.insert(vto);
					ans[vto] = (1LL * ans[v] * pw[sz(kek)] + mem_w) % mod;
				}
			}
		}
	}
	for (int i = 1; i < n; i++) cout << ans[i] << '\n';
}