#include <bits/stdc++.h>
using std::vector; using std::queue;
typedef long long LL;
const int N = 300005;
int n, m, x, a[N], fa[N], vis[N], tot = 0; LL w[N];
int fset(int x) { return fa[x] == x ? x : fa[x] = fset(fa[x]); }
struct Node { int x, y; };
struct Edges { int u, v, id; };
vector<Node> G[N];
vector<Edges> H;
vector<int> ans;
queue<int> Q;
int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back({v, i}), G[v].push_back({u, i});
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i, w[i] = a[i];
		if (w[i] >= x) Q.push(i);
	}
	while (!Q.empty()) {
		int u = fset(Q.front()); Q.pop();
		if (w[u] < x) continue;
		for (int i = (int)G[u].size() - 1; ~i; i--) {
			int v = fset(G[u][i].x);
			// printf("%d %d\n", u, v);
			if (u == v) G[u].pop_back();
			else {
				ans.push_back(G[u][i].y);
				if (G[u].size() < G[v].size()) {
					for (int j = 0; j < G[u].size(); j++) G[v].push_back(G[u][j]);
					fa[u] = v; w[v] += w[u] - x; Q.push(v);
				} else {
					for (int j = 0; j < G[v].size(); j++) G[u].push_back(G[v][j]);
					fa[v] = u; w[u] += w[v] - x; Q.push(u);
				}
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int f = fset(i);
		if (vis[f]) continue;
		vis[f] = 1;
		for (int j = 0; j < G[f].size(); j++)
			H.push_back({f, G[f][j].x, G[f][j].y});
	}
	for (int i = 0; i < H.size(); i++) {
		int u = fset(H[i].u), v = fset(H[i].v);
		if (u == v) continue;
		if (w[u] + w[v] >= x) {
			fa[v] = u; w[u] += w[v] - x;
			ans.push_back(H[i].id);
		}
	}
	// for (int i = 1; i <= n; i++) printf("(%d,%lld)", fset(i), w[i]);
	if (ans.size() < n - 1) { puts("NO"); return 0; }
	puts("YES");
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}