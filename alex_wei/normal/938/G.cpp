#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, q, fa[N], val[N], sz[N];
pair <int, int> qu[N];
map <int, int> mp[N];
struct edge {int u, v, d, l, r;} e[N << 1];
vector <edge> buc[N << 2];
void modify(int l, int r, int x, edge v) {
	if(v.l <= l && r <= v.r) return buc[x].push_back(v), void();
	int m = l + r >> 1;
	if(v.l <= m) modify(l, m, x << 1, v);
	if(m < v.r) modify(m + 1, r, x << 1 | 1, v);
}
struct Linear_Basis {
	int w[30];
	int query(int v) {for(int i = 29; ~i; i--) v = min(v, v ^ w[i]); return v;}
	void insert(int v) {for(int i = 29; ~i; i--) if(v >> i & 1) if(w[i]) v ^= w[i]; else {w[i] = v; break;}}
} lb[N << 2];
int find(int x) {return fa[x] == x ? x : find(fa[x]);} // DO NOT SQUEEZE THE PATH =.= 
int calc(int x) {return fa[x] == x ? 0 : (val[x] ^ calc(fa[x]));}
void query(int l, int r, int x) {
	vector <int> op;
	for(auto it : buc[x]) {
		int u = find(it.u), v = find(it.v), w = it.d ^ calc(it.u) ^ calc(it.v);
		if(u == v) lb[x].insert(w);
		else {
			if(sz[u] < sz[v]) swap(u, v);
			op.push_back(v), sz[u] += sz[v], fa[v] = u, val[v] = w;
		}
	}
	if(l == r) {if(qu[l].first) cout << lb[x].query(calc(qu[l].first) ^ calc(qu[l].second)) << "\n";} // DO NOT RETURN
	else {
		int m = l + r >> 1;
		lb[x << 1] = lb[x << 1 | 1] = lb[x];
		query(l, m, x << 1), query(m + 1, r, x << 1 | 1);
	}
	reverse(op.begin(), op.end()); // REMEMBER TO REVERSE 
	for(int it : op) sz[fa[it]] -= sz[it], fa[it] = it;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].d), e[i].l = 1;
		mp[e[i].u][e[i].v] = i;
	}
	cin >> q;
	for(int i = 1; i <= q; i++) {
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);
		if(op == 1) e[++m] = {x, y, 0, i, 0}, scanf("%d", &e[m].d), mp[x][y] = m;
		if(op == 2) e[mp[x][y]].r = i;
		if(op == 3) qu[i] = make_pair(x, y);
	}
	for(int i = 1; i <= m; i++) {if(!e[i].r) e[i].r = q; modify(1, q, 1, e[i]);}
	query(1, q, 1);
	return 0;
}

// fuck !