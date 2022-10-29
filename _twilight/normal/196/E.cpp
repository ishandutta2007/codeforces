#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

typedef class Edge {
	public:
		int u, v;
		ll w;

		Edge() {	}
		Edge(int u, int v, ll w) : u(u), v(v), w(w)	{	}

		void read() {
			scanf("%d%d%lld", &u, &v, &w);
		}
		boolean operator < (Edge b) const {
			return w < b.w;
		}
} Edge;

typedef class Node {
	public:
		int p;
		ll d;
		int org;

		Node(int p, ll d, int org) : p(p), d(d), org(org) {	}

		boolean operator < (Node b) const {
			return d > b.d;
		}
} Node;

#define pii pair<int, int>

const ll llf = (~0ull >> 2);

const int N = 1e5 + 5;

int n, m;
boolean iskey[N];
vector<pii> G[N];
vector<Edge> E, E0;

ll f[N];
int g[N];
void dijkstra() {
	priority_queue<Node> Q;
	for (int i = 1; i <= n; i++) {
		if (iskey[i]) {
			Q.push(Node(i, f[i] = 0, g[i] = i));
		} else {
			f[i] = llf;
		}
	}
	while (!Q.empty()) {
		Node e = Q.top();
		Q.pop();
		if (e.d ^ f[e.p])
			continue;
		for (auto _ : G[e.p]) {
			int q = _.first;
			int w = _.second;
			if (f[e.p] + w < f[q]) {
				Q.push(Node(q, f[q] = f[e.p] + w, g[q] = e.org));
			}
		}
	}
}

int uf[N];
int find(int x) {
	return uf[x] == x ? (x) : (uf[x] = find(uf[x]));
}
ll kruskal() {
	for (int i = 1; i <= n; i++)
		uf[i] = i;
	sort(E.begin(), E.end());
	ll ret = 0;
	for (auto e : E) {
		int u = find(e.u), v = find(e.v);
		if (u ^ v) {
			uf[u] = v;
			ret += e.w;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	E0.resize(m);
	for (int i = 0; i < m; i++) {
		E0[i].read();
		G[E0[i].u].emplace_back(E0[i].v, (int) E0[i].w);
		G[E0[i].v].emplace_back(E0[i].u, (int) E0[i].w);
	}
	int cnt, x;
	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%d", &x);
		iskey[x] = true;
	}
	dijkstra();
	for (auto e : E0) {
		if (g[e.u] ^ g[e.v]) {
			E.emplace_back(g[e.u], g[e.v], f[e.u] + f[e.v] + e.w);
		}
	}
	ll ans = kruskal() + f[1];
	printf("%lld\n", ans);
	return 0;
}