#include <cstdio>
#include <vector>
#include <algorithm>
#define N 200005
int n;
std :: vector<int> E[N];
int sz[N];
long long ans;
void dfs(int u, int fa = 0){
	sz[u] = 1;
	for (auto v : E[u]) if (v != fa) dfs(v, u), sz[u] += sz[v];
}
void Dfs(int u, long long s, int fa = 0){
	ans = std :: max(ans, s);
	for (auto v : E[u]) if (v != fa) Dfs(v, s + n - 2 * sz[v], u);
}
int main(){
	scanf("%d", &n);
	for (register int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v), E[u].push_back(v), E[v].push_back(u);
	dfs(1);
	long long s = 0;
	for (register int i = 1; i <= n; ++i) s += sz[i];
	Dfs(1, s);
	printf("%lld", ans);
}