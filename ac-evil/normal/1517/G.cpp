#include <bits/stdc++.h>
#define fi first
#define se second
using std::min;
typedef long long ll;
const int N = 1e3 + 5;
const ll INF = 1e18;
template<int N, int M>
class graph {
private:
	struct edge { int u, v, nxt; ll f, c; } e[M * 2];
	int edges, G[N], n, s, t;
	int d[N]; std::queue<int> Q;
	bool bfs() {
		std::fill(d + 1, d + n + 1, -1);
		d[t] = 1e9; Q.push(t);
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			for (int i = G[u]; ~i; i = e[i].nxt) {
				int v = e[i].v;
				if (e[i ^ 1].f < e[i ^ 1].c && d[v] == -1) {
					d[v] = d[u] - 1;
					Q.push(v);
				}
			}
		}
		return ~d[s];
	}
	int cur[N];
	ll dfs(int u, ll a) {
		if (u == t || !a) return a;
		ll flow = 0, f;
		for (int &i = cur[u]; ~i; i = e[i].nxt) {
			edge &now = e[i];
			if (d[u] + 1 == d[now.v] && (f = dfs(now.v, min(a, now.c - now.f)))) {
				flow += f; now.f += f;
				a -= f; e[i ^ 1].f -= f;
				if (!a) break;
			}
		}
		return flow;
	}
public:
	void init(int n) {
		this->n = n; edges = 0;
		std::fill(G + 1, G + n + 1, -1);
	}
	void add(int u, int v, ll c) {
		e[edges] = {u, v, G[u], 0, c}, G[u] = edges++;
		e[edges] = {v, u, G[v], 0, 0}, G[v] = edges++;
	}
	ll dinic(int s, int t) {
		this->s = s, this->t = t;
		ll flow = 0;
		while (bfs()) {
			for (int i = 1; i <= n; i++) cur[i] = G[i];
			flow += dfs(s, INF);
		}
		return flow;
	}
};
graph<N * 2, N * 10> G;
int n; ll ans = 0;
std::map<std::pair<int, int>, std::pair<int, int>> A;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		A[{x, y}] = {w, i}; ans += w;
	}
	G.init(n * 2 + 2);
	int S = n * 2 + 1, T = n * 2 + 2;
	for (auto tmp : A) {
		int x = tmp.fi.fi, y = tmp.fi.se, w = tmp.se.fi, id = tmp.se.se, to;
		int tx = x & 1, ty = y & 1;
		G.add(id, id + n, w);
		if (!(tx ^ ty)) {
			auto it = A.find({x - 1, y});
			if (it != A.end()) {
				to = it->se.se;
				G.add(id + n, to, INF);
			}
			it = A.find({x + 1, y});
			if (it != A.end()) {
				to = it->se.se;
				G.add(id + n, to, INF);
			}
			if (tx == 1 && ty == 1) G.add(S, id, INF);
		}
		else if (tx == 0) {
			auto it = A.find({x, y - 1});
			if (it != A.end()) {
				to = it->se.se;
				G.add(id + n, to, INF);
			}
			it = A.find({x, y + 1});
			if (it != A.end()) {
				to = it->se.se;
				G.add(id + n, to, INF);
			}
		} else G.add(id + n, T, INF);
	}
	ans -= G.dinic(S, T);
	printf("%lld\n", ans);
	return 0;
}