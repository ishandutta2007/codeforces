#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 200005;
int n, sz[N];
long long ans1, ans2;
std::vector< std::pair<int, int> > E[N];
int dfs1(int u, int fa = 0){
	int s = 1;
	sz[u] = 1;
	for (auto [v, w] : E[u])
		if (v != fa){
			int t = dfs1(v, u);
			sz[u] += sz[v], s += t, ans1 += 1ll * w * t;
		}
	return s & 1;
}
int dfs2(int u, int fa = 0){
	int s = 1;
	for (auto [v, w] : E[u])
		if (v != fa){
			int t = dfs2(v, u);
			s += t, ans2 += 1ll * w * t;
		}
	return std::min(n - sz[u], s);
}
void solve(){
	scanf("%d", &n), n <<= 1;
	for (register int i = 1; i <= n; ++i) E[i].clear();
	for (register int i = 1, u, v, w; i < n; ++i)
		scanf("%d%d%d", &u, &v, &w), E[u].push_back({v, w}), E[v].push_back({u, w});
	ans1 = 0, dfs1(1);
	printf("%lld ", ans1);
	ans2 = 0, dfs2(1);
	printf("%lld\n", ans2);
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) solve();
}