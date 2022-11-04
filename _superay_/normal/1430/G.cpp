#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int V = 105;
const int E = 11000;
namespace F {
int n, head[V], to[E], cap[E], cst[E], nxt[E], eid;
inline void Init(int _n) {
	n = _n;
	for (int i = 0; i < n; i++) head[i] = -1;
	eid = 0;
}
inline void _add_edge(int u, int v, int w, int c) {
	to[eid] = v;
	cap[eid] = w;
	cst[eid] = c;
	nxt[eid] = head[u];
	head[u] = eid++;
}
inline void add_edge(int u, int v, int w, int c) {
	_add_edge(u, v, w, c);
	_add_edge(v, u, 0, -c);
}
int dist[V], pre[V];
bool inq[V];
inline bool SPFA(int s, int t) {
	for (int i = 0; i < n; i++) dist[i] = INF, pre[i] = -1, inq[i] = 0;
	queue<int> que;
	dist[s] = 0;
	que.push(s);
	inq[s] = 1;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		inq[u] = 0;
		for (int i = head[u]; ~i; i = nxt[i]) if (cap[i] > 0) {
			int v = to[i];
			if (dist[v] > dist[u] + cst[i]) {
				dist[v] = dist[u] + cst[i];
				pre[v] = i;
				if (!inq[v]) {
					que.push(v);
					inq[v] = 1;
				}
			}
		}
	}
	return pre[t] != -1;
}
inline void solve(int s, int t) {
	while (SPFA(s, t)) {
		int mn = INF;
		for (int u = t; u != s; u = to[pre[u] ^ 1]) {
			mn = min(mn, cap[pre[u]]);
		}
		for (int u = t; u != s; u = to[pre[u] ^ 1]) {
			cap[pre[u]] -= mn;
			cap[pre[u] ^ 1] += mn;
		}
	}
}
}
int n, m, sw[V], eu[E], ev[E];
namespace G {
vector<pair<int, int> > G[V];
inline void add_edge(int u, int v, int w) {
	G[u].push_back(make_pair(v, w));
}
int dist[V];
bool inq[V];
inline void solve(int s) {
	for (int i = 0; i <= n; i++) dist[i] = -INF, inq[i] = 0;
	queue<int> que;
	dist[s] = 0;
	que.push(s);
	inq[s] = 1;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		inq[u] = 0;
		for (auto &e : G[u]) {
			int v = e.first, w = e.second;
			if (dist[v] < dist[u] + w) {
				dist[v] = dist[u] + w;
				if (!inq[v]) {
					que.push(v);
					inq[v] = 1;
				}
			}
		}
	}
}
}
int main() {
	scanf("%d%d", &n, &m);
	F::Init(n + 2);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		sw[u] += w;
		sw[v] -= w;
		F::add_edge(u, v, INF, -1);
		G::add_edge(v, u, 1);
		eu[i] = u, ev[i] = v;
	}
	for (int i = 1; i <= n; i++) {
		if (sw[i] > 0) F::add_edge(0, i, sw[i], 0);
		else if (sw[i] < 0) F::add_edge(i, n + 1, -sw[i], 0);
		G::add_edge(0, i, 0);
	}
	F::solve(0, n + 1);
	for (int i = 1; i <= m; i++) if (F::cap[i * 2 - 1]) {
		G::add_edge(eu[i], ev[i], -1);
	}
	G::solve(0);
	for (int i = 1; i <= n; i++) printf("%d ", G::dist[i]);
	return 0;
}