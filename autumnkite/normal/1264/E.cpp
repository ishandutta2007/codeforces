#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 105;
int n, m, a[N][N], cnt, d[N];
struct node{
	int x, y;
}e[N * N];
struct Graph{
	const static int N = 5105, M = 100005, L = (1 << 13) - 1, INF = 0x3f3f3f3f;
	int S, T;
	int n, edge, to[M], cap[M], cost[M], pr[M], hd[N];
	void init(int _n){
		n = _n, edge = 0;
		for (register int i = 0; i < n; ++i) hd[i] = -1;
	}
	void addedge(int u, int v, int w, int c){
		to[edge] = v, cap[edge] = w, cost[edge] = c, pr[edge] = hd[u], hd[u] = edge++;
		to[edge] = u, cap[edge] = 0, cost[edge] = -c, pr[edge] = hd[v], hd[v] = edge++;
	}
	int h, t, Q[L + 1], vis[N], dis[N], mn[N], pre[N];
	void SPFA(){
		for (register int i = 0; i < n; ++i) dis[i] = INF, vis[i] = 0;
		h = 0, t = 1, Q[t] = S, dis[S] = 0, vis[S] = 1, mn[S] = INF;
		while (h != t){
			int u = Q[h = (h + 1) & L];
			vis[u] = 0;
			for (register int i = hd[u], v; ~i; i = pr[i])
				if (cap[i] && dis[v = to[i]] > dis[u] + cost[i]){
					dis[v] = dis[u] + cost[i], mn[v] = std :: min(mn[u], cap[i]), pre[v] = i;
					if (!vis[v]) Q[t = (t + 1) & L] = v, vis[v] = 1;
				}
		}
	}
	int MCMF(int _S, int _T){
		S = _S, T = _T;
		int Cost = 0;
		while (SPFA(), dis[T] != INF){
			Cost += mn[T] * dis[T];
			for (register int u = T; u != S; u = to[pre[u] ^ 1])
				cap[pre[u]] -= mn[T], cap[pre[u] ^ 1] += mn[T];
		}
		return Cost;
	}
}G;
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i)
		for (register int j = i + 1; j <= n; ++j)
			a[i][j] = a[j][i] = 2;
	for (register int i = 1, u, v; i <= m; ++i)
		u = read(), v = read(), a[u][v] = 1, a[v][u] = 0;
	for (register int i = 1; i <= n; ++i)
		for (register int j = i + 1; j <= n; ++j)
			if (a[i][j] == 2) e[++cnt] = (node){i, j};
			else if (a[i][j] == 1) ++d[j]; else ++d[i];
	G.init(cnt + n + 2);
	for (register int i = 1; i <= cnt; ++i)
		G.addedge(0, i, 1, 0), G.addedge(i, cnt + e[i].x, 1, 0), G.addedge(i, cnt + e[i].y, 1, 0);
	int ans = n * (n - 1) * (n - 2) / 6;
	for (register int i = 1; i <= n; ++i){
		ans -= d[i] * (d[i] - 1) / 2;
		for (register int j = d[i]; j < n - 1; ++j)
			G.addedge(cnt + i, cnt + n + 1, 1, j);
	}
	ans -= G.MCMF(0, cnt + n + 1);
	for (register int i = 1; i <= cnt; ++i)
		for (register int j = G.hd[i]; ~j; j = G.pr[j])
			if (G.to[j] && !G.cap[j]){
				if (G.to[j] == cnt + e[i].x) a[e[i].y][e[i].x] = 1, a[e[i].x][e[i].y] = 0;
				else a[e[i].x][e[i].y] = 1, a[e[i].y][e[i].x] = 0;
				break;
			}
	for (register int i = 1; i <= n; ++i){
		for (register int j = 1; j <= n; ++j) putchar(a[i][j] ^ '0');
		putchar('\n');
	}
}