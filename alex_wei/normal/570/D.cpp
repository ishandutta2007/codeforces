#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, K = N * 20;
char s[N];
vector <int> e[N];
vector <pair <int, int>> q[N];
int n, m, ans[N], dep[N], fa[N];
int node, R[N], ls[K], rs[K], val[K];
void modify(int l, int r, int p, int &x, int v) {
	val[x = ++node] = v;
	if(l == r) return;
	int m = l + r >> 1;
	if(p <= m) modify(l, m, p, ls[x], v);
	else modify(m + 1, r, p, rs[x], v);
}
int query(int p, int x) {
	int l = 1, r = n;
	while(l < r) {
		int m = l + r >> 1;
		if(p <= m) x = ls[x], r = m;
		else x = rs[x], l = m + 1;
	}
	return val[x];
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	ls[x] = merge(ls[x], ls[y]), rs[x] = merge(rs[x], rs[y]);
	return val[x] ^= val[y], x;
}
void dfs(int id) {
	modify(1, n, dep[id] = dep[fa[id]] + 1, R[id], 1 << s[id] - 'a');
	for(int it : e[id]) dfs(it), R[id] = merge(R[id], R[it]);
	for(auto it : q[id]) ans[it.second] = __builtin_popcount(query(it.first, R[id])) < 2;
}
int main() {
	cin >> n >> m;
	for(int i = 2; i <= n; i++) scanf("%d", &fa[i]), e[fa[i]].push_back(i);
	cin >> s + 1;
	for(int i = 1, v, h; i <= m; i++) scanf("%d %d", &v, &h), q[v].push_back({h, i});
	dfs(1);
	for(int i = 1; i <= m; i++) puts(ans[i] ? "Yes" : "No");
	return 0;
}