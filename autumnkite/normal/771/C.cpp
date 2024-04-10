#include <cstdio>
#include <cctype>
#define int long long
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, k;
int edge, to[N << 1], pr[N << 1], hd[N];
long long ans;
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
int dp[N][10], Dp[N], sz[N];
void dfs(int u, int fa = 0){
	sz[u] = 1, dp[u][0] = 1;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa){
			dfs(v, u);
			ans += 1ll * sz[u] * Dp[v] + 1ll * sz[v] * Dp[u];
			ans += 1ll * sz[u] * sz[v] - 1ll * dp[u][0] * dp[v][0];
			for (register int j = 0, x = sz[u], y = 0; j < k; ++j){
				if (j > 1) y = dp[v][k - j + 1];
				ans += 1ll * x * y;
				x -= dp[u][j];
			}
			Dp[u] += Dp[v], sz[u] += sz[v];
			for (register int j = 0; j < k; ++j) dp[u][j] += dp[v][j];
		}
	for (register int i = k; i; --i) dp[u][i] = dp[u][i - 1];
	dp[u][0] = dp[u][k], Dp[u] += dp[u][0], dp[u][k] = 0;
}
signed main(){
	n = read(), k = read();
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u);
	dfs((n - 1) % 1752 + 1);
	printf("%lld", ans);
}