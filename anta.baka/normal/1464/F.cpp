#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int LG = 20;
const int inf = 1e9 + 228;

struct Fenwick {
	int n;
	vector<int> t;
	Fenwick(int n) : n(n), t(n) {}
	void upd(int v, int x) {
		for (int i = v; i < n; i |= i + 1) {
			t[i] += x;
		}
	}
	int get(int v) {
		int res = 0;
		for (int i = v; i >= 0; i = (i & (i + 1)) - 1) {
			res += t[i];
		}
		return res;
	}
	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

struct SegTree {
	int n;
	vector<int> t;
	SegTree(int n) : n(n), t(2 * n, -inf) {}
	void upd(int v, int x) {
		t[v += n] = x;
		for (v >>= 1; v; v >>= 1) {
			t[v] = max(t[v << 1], t[v << 1 | 1]);
		}
	}
	int get(int l, int r) {
		int ret = -inf;
		for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if (l & 1) {
				ret = max(ret, t[l]);
			}
			if (!(r & 1)) {
				ret = max(ret, t[r]);
			}
		}
		return ret;
	}
};

struct Query {
	int type;
	int u, v;
	int d;
};

struct HpItem {
	int in_hp_v;
	int in_desc_v;
	int src_v;
	bool operator < (const HpItem& o) const {
		return in_hp_v > o.in_hp_v || in_hp_v == o.in_hp_v && in_desc_v > o.in_desc_v || 
			in_hp_v == o.in_hp_v && in_desc_v == o.in_desc_v && src_v > o.src_v;
	}
};

int n, q;
vector<vector<int>> g;
vector<Query> qs;
vector<vector<int>> up;
vector<int> pred;
vector<int> in;
vector<int> out;
int timer;
vector<int> dep;
vector<int> sz;
vector<int> top;
vector<int> bot;
vector<vector<HpItem>> hpq;
vector<SegTree> onBot;
vector<SegTree> onTop;
vector<vector<int>> cnt;

void dfs_tree(int v, int p) {
	if (v > 0) {
		auto it = g[v].begin();
		while (*it != p) {
			it++;
		}
		g[v].erase(it);
	}
	up[v][0] = p;
	pred[v] = p - !v;
	for (int i = 1; i < LG; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	sz[v] = 1;
	for (int& to : g[v]) {
		dep[to] = dep[v] + 1;
		dfs_tree(to, v);
		sz[v] += sz[to];
		if (sz[to] > sz[g[v][0]]) {
			swap(to, g[v][0]);
		}
	}
}

void dfs_hld(int v) {
	in[v] = timer++;
	for (int to : g[v]) {
		if (to == g[v][0]) {
			top[to] = top[v];
			bot[top[v]] = to;
		}
		else {
			top[to] = to;
			bot[to] = to;
		}
		dfs_hld(to);
	}
	out[v] = timer;
}

bool upper(int u, int v) {
	return (in[u] <= in[v] && out[v] <= out[u]);
}

int lca(int u, int v) {
	if (in[u] > in[v]) {
		swap(u, v);
	}
	if (upper(u, v)) {
		return u;
	}
	for (int i = LG - 1; i >= 0; i--) {
		if (!upper(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

int kth(int v, int k) {
	for (int i = LG - 1; i >= 0; i--) {
		if ((1 << i) <= k) {
			v = up[v][i];
			k -= (1 << i);
		}
	}
	return v;
}

void upd(int u, int dt) {
	int v = u;
	int desc = -1;
	while (v != -1) {
		int pos = lower_bound(hpq[top[v]].begin(), hpq[top[v]].end(), HpItem{ in[v], (desc == -1 ? -1 : in[desc]), u }) - hpq[top[v]].begin();
		bool ex = (cnt[top[v]][pos] > 0);
		cnt[top[v]][pos] += dt;
		if (!ex) {
			onBot[top[v]].upd(pos, dep[u]);
			onTop[top[v]].upd(pos, dep[u] - dep[v] + (dep[bot[top[v]]] - dep[v]));
		}
		else if (cnt[top[v]][pos] == 0) {
			onBot[top[v]].upd(pos, -inf);
			onTop[top[v]].upd(pos, -inf);
		}
		desc = top[v];
		v = pred[top[v]];
	}
}

int get(int u, int v) { // lower upper
	int ret = -inf;
	int roma = u;
	int desc = -1;
	while (top[u] != top[v]) {
		int R = upper_bound(hpq[top[u]].begin(), hpq[top[u]].end(), HpItem{ in[u], (desc == -1 ? -1 : in[desc]), -inf }) - hpq[top[u]].begin(); // [R..
		int L = upper_bound(hpq[top[u]].begin(), hpq[top[u]].end(), HpItem{ in[u], (desc == -1 ? -1 : in[desc]), inf }) - hpq[top[u]].begin() - 1; // ..L]
		if (L >= 0) {
			ret = max(ret, (onBot[top[u]].get(0, L) - dep[u]) + (dep[roma] - dep[u]));
		}
		if (R < onTop[top[u]].n) {
			ret = max(ret, (onTop[top[u]].get(R, onTop[top[u]].n - 1) - (dep[bot[top[u]]] - dep[u])) + (dep[roma] - dep[u]));
		}
		desc = top[u];
		u = pred[top[u]];
	}
	{
		int R = upper_bound(hpq[top[u]].begin(), hpq[top[u]].end(), HpItem{ in[u], (desc == -1 ? -1 : in[desc]), -inf }) - hpq[top[u]].begin(); // [R..
		int L = upper_bound(hpq[top[u]].begin(), hpq[top[u]].end(), HpItem{ in[u], (desc == -1 ? -1 : in[desc]), inf }) - hpq[top[u]].begin() - 1; // ..L]
		if (L >= 0) {
			ret = max(ret, (onBot[top[u]].get(0, L) - dep[u]) + (dep[roma] - dep[u]));
		}
		int bound = upper_bound(hpq[top[u]].begin(), hpq[top[u]].end(), HpItem{ in[v], -inf, -inf }) - hpq[top[u]].begin() - 1;
		if (R <= bound) {
			ret = max(ret, (onTop[top[u]].get(R, bound) - (dep[bot[top[u]]] - dep[u])) + (dep[roma] - dep[u]));
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	qs.resize(q);
	for (auto& qry : qs) {
		cin >> qry.type;
		if (qry.type <= 2) {
			cin >> qry.u >> qry.v;
			--qry.u;
			--qry.v;
		}
		else {
			cin >> qry.d;
		}
	}
	up.resize(n, vector<int>(LG));
	dep.resize(n);
	sz.resize(n);
	pred.resize(n);
	dfs_tree(0, 0);
	in.resize(n);
	out.resize(n);
	top.resize(n);
	bot.resize(n);
	dfs_hld(0);
	hpq.resize(n);
	for (int u = 0; u < n; u++) {
		int v = u;
		int desc = -1;
		while (v != -1) {
			hpq[top[v]].push_back({ in[v], (desc == -1 ? -1 : in[desc]), u });
			desc = top[v];
			v = pred[top[v]];
		}
	}
	cnt.resize(n);
	for (int u = 0; u < n; u++) {
		sort(hpq[u].begin(), hpq[u].end());
		onBot.emplace_back(hpq[u].size());
		onTop.emplace_back(hpq[u].size());
		cnt[u].resize(hpq[u].size());
	}
	multiset<pair<int, int>> setik;
	Fenwick fen(n);
	for (int i = 0; i < q; i++) {
		if (qs[i].type == 1) {
			int u = qs[i].u;
			int v = qs[i].v;
			int _lca = lca(u, v);
			setik.insert({ dep[_lca], _lca });
			fen.upd(in[u], 1);
			fen.upd(in[v], 1);
			fen.upd(in[_lca], -1);
			upd(_lca, 1);
		}
		else if (qs[i].type == 2) {
			int u = qs[i].u;
			int v = qs[i].v;
			int _lca = lca(u, v);
			setik.erase(setik.find({ dep[_lca], _lca }));
			fen.upd(in[u], -1);
			fen.upd(in[v], -1);
			fen.upd(in[_lca], 1);
			upd(_lca, -1);
		}
		else {
			int d = qs[i].d;
			int v = setik.rbegin()->second;
			int roma = kth(v, d);
			int u = kth(roma, d);
			if (fen.get(in[u], out[u] - 1) != setik.size()) {
				cout << "No\n";
				continue;
			}
			cout << (get(roma, u) <= d ? "Yes\n" : "No\n");
		}
	}
}