#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, cur, dep[N], mxd[N], son[N], fa[N];
int mx[N], ans[N], buf[N], *f[N];
vector <int> e[N];
void dfs1(int id, int f) {
	dep[id] = dep[f] + 1, fa[id] = f;
	for(int it : e[id]) if(it != f) {
		dfs1(it, id), mxd[id] = max(mxd[id], mxd[it] + 1);
		if(mxd[it] > mxd[son[id]]) son[id] = it;
	}
}
void dfs2(int id) {
	if(son[id]) f[son[id]] = f[id] + 1, dfs2(son[id]), mx[id] = mx[son[id]], ans[id] = ans[son[id]] + 1;
	for(int it : e[id]) {
		if(it == fa[id] || it == son[id]) continue;
		f[it] = buf + cur, cur += mxd[it] + 1, dfs2(it);
		for(int i = 1; i <= mxd[it] + 1; i++) {
			f[id][i] += f[it][i - 1];
			if(f[id][i] > mx[id] || f[id][i] == mx[id] && ans[id] > i) mx[id] = f[id][i], ans[id] = i;
		}
	} f[id][0] = 1;
	if(mx[id] <= 1) mx[id] = 1, ans[id] = 0;
}
int main() {
	cin >> n, mxd[0] = -1;
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		e[u].push_back(v), e[v].push_back(u);
	} dfs1(1, 0), f[1] = buf, cur += mxd[1] + 1, dfs2(1);
	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}