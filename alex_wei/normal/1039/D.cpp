#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, dn, dfn[N], p[N], fa[N], f[N], ans[N];
vector <int> e[N];
void dfs(int id, int f) {
	fa[id] = f, dfn[id] = ++dn;
	for(int it : e[id]) if(it != f) dfs(it, id);
}
int calc(int k) {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int mx = 0, mx2 = 0, id = p[i];
		for(int it : e[id]) if(it != fa[id])
			if(f[it] > mx) mx2 = mx, mx = f[it];
			else if(f[it] > mx2) mx2 = f[it];
		if(mx + mx2 + 1 >= k) ans++, f[id] = 0;
		else f[id] = mx + 1;
	}
	return ans;
}
int main() {
	for(int i = (cin >> n, 1), u, v; i < n; i++)
		cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	for(int i = 1; i <= n; i++) p[i] = i;
	dfs(1, 0), sort(p + 1, p + n + 1, [&](int u, int v) {return dfn[u] > dfn[v];});
	int B = sqrt(n);
	for(int i = 1; i <= B; i++) ans[i] = calc(i);
	for(int i = 0, lst = n; i <= B; i++) {
		int l = B + 1, r = lst + 1;
		while(l < r) {
			int m = l + r >> 1;
			if(calc(m) == i) r = m;
			else l = m + 1;
		}
		for(int j = l; j <= lst; j++) ans[j] = i;
		lst = l - 1;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
	return 0;
}