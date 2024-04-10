#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 205
#define M 100005
#define INF 0x3f3f3f3f
int n, a[N];
int cnt, p[20005], vis[20005];
struct Network{
	int S, T, edge, to[M], cap[M], pr[M], hd[N], nhd[N];
	Network(){ edge = 0, memset(hd, -1, sizeof hd); }
	void addedge(int u, int v, int w){
		to[edge] = v, pr[edge] = hd[u], cap[edge] = w, hd[u] = edge++;
		to[edge] = u, pr[edge] = hd[v], cap[edge] = 0, hd[v] = edge++;
	}
	int h, t, Q[N], dep[N];
	int dfs(int u, int flow){
		if (u == T | !flow) return flow;
		int ans = 0;
		for (register int i = nhd[u], v, tmp; ~i; nhd[u] = i = pr[i])
			if (dep[v = to[i]] == dep[u] + 1 && (tmp = dfs(v, std :: min(flow, cap[i])))){
				ans += tmp, flow -= tmp, cap[i] -= tmp, cap[i ^ 1] += tmp;
				if (!flow) break;
			}
		if (!ans) dep[u] = -1;
		return ans;
	}
	bool bfs(){
		memset(dep, -1, sizeof dep);
		h = 0, t = 1, Q[t] = S, dep[S] = 0;
		while (h < t){
			int u = Q[++h];
			for (register int i = hd[u], v; ~i; i = pr[i])
				if (dep[v = to[i]] == -1 && cap[i]){
					Q[++t] = v, dep[v] = dep[u] + 1;
					if (v == T) return 1;
				}
		}
		return 0;
	}
	int dinic(){
		int ans = 0;
		while (bfs()) memcpy(nhd, hd, sizeof nhd), ans += dfs(S, INF);
		return ans;
	}
}G;
void pre(int n){
	vis[1] = 1;
	for (register int i = 2; i <= n; ++i){
		if (!vis[i]) p[++cnt] = i;
		for (register int j = 1; j <= cnt && i * p[j] <= n; ++j){
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
struct Answer{
	int edge, to[N << 1], pr[N << 1], hd[N], vis[N], s;
	std :: vector<int> c[N];
	void addedge(int u, int v){
		to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
		to[++edge] = u, pr[edge] = hd[v], hd[v] = edge;
	}
	void dfs(int u){
		vis[u] = 1, c[s].push_back(u);
		for (register int i = hd[u]; i; i = pr[i])
			if (!vis[to[i]]) dfs(to[i]);
	}
	void find(){
		for (register int i = 1; i <= n; ++i)
			if (!vis[i]) ++s, dfs(i);
	}
}H;
int main(){
	scanf("%d", &n);
	int m = 0;
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i), m = std :: max(m, a[i]);
	pre(m << 1);
	G.S = 0, G.T = n + 1;
	for (register int i = 1; i <= n; ++i)
		if (a[i] & 1){
			G.addedge(G.S, i, 2);
			for (register int j = 1; j <= n; ++j)
				if (!vis[a[i] + a[j]]) G.addedge(i, j, 1);
		}
		else G.addedge(i, G.T, 2);
	if (G.dinic() < n) return printf("Impossible"), 0;
	for (register int i = 1; i <= n; ++i)
		if (a[i] & 1)
			for (register int j = G.hd[i]; ~j; j = G.pr[j])
				if (!G.cap[j] && G.to[j] != G.S && G.to[j] != G.T) H.addedge(i, G.to[j]);
	H.find();
	printf("%d\n", H.s);
	for (register int i = 1; i <= H.s; ++i){
		printf("%d ", H.c[i].size());
		for (register int j = 0; j < H.c[i].size(); ++j) printf("%d ", H.c[i][j]);
		putchar('\n');
	}
}