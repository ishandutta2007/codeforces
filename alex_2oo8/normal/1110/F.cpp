#include <bits/stdc++.h>

using namespace std;

const int MX = 500000;
const long long INF = 1e16;

vector<pair<int, int>> G[MX];
int f[MX], sz[MX];

int dfs_sz(int v, int p = -1) {
	sz[v] = 1;
	for (auto& e : G[v]) {
		int u = e.first;
		if (f[u] != 0 || u == p) continue;
		sz[v] += dfs_sz(u, v);
	}
	return sz[v];
}

void decomp(int v, int lev = 1) {
	int n = dfs_sz(v);
	bool ok = true;
	while (ok) {
		ok = false;
		for (auto& e : G[v]) {
			int u = e.first;
			if (f[u] == 0 && sz[u] < sz[v] && sz[u] >= n / 2) {
				v = u;
				ok = true;
				break;
			}
		}
	}
	
	sz[v] = n;
	f[v] = lev;
	
	for (auto& e : G[v]) {
		int u = e.first;
		if (f[u] == 0) decomp(u, lev + 1);
	}
}

namespace seg_tree {
	long long t[2 * MX];
	
	void update(int p, long long value) {
		for (t[p += MX] = value; p >>= 1; ) t[p] = min(t[p<<1], t[p<<1|1]);
	}

	long long getMin(int l, int r) {
		r++;
		long long resl = INF, resr = INF;
		for (l += MX, r += MX; l < r; l >>= 1, r >>= 1) {
			if (l&1) resl = min(resl, t[l++]);
			if (r&1) resr = min(t[--r], resr);
		}
		return min(resl, resr);
	}
}

bool leaf[MX];
vector<tuple<int, int, int>> queries[MX];
long long ans[MX];

void dfs_add(int v, int fv, long long d, int p = -1) {
	if (leaf[v]) seg_tree::update(v, d);
	for (auto& e : G[v]) {
		int u = e.first;
		if (u == p || f[u] <= fv) continue;
		dfs_add(u, fv, d + e.second, v);
	}
}

void dfs_calc(int v, int fv, long long d, int p = -1) {
	for (auto& f : queries[v]) {
		int i, l, r;
		tie(i, l, r) = f;
		ans[i] = min(ans[i], seg_tree::getMin(l, r) + d);
	}
	
	for (auto& e : G[v]) {
		int u = e.first;
		if (u == p || f[u] <= fv) continue;
		dfs_calc(u, fv, d + e.second, v);
	}
}

int main() {
	int n, q;
	ignore = scanf("%d %d", &n, &q);
	fill(leaf, leaf + n, true);
	for (int i = 1, p, w; i < n; i++) {
		ignore = scanf("%d %d", &p, &w);
		p--;
		G[p].emplace_back(i, w);
		G[i].emplace_back(p, w);
		leaf[p] = false;
	}
	
	for (int i = 0, v, l, r; i < q; i++) {
		ignore = scanf("%d %d %d", &v, &l, &r);
		queries[v - 1].emplace_back(i, l - 1, r - 1);
		ans[i] = INF;
	}
	
	decomp(0);
	
	fill(seg_tree::t, seg_tree::t + 2 * MX, INF);
	
	for (int v = 0; v < n; v++) {
		dfs_add(v, f[v], 0);
		dfs_calc(v, f[v], 0);
		dfs_add(v, f[v], INF);
	}
	
	for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
	
	return 0;
}