#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

const int N = 1e5;
const int M = (1 << 15);

using BS = bitset<M>;

int n;
vector<int> g[N];
int m;
vector<int> pid[N];
int _size[N];
BS on_me[N];
BS deal_edge[M];
BS complete[M];
int U[M];
int V[M];
int in[N];
int out[N];
int timer;
BS was;
vector<int> tps;
int comp[N];
int cur_comp;
BS foo;
BS bar;
BS a;
BS b;

#define _g deal_edge
#define _rg complete

bool upper(int u, int v) {
	return (in[u] <= in[v] && out[v] <= out[u]);
}

void dfs_micro_zalupa(int v, int p, int root) {
	for (int to : g[v]) {
		if (to == p) continue;
		dfs_micro_zalupa(to, v, root);
	}
	for (int id : pid[v]) {
		int u = v ^ U[id] ^ V[id];
		if (upper(root, u)) continue;
		deal_edge[id] |= on_me[root];
	}
}

void dfs_time(int v, int p) {
	in[v] = timer++;
	for (int to : g[v]) {
		if (to == p) continue;
		dfs_time(to, v);
	}
	out[v] = timer++;
}

void dfs_tree(int v, int p) {
	int epikid = -1;
	_size[v] = 1 + pid[v].size();
	for (int to : g[v]) {
		if (to == p) continue;
		dfs_tree(to, v);
		_size[v] += _size[to];
		if (epikid == -1 || _size[to] >= _size[epikid]) {
			epikid = to;
		}
	}
	if (epikid != -1) {
		on_me[v] = on_me[epikid];
	}
	for (int to : g[v]) {
		if (to == p || to == epikid) continue;
		on_me[v] ^= on_me[to];
	}
	for (int id : pid[v]) {
		on_me[v].flip(id);
	}
	for (int id : pid[v]) {
		int u = v ^ U[id] ^ V[id];
		if (upper(v, u)) continue;
		deal_edge[id] |= on_me[v];
	}
	for (int to : g[v]) {
		if (to == p || to == epikid) continue;
		dfs_micro_zalupa(to, v, v);
	}
}

void transpose(BS deal_edge[]) {
	int w = 1;
	while (w < 2 * m) {
		w <<= 1;
	}
	for (int k = 1; k < w; k <<= 1) {
		foo.reset();
		for (int start = 0; start < w; start += (k << 1)) {
			for (int i = 0; i < k; i++) {
				foo.set(start + i);
			}
		}
		bar = (foo << k);

		for (int start = 0; start < w; start += (k << 1)) {
			int nexel = start + k;
			for (int i = 0; i < k; i++) {
				a = (deal_edge[start + i] & bar) >> k;
				b = (deal_edge[nexel + i] & foo) << k;
				deal_edge[start + i] = (deal_edge[start + i] & foo) | b;
				deal_edge[nexel + i] = (deal_edge[nexel + i] & bar) | a;
			}
		}
	}
}

void get_tps(int v) {
	was.reset(v);
	while (true) {
		auto to = (was & _g[v])._Find_first();
		if (to == M) break;
		get_tps(to);
	}
	tps.push_back(v);
}

void dfs_comp(int v) {
	was.reset(v);
	comp[v] = cur_comp;
	while (true) {
		auto to = (was & _rg[v])._Find_first();
		if (to == M) break;
		dfs_comp(to);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a; --b; --c; --d;
		pid[a].push_back(i);
		pid[b].push_back(i);
		pid[c].push_back(i + m);
		pid[d].push_back(i + m);
		U[i] = a;
		V[i] = b;
		U[i + m] = c;
		V[i + m] = d;
	}
	dfs_time(0, -1);
	dfs_tree(0, -1);

	for (int i = 0; i < 2 * m; i++) {
		deal_edge[i].reset(i);
		complete[i] = deal_edge[i];
	}

	transpose(deal_edge);

	for (int i = 0; i < 2 * m; i++) {
		complete[i] |= deal_edge[i];
		_g[i].reset();
	}

	for (int u = 0; u < m; u++) {
		_g[u + m] |= (complete[u]);
	}
	for (int u = m; u < 2 * m; u++) {
		_g[u - m] |= (complete[u]);
	}

	for (int i = 0; i < 2 * m; i++) {
		_rg[i] = _g[i];
	}
	transpose(_rg);

	was.set();
	for (int u = 0; u < 2 * m; u++) {
		if (was[u] == 1) {
			get_tps(u);
		}
	}
	reverse(tps.begin(), tps.end());

	was.set();
	for (int u : tps) {
		if (was[u] == 0) continue;
		dfs_comp(u);
		cur_comp++;
	}

	for (int u = 0; u < m; u++) {
		if (comp[u] == comp[u + m]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	for (int u = 0; u < m; u++) {
		cout << 1 + (comp[u] > comp[u + m]) << '\n';
	}
}