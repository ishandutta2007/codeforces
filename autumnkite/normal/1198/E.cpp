#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define INF 0x3f3f3f3f
struct Network{
	static const int N = 205, M = 20005;
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
#define N 105
int n, m, cx, dx[N], cy, dy[N], bl[N][N];
int x1[N], y1[N], x2[N], y2[N];
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= m; ++i)
		x1[i] = read() - 1, y1[i] = read() - 1, x2[i] = read(), y2[i] = read(),
		dx[cx++] = x1[i], dx[cx++] = x2[i], dy[cy++] = y1[i], dy[cy++] = y2[i];
	std :: sort(dx, dx + cx);
	cx = std :: unique(dx, dx + cx) - dx;
	std :: sort(dy, dy + cy);
	cy = std :: unique(dy, dy + cy) - dy;
	G.S = 0, G.T = cx + cy - 1;
	for (register int i = 1; i < cx; ++i) G.addedge(G.S, i, dx[i] - dx[i - 1]);
	for (register int i = 1; i < cy; ++i) G.addedge(cx + i - 1, G.T, dy[i] - dy[i - 1]);
	for (register int k = 1; k <= m; ++k){
		int X1 = std :: upper_bound(dx, dx + cx, x1[k]) - dx;
		int Y1 = std :: upper_bound(dy, dy + cy, y1[k]) - dy;
		int X2 = std :: lower_bound(dx, dx + cx, x2[k]) - dx;
		int Y2 = std :: lower_bound(dy, dy + cy, y2[k]) - dy;
		for (register int i = X1; i <= X2; ++i)
			for (register int j = Y1; j <= Y2; ++j)
				bl[i][j] = 1;
	}
	for (register int i = 1; i < cx; ++i)
		for (register int j = 1; j < cy; ++j)
			if (bl[i][j]) G.addedge(i, cx + j - 1, INF);
	printf("%d\n", G.dinic());
}