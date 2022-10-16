#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, node, R[N], c[N];
long long ans[N];
vector <int> e[N];
struct dat {
	int mx;
	long long val;
	dat operator + (dat x) {
		dat y = {0, 0};
		y.mx = max(mx, x.mx);
		y.val = (mx == y.mx ? val : 0) + (x.mx == y.mx ? x.val : 0);
		return y;
	}
} val[N << 5];
int ls[N << 5], rs[N << 5];
void modify(int l, int r, int p, int &x) {
	val[x = ++node] = {1, p};
	if(l == r) return;
	int m = l + r >> 1;
	if(p <= m) modify(l, m, p, ls[x]);
	else modify(m + 1, r, p, rs[x]);
}
int merge(int l, int r, int x, int y) {
	if(!x || !y) return x | y;
	if(l == r) return val[x] = {val[x].mx + val[y].mx, val[x].val}, x;
	int m = l + r >> 1;
	ls[x] = merge(l, m, ls[x], ls[y]), rs[x] = merge(m + 1, r, rs[x], rs[y]);
	return val[x] = val[ls[x]] + val[rs[x]], x;
}
void dfs(int id, int fa) {
	modify(1, n, c[id], R[id]);
	for(int it : e[id]) if(it != fa) dfs(it, id), R[id] = merge(1, n, R[id], R[it]);
	ans[id] = val[R[id]].val;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	dfs(1, 0);
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}