#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, f[N], g[N], ans, bot[N], nxt[N];
vector<int> G[N];
void dfs1(int u, int lst) {
	vector<int> vec;
	for (int v : G[u]) if (v != lst) {
		dfs1(v, u);
		vec.push_back(f[v]);
	}
	sort(vec.rbegin(), vec.rend());
	f[u] = 1;
	for (int i = 0; i < (int)vec.size(); i++) f[u] = max(f[u], vec[i] + i);
}
void dfs2(int u, int lst) {
	vector<pair<int, int> > vec;
	for (int v : G[u]) if (v != lst) vec.emplace_back(f[v], v);
	if (lst) vec.emplace_back(g[u], lst);
	sort(vec.rbegin(), vec.rend());
	vector<int> ps(vec.size() + 1), ss(vec.size() + 1);
	ps[0] = 1;
	ss[vec.size()] = 0;
	for (int i = 0; i < (int)vec.size(); i++) ps[i + 1] = max(ps[i], vec[i].first + i);
	for (int i = (int)vec.size() - 1; i >= 0; i--) ss[i] = max(ss[i + 1], vec[i].first + i - 1);
	ans = max(ans, vec[0].first + ss[1]);
	for (int i = 0; i < (int)vec.size(); i++) {
		int v = vec[i].second;
		if (v == lst) continue;
		g[v] = max(ps[i], ss[i + 1]);
		dfs2(v, u);
	}
}
void dfs3(int u, int lst) {
	for (int i = 0; i < (int)G[u].size(); i++) if (G[u][i] == lst) {
		swap(G[u][i], G[u].back());
		G[u].pop_back();
		break;
	}
	for (int v : G[u]) {
		dfs3(v, u);
	}
	sort(G[u].begin(), G[u].end(), [](int x, int y) {
		return f[x] > f[y];
	});
	f[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++) f[u] = max(f[u], f[G[u][i]] + i);
	if (G[u].size()) {
		nxt[u] = G[u][0];
		bot[u] = bot[nxt[u]];
	} else {
		nxt[u] = bot[u] = u;
	}
}
inline int Query(int u) {
	printf("? %d\n", u);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}
int Find(int u, int r) {
	while (u != r) u = nxt[u];
	for (int i = 1; i < (int)G[u].size(); i++) {
		int v = G[u][i];
		int w = Query(bot[v]);
		if (w != u) return Find(v, w);
	}
	return u;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (n == 1) {
		puts("0");
		fflush(stdout);
		scanf("%*d");
		puts("! 1 1");
		return 0;
	}
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%d\n", ans);
	fflush(stdout);
	int rt;
	scanf("%d", &rt);
	dfs3(rt, 0);
	int a1 = rt, a2 = rt;
	for (int i = 0; i < (int)G[rt].size(); i++) {
		int v = G[rt][i];
		int w = Query(bot[v]);
		if (w == rt) continue;
		int cur = Find(v, w);
		if (a1 == rt) {
			a1 = cur;
		} else {
			a2 = cur;
			break;
		}
	}
	printf("! %d %d\n", a1, a2);
	return 0;
}