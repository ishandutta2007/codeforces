#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, K = 17;
int n, m, dep[N], fa[K][N];
int anc(int x, int k) {for(int i = 16; ~i; i--) if(k >> i & 1) x = fa[i][x]; return x;}
vector <int> e[N];
int node, R[N], ls[N << 6], rs[N << 6], val[N << 6];
void modify(int l, int r, int p, int &x) {
	val[x = ++node] = 1;
	if(l == r) return;
	int m = l + r >> 1;
	if(p <= m) modify(l, m, p, ls[x]);
	else modify(m + 1, r, p, rs[x]);
}
int query(int l, int r, int p, int x) {
	if(l == r) return val[x];
	int m = l + r >> 1;
	if(p <= m) return query(l, m, p, ls[x]);
	return query(m + 1, r, p, rs[x]); 
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	int z = ++node;
	ls[z] = merge(ls[x], ls[y]), rs[z] = merge(rs[x], rs[y]);
	return val[z] = val[x] + val[y], z;
}
void dfs(int id) {
	modify(1, N, dep[id] = dep[fa[0][id]] + 1, R[id]);
	for(int i = 1; i < K; i++) fa[i][id] = fa[i - 1][fa[i - 1][id]];
	for(int it : e[id]) dfs(it), R[id] = merge(R[id], R[it]);
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> fa[0][i], e[fa[0][i]].push_back(i);
	dfs(0), cin >> m;
	for(int i = 1, p, v; i <= m; i++) {
		cin >> p >> v, p = anc(p, v);
		cout << (p ? query(1, N, dep[p] + v, R[p]) - 1 : 0) << " ";
	}
	return 0;
}