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
#define N 200005
int n, m, a[N], x[N], y[N], rt;
std :: vector<int> E[N];
int idx, dfn[N], low[N], top, sta[N], vis[N], cnt, sz[N], col[N];
long long val[N];
void tarjan(int u, int fa){
	dfn[u] = low[u] = ++idx, sta[++top] = u, vis[u] = 1;
	for (int v : E[u])
		if (v != fa)
			if (!vis[v]) tarjan(v, u), low[u] = std :: min(low[u], low[v]);
			else low[u] = std :: min(low[u], dfn[v]);
	if (low[u] == dfn[u]){
		++cnt, sta[top + 1] = -1;
		while (sta[top + 1] != u) col[sta[top]] = cnt, val[cnt] += a[sta[top]], ++sz[cnt], vis[sta[top--]] = 0;
	}
}
bool ok[N];
long long dp[N][2];
void dfs(int u, int fa = 0){
	long long sum = 0;
	ok[u] = sz[u] > 1;
	for (int v : E[u]) if (v != fa) dfs(v, u), ok[u] |= ok[v], sum += dp[v][0];
	for (int v : E[u]) if (v != fa) dp[u][1] = std :: max(dp[u][1], dp[v][1] + sum - dp[v][0]);
	dp[u][1] += val[u];
	if (ok[u]) dp[u][0] = sum + val[u];
}
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 1; i <= m; ++i)
		x[i] = read(), y[i] = read(), E[x[i]].push_back(y[i]), E[y[i]].push_back(x[i]);
	for (register int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i, 0);
	for (register int i = 1; i <= n; ++i) E[i].clear();
	for (register int i = 1; i <= m; ++i)
		if (col[x[i]] != col[y[i]]) E[col[x[i]]].push_back(col[y[i]]), E[col[y[i]]].push_back(col[x[i]]);
	rt = col[read()];
	dfs(rt);
	printf("%lld\n", dp[rt][1]);
}