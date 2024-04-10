#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1005
int n, fa[N], sz[N], Mx, rt, now, a[N], w[N];
std :: vector<int> E[N], num[N], son;
void find_root(int u, int fa = 0){
	int mx = 0;
	sz[u] = 1;
	for (int v : E[u]) if (v != fa) find_root(v, u), sz[u] += sz[v], mx = std :: max(mx, sz[v]);
	mx = std :: max(mx, n - sz[u]);
	if (!rt || mx < Mx) Mx = mx, rt = u;
}
void get_sz(int u){
	sz[u] = 1;
	for (int v : E[u]) if (v != fa[u]) fa[v] = u, get_sz(v), sz[u] += sz[v];
}
void get_ans(int u){
	for (int v : E[u])
		if (v != fa[u]){
			w[v] = a[++now];
			for (register int i = now; i < now + sz[v]; ++i) a[i] -= w[v];
			get_ans(v);
		}
}
int main(){
	n = read();
	if (n == 1) return 0;
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), E[u].push_back(v), E[v].push_back(u);
	find_root(1);
	get_sz(rt);
	for (int v : E[rt]) num[sz[v]].push_back(v);
	for (register int i = 1; i <= n; ++i)
		for (int j : num[i]) son.push_back(j);
	for (register int i = 0; i < son.size(); ++i) E[rt][i] = son[i];
	int k = 0, sum = 0;
	for (register int i = 0; i < son.size(); ++i)
		if ((sum += sz[son[i]]) > n / 3){ k = i + 1; break; }
	for (register int i = 1; i <= sum; ++i) a[i] = i;
	for (register int i = sum + 1; i < n; ++i) a[i] = (i - sum) * (sum + 1);
	now = 0, get_ans(rt);
	for (register int i = 1; i <= n; ++i)
		if (rt != i) printf("%d %d %d\n", i, fa[i], w[i]);
}