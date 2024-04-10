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
#define N 500005
int n, k;
int edge, to[N << 1], pr[N << 1], tw[N << 1], hd[N];
void addedge(int u, int v, int w){
	to[++edge] = v, tw[edge] = w, pr[edge] = hd[u], hd[u] = edge;
}
int cnt;
long long dp[N][2], val[N];
void DP(int u, int fa = 0){
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa) DP(v, u);
	cnt = 0, dp[u][0] = 0;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa) dp[u][0] += dp[v][0], val[++cnt] = dp[v][0] - (dp[v][1] + tw[i]);
	dp[u][1] = dp[u][0], std :: sort(val + 1, val + 1 + cnt);
	for (register int i = 1; i <= k && i <= cnt; ++i)
		if (val[i] < 0) dp[u][0] -= val[i]; else break;
	for (register int i = 1; i < k && i <= cnt; ++i)
		if (val[i] < 0) dp[u][1] -= val[i]; else break;
}
void solve(){
	n = read(), k = read(), edge = 0;
	for (register int i = 1; i <= n; ++i) hd[i] = 0;
	for (register int i = 1, u, v, w; i < n; ++i)
		u = read(), v = read(), w = read(), addedge(u, v, w), addedge(v, u, w);
	DP(1);
	printf("%lld\n", dp[1][0]);
}
int main(){
	int T = read();
	while (T--) solve();
}