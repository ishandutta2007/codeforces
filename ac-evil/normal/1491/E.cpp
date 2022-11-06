#include <bits/stdc++.h>
using std::min; using std::max; using std::vector;
typedef long long LL;
const int N = 200005;
int n, f[30];
struct Edge { int v, nxt; } e[N * 2];
int edges = 0, G[N];
void adde(int u, int v) {
	e[edges++] = (Edge){v, G[u]}; G[u] = edges - 1;
}
int fa[N], sz[N], vis[N];
void dfs(int u, int f, vector<int> &lst) {
	fa[u] = f; sz[u] = 1; lst.push_back(u);
	for (int i = G[u]; ~i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == f || vis[v]) continue;
		dfs(v, u, lst);
		sz[u] += sz[v];
	}
}
bool solve(int dep, int u) {
	if (dep <= 3) return true;
	//printf("%d %d\n", dep, u);
	vector<int> lst;
	dfs(u, 0, lst);
	int ans = 1;
	for (int i = 0; i < lst.size(); i++) {
		if (sz[lst[i]] == f[dep - 1]) {
			//printf("[%d]\n", lst[i]);
			int f = fa[lst[i]];
			vis[lst[i]] = 1;
			ans &= solve(dep - 2, f);
			vis[lst[i]] = 0;
			vis[f] = 1;
			return ans & solve(dep - 1, lst[i]);
		}
		else if (sz[lst[i]] == f[dep - 2]) {
			//printf("(%d)\n", lst[i]);
			int f = fa[lst[i]];
			vis[f] = 1;
			ans &= solve(dep - 2, lst[i]);
			vis[f] = 0;
			vis[lst[i]] = 1;
			//printf("(%d)\n", lst[i]);
			return ans & solve(dep - 1, f);
		}
	}
	return false;
}
int main() {
	//freopen("ques.in", "r", stdin);
	scanf("%d", &n);
	memset(G, -1, sizeof G);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	f[0] = f[1] = 1;
	for (int i = 2; i < 30; i++) f[i] = f[i - 1] + f[i - 2];
	int ok = 0;
	for (int i = 1; i < 30; i++)
		if (n == f[i]) { ok = 1; n = i; break; }
	if (!ok) { puts("NO"); return 0; }
	else printf("%s\n", solve(n, 1) ? "YES" : "NO");
	return 0;
}