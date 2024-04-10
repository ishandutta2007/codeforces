#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 15005
int n;
int edge, to[N << 1], pr[N << 1], hd[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
int top, sta[N], vis[N], cnt, p[N], on[N], sz[N], f[N], sum[N << 1], dp[2][N], sf;
void find_cycle(int u, int fa = 0){
	sta[++top] = u, vis[u] = 2;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa)
			if (!vis[v]) find_cycle(v, u);
			else if (vis[v] == 2){
				int k = top;
				while (sta[k] != v) --k;
				for (register int j = k; j <= top; ++j) p[++cnt] = sta[j], on[sta[j]] = 1;
			}
	vis[u] = 1, --top;
}
void dfs(int u, int fa = 0){
	sz[u] = 1;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa && !on[v]) dfs(v, u), sz[u] += sz[v], f[u] += f[v];
	f[u] += sz[u];
}
int nxt(int i){ return (i % cnt) + 1; }
int uans;
void get_uans(int u, int sum, int fa = 0){
	uans = std :: max(uans, sum);
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa && !on[v]) get_uans(v, sum + n - 2 * sz[v], u);
}
int main(){
	n = read();
	for (register int i = 1, u, v; i <= n; ++i)
		u = read() + 1, v = read() + 1, addedge(u, v), addedge(v, u);
	find_cycle(1);
	for (register int i = 1; i <= cnt; ++i)
		dfs(p[i]), sum[i] = sum[i - 1] + (dp[0][i] = sz[p[i]]), sf += f[p[i]] - sz[p[i]];
	for (register int i = cnt + 1; i <= (cnt << 1); ++i)
		sum[i] = sum[i - 1] + sz[p[i - cnt]];
	for (register int len = 1; len <= cnt - 2; ++len){
		for (register int i = 1; i <= cnt; ++i)
			dp[len & 1][i] = std :: max(dp[!(len & 1)][nxt(i)], dp[!(len & 1)][i]) + sum[i + len] - sum[i - 1];
	}
	int ans = 0;
	for (register int i = 1; i <= cnt; ++i){
		uans = 0, get_uans(p[i], f[p[i]] - sz[p[i]] + n);
		ans = std :: max(ans, dp[(cnt - 2) & 1][nxt(i)] + sf - (f[p[i]] - sz[p[i]]) + uans);
	}
	printf("%d\n", ans);
}