#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
#define INF 0x3f3f3f3f
int n, m;
struct Segment_Tree{
	struct node{
		int mn, cmn;
		node(int _mn = INF, int _cmn = INF){ mn = _mn, cmn = _cmn; }
		node operator + (const node &rhs) const {
			if (mn < rhs.mn) return node(mn, std :: min(rhs.mn, cmn));
			else return node(rhs.mn, std :: min(mn, rhs.cmn));
		}
	}val[N << 2];
	void modify(int u, int l, int r, int x, int v){
		if (l == r) return val[u] = node(v, INF), void(0);
		int md = (l + r) >> 1;
		if (x <= md) modify(u << 1, l, md, x, v);
		else modify(u << 1 | 1, md + 1, r, x, v);
		val[u] = val[u << 1] + val[u << 1 | 1];
	}
	node query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return val[u];
		int md = (l + r) >> 1;
		if (R <= md) return query(u << 1, l, md, L, R);
		else if (L > md) return query(u << 1 | 1, md + 1, r, L, R);
		else return query(u << 1, l, md, L, R) + query(u << 1 | 1, md + 1, r, L, R);
	}
}T[9];
void modify(int p, int x){
	int _x = x;
	for (register int i = 0; i < 9; ++i, x /= 10)
		if (x % 10) T[i].modify(1, 1, n, p, _x);
		else T[i].modify(1, 1, n, p, INF);
}
int query(int l, int r){
	int rhs = INF << 1;
	for (register int i = 0; i < 9; ++i){
		Segment_Tree :: node t = T[i].query(1, 1, n, l, r);
		if (t.cmn != INF) rhs = std :: min(rhs, t.mn + t.cmn);
	}
	return rhs == (INF << 1) ? -1 : rhs;
}
int main(){
	n = read(), m = read();
	for (register int i = 1, x; i <= n; ++i) x = read(), modify(i, x);
	for (register int i = 1; i <= m; ++i){
		int opt = read(), x = read(), y = read();
		if (opt == 1) modify(x, y);
		else printf("%d\n", query(x, y));
	}
}