#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, m, cnt, tot;
struct node{
	int u, v, t, k;
	bool operator < (const node &rhs) const {
		return u < rhs.u || (u == rhs.u && v < rhs.v) || (u == rhs.u && v == rhs.v && t < rhs.t);
	}
}a[N << 1];
struct edge{
	int u, v;
}q[N], e[N << 1];
bool vis[N << 1];
int E[N][2];
struct DSU{
	int fa[N], dep[N], tp, sta[N], stad[N];
	void init(int n){
		for (register int i = 1; i <= n; ++i) fa[i] = i, dep[i] = 1;
		tp = 0;
	}
	int find(int x){
		return fa[x] == x ? x : find(fa[x]);
	}
	void merge(int x, int y){
		x = find(x), y = find(y);
		if (dep[x] < dep[y]) std :: swap(x, y);
		if (x == y) return;
		sta[++tp] = y;
		if (dep[y] == dep[x]) stad[tp] = 1, ++dep[x];
		else stad[tp] = 0;
		fa[y] = x;
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
	void undo(){
		int y = sta[tp], x = fa[y], d = stad[tp];
		--tp, dep[x] -= d, fa[y] = y;
	}
}D;
struct Segment_Tree{
	std :: vector<int> a[N << 2];
	void modify(int u, int l, int r, int L, int R, int x){
		if (L <= l && r <= R) return a[u].push_back(x), void(0);
		int md = (l + r) >> 1;
		if (L <= md) modify(u << 1, l, md, L, R, x);
		if (R > md) modify(u << 1 | 1, md + 1, r, L, R, x);
	}
	void solve(int u, int l, int r){
		static int lastans = 0;
		int now = D.tp;
		for (int i : a[u]) if (vis[i]) D.merge(e[i].u, e[i].v);
		if (l == r){
			if (q[l].u){
				int x = (q[l].u + lastans - 1) % n + 1, y = (q[l].v + lastans - 1) % n + 1;
				putchar((lastans = D.same(x, y)) ^ '0');
			}
			else vis[E[l][lastans]] ^= 1;
		}
		else{
			int md = (l + r) >> 1;
			solve(u << 1, l, md), solve(u << 1 | 1, md + 1, r);
		}
		while (D.tp > now) D.undo();
	}
}T;
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= m; ++i){
		int opt = read(), x = read(), y = read();
		if (opt == 2) q[i] = (edge){x, y};
		else{
			x > y ? std :: swap(x, y), 0 : 0, a[++cnt] = (node){x, y, i, 0};
			x %= n, y %= n, ++x, ++y;
			x > y ? std :: swap(x, y), 0 : 0, a[++cnt] = (node){x, y, i, 1};
		}
	}
	std :: sort(a + 1, a + 1 + cnt);
	for (register int i = 1; i <= cnt; ++i){
		if (a[i].u == a[i - 1].u && a[i].v == a[i - 1].v) T.modify(1, 1, m + 1, a[i - 1].t + 1, a[i].t, tot);
		else T.modify(1, 1, m + 1, a[i - 1].t + 1, m + 1, tot), e[++tot] = (edge){a[i].u, a[i].v};
		E[a[i].t][a[i].k] = tot;
	}
	T.modify(1, 1, m + 1, a[cnt].t + 1, m + 1, tot);
	D.init(n);
	T.solve(1, 1, m + 1);
}