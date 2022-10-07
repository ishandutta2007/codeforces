#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
#include <cassert>
const int N = 1005;
int n;
std::set<int> E[N];
std::set<std::pair<int, int>> S;
int LCA(int u, int v){
	printf("? %d %d\n", u, v), fflush(stdout);
	scanf("%d", &u);
	return u;
}
void Ans(int ans){
	printf("! %d\n", ans), fflush(stdout);
}
int fa[N];
void dfs(int u){
	for (int v : E[u]) if (v != fa[u]) fa[v] = u, dfs(v);
}
void erase(int u, int v){
	S.erase({E[u].size(), u}), E[u].erase(v), S.insert({E[u].size(), u});
}
void solve(){
	scanf("%d", &n);
	for (register int i = 1, u, v; i < n; ++i)
		scanf("%d%d", &u, &v), E[u].insert(v), E[v].insert(u);
	for (register int i = 1; i <= n; ++i)
		S.insert({E[i].size(), i});
	while (S.size() > 1){
		int u, v;
		u = S.begin()->second, S.erase(S.begin());
		v = S.begin()->second, S.erase(S.begin());
		int w = LCA(u, v);
		if (w == u || w == v) return Ans(w), void(0);
		fa[w] = 0, dfs(w);
		erase(fa[u], u), erase(fa[v], v), E[u].clear(), E[v].clear();
	}
	if (S.size() == 1) return Ans(S.begin()->second), void(0);
}
int main(){
	int T = 1;
	// read(T);
	while (T--) solve();
}