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
#define N 300005
int n, a[N], m, dp[N];
std :: vector<int> son[N];
void dfs(int u){
	if (son[u].empty()) return dp[u] = 1, void(0);
	if (a[u]) dp[u] = 1e9; else dp[u] = 0;
	for (auto v : son[u]){
		dfs(v);
		if (a[u]) dp[u] = std :: min(dp[u], dp[v]); else dp[u] += dp[v];
	}
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 2; i <= n; ++i) son[read()].push_back(i);
	for (register int i = 1; i <= n; ++i) m += son[i].empty();
	dfs(1);
	return printf("%d\n", m - dp[1] + 1), 0;
}