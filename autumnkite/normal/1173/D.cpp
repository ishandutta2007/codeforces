#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
#define P 998244353
int n, fac[N], dp[N], sz[N];
int edge, to[N << 1], pr[N << 1], hd[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
void dfs(int u, int fa = 0){
	sz[u] = 1, dp[u] = 1;
	int d = 0;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa)
			dfs(v, u), sz[u] += sz[v], ++d, dp[u] = 1ll * dp[u] * dp[v] % P;
	if (!fa) dp[u] = 1ll * n * dp[u] % P * fac[d] % P;
	else dp[u] = 1ll * (d + 1) * dp[u] % P * fac[d] % P;
}
int main(){
	n = read();
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u);
	fac[0] = 1;
	for (register int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	dfs(1);
	printf("%d\n", dp[1]);
}