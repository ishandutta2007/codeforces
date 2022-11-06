#include <bits/stdc++.h>
typedef long long LL;
using std::max; using std::min;
const int N = 400005;
int n, m, u[N], v[N], w[N];
LL ans[N];
struct Edge {
	int u, v, w, nxt;
} e[N*10];
int edges = 0, G[N*3];
void clear() {
	memset(G, -1, sizeof G); edges = 0;
}
void adde(int u, int v, int w) {
	e[edges++] = (Edge){u, v, w, G[u]}; G[u] = edges-1;
}
struct Node {
	LL dis, id;
	bool operator < (const Node &rhs) const {
		return dis > rhs.dis;
	}
};
LL dis[N*3]; bool vis[N*3];
void dijkstra() {
	std::priority_queue<Node> Q;
	memset(dis, 0x3f, sizeof dis); memset(vis, 0, sizeof vis);
	dis[1] = 0;
	Q.push((Node){0, 1});
	while (!Q.empty()) {
		int u = Q.top().id; Q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = G[u]; ~i; i = e[i].nxt)
			if (dis[u] + e[i].w < dis[e[i].v]) {
				dis[e[i].v] = dis[u] + e[i].w;
				Q.push((Node){dis[e[i].v], e[i].v});
			}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	memset(ans, 0x3f, sizeof ans);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		if (u[i] == 1) ans[v[i]] = min(ans[v[i]], (LL)w[i]);
		if (v[i] == 1) ans[u[i]] = min(ans[u[i]], (LL)w[i]);
	}
	clear();
	for (int i = 1; i <= m; i++) {
		adde(u[i], v[i], w[i]); adde(v[i], u[i], w[i]);
		adde(u[i]+n, v[i]+n, w[i]); adde(v[i]+n, u[i]+n, w[i]);
		adde(u[i]+n*2, v[i]+n*2, w[i]); adde(v[i]+n*2, u[i]+n*2, w[i]);
		adde(u[i], v[i]+n, 2*w[i]); adde(v[i], u[i]+n, 2*w[i]);
		adde(u[i]+n, v[i]+2*n, 0), adde(v[i]+n, u[i]+2*n, 0);
	}
	dijkstra();
	for (int i = 1; i <= n; i++) ans[i] = min(ans[i], dis[n*2+i]);

	//for (int i = 2; i <= n; i++) printf("%lld ", ans[i]); puts("");

	clear();
	for (int i = 1; i <= m; i++) {
		adde(u[i], v[i], w[i]); adde(v[i], u[i], w[i]);
		adde(u[i]+n, v[i]+n, w[i]); adde(v[i]+n, u[i]+n, w[i]);
		adde(u[i]+n*2, v[i]+n*2, w[i]); adde(v[i]+n*2, u[i]+n*2, w[i]);
		adde(u[i], v[i]+n, 0); adde(v[i], u[i]+n, 0);
		adde(u[i]+n, v[i]+2*n, 2*w[i]), adde(v[i]+n, u[i]+2*n, 2*w[i]);
	}
	dijkstra();
	for (int i = 2; i <= n; i++) printf("%lld ", min(ans[i], dis[n*2+i]));
	return 0;
}