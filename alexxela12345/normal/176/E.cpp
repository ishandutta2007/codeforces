#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5 + 1337;
const int LOG = 20;
vector<pair<int, int>> g[MAXN];
int tin[MAXN];
int cur_time = 0;

void dfs(int v, int pp = -1) {
	tin[v] = cur_time++;
	for (auto u : g[v]) {
		if (u.first != pp) {
			dfs(u.first, v);
		}
	}
}

struct ver {
	int v;
	ver(int v) : v(v) {}
	bool operator<(const ver &o) const {
		return tin[v] < tin[o.v];
	}
};

int p[MAXN][LOG];
int sum[MAXN][LOG];
int d[MAXN];

void dfs2(int v, int pp, int summ) {
	d[v] = d[pp] + 1;
	p[v][0] = pp;
	sum[v][0] = summ;
	for (int i = 1; i < LOG; i++) {
		p[v][i] = p[p[v][i - 1]][i - 1];
		sum[v][i] = sum[v][i - 1] + sum[p[v][i - 1]][i - 1];
	}
	for (auto u : g[v]) {
		if (u.first != pp) {
			dfs2(u.first, v, u.second);
		}
	}
}

int up(int v, int c) {
	for (int i = LOG - 1; i >= 0; i--) {
		if ((1 << i) <= c) {
			c -= (1 << i);
			v = p[v][i];
		}
	}
	return v;
}

int get(int v, int c) {
	int ans = 0;
	for (int i = LOG - 1; i >= 0; i--) {
		if ((1 << i) <= c) {
			ans += sum[v][i];
			c -= (1 << i);
			v = p[v][i];
		}
	}
	return ans;
}

int lca(int u, int v) {
	if (d[u] > d[v]) {
		swap(u, v);
	}
	v = up(v, d[v] - d[u]);
	if (u == v) {
		return u;
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (p[v][i] != p[u][i]) {
			v = p[v][i];
			u = p[u][i];
		}
	}
	return p[u][0];
}


signed main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	dfs(0);
	dfs2(0, 0, 0);
	set<ver> vers;
	int q;
	cin >> q;
	int ans = 0;
	while (q--) {
		char t;
		cin >> t;
		if (t == '+') {
			int x;
			cin >> x;
			x--;
			ver v(x);
			if (vers.empty()) {
				vers.insert(v);
			} else {
				auto it = vers.lower_bound(v);
				if (it == vers.begin()) {
					int l = lca(it->v, x);
					auto it2 = vers.rbegin();
					int l2 = lca(it->v, it2->v) ^ l ^ lca(it2->v, x);
					int l3 = lca(l2, x);
					ans += get(l2, d[l2] - d[l3]);
					ans += get(x, d[x] - d[l3]);
				} else if (it == vers.end()) {
					it--;
					int l = lca(it->v, x);
					auto it2 = vers.begin();
					int l2 = lca(it->v, it2->v) ^ l ^ lca(it2->v, x);
					int l3 = lca(l2, x);
					ans += get(l2, d[l2] - d[l3]);
					ans += get(x, d[x] - d[l3]);
				} else {
					auto it2 = --vers.lower_bound(v);
					int l2 = lca(it->v, x) ^ lca(it2->v, x) ^ lca(it->v, it2->v);
					int l = lca(l2, x);
					ans += get(x, d[x] - d[l]) + get(l2, d[l2] - d[l]);
				}
				vers.insert(v);
			} 
		} else if (t == '-') {
			int x;
			cin >> x;
			x--;
			ver v(x);
			vers.erase(v);
			if (vers.empty()) {
				continue;
			} else {
				auto it = vers.lower_bound(v);
				if (it == vers.begin()) {
					int l = lca(it->v, x);
					auto it2 = vers.rbegin();
					int l2 = lca(it->v, it2->v) ^ l ^ lca(it2->v, x);
					int l3 = lca(l2, x);
					ans -= get(l2, d[l2] - d[l3]);
					ans -= get(x, d[x] - d[l3]);
				} else if (it == vers.end()) {
					it--;
					int l = lca(it->v, x);
					auto it2 = vers.begin();
					int l2 = lca(it->v, it2->v) ^ l ^ lca(it2->v, x);
					int l3 = lca(l2, x);
					ans -= get(l2, d[l2] - d[l3]);
					ans -= get(x, d[x] - d[l3]);
				} else {
					auto it2 = --vers.lower_bound(v);
					int l2 = lca(it->v, x) ^ lca(it2->v, x) ^ lca(it->v, it2->v);
					int l = lca(l2, x);
					ans -= get(x, d[x] - d[l]) + get(l2, d[l2] - d[l]);
				}
			} 
		} else {
			cout << ans << endl;
		}
	}
}