#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, d, q, a[200005][5], s[200005];
struct Query{
	int opt, x, b[5], l, r, ans;
}Q[200005];
struct Answer{
	int mx, mn;
	Answer(int Mx = -1000000000, int Mn = 1000000000){ mx = Mx, mn = Mn; }
	void operator += (const Answer &res){
		mx = std :: max(mx, res.mx);
		mn = std :: min(mn, res.mn);
	}
};
struct Segment_Tree{
	int mx[1000005], mn[1000005];
	void up(int u){
		mx[u] = std :: max(mx[u << 1], mx[u << 1 | 1]);
		mn[u] = std :: min(mn[u << 1], mn[u << 1 | 1]);
	}
	void build(int u, int l, int r){
		if (l == r) return mx[u] = mn[u] = s[l], void(0);
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		up(u);
	}
	void modify(int u, int l, int r, int x, int y){
		if (l == r) return mx[u] = mn[u] = y, void(0);
		int mid = l + r >> 1;
		if (x <= mid) modify(u << 1, l, mid, x, y);
		else modify(u << 1 | 1, mid + 1, r, x, y);
		up(u);
	}
	Answer query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return Answer(mx[u], mn[u]);
		int mid = l + r >> 1; Answer res;
		if (L <= mid) res += query(u << 1, l, mid, L, R);
		if (R > mid) res += query(u << 1 | 1, mid + 1, r, L, R);
		return res;
	}
}T;
int main(){
	n = read(), d = read();
	for (register int i = 1; i <= n; ++i)
		for (register int j = 0; j < d; ++j)
			a[i][j] = read();
	q = read();
	for (register int i = 1; i <= q; ++i){
		Q[i].opt = read();
		if (Q[i].opt == 1){
			Q[i].x = read();
			for (register int j = 0; j < d; ++j) Q[i].b[j] = read();
		}
		else Q[i].l = read(), Q[i].r = read();
	}
	for (register int p = 0; p < (1 << d); ++p){
		for (register int i = 1; i <= n; ++i){
			s[i] = 0;
			for (register int j = 0; j < d; ++j)
				if (p & (1 << j)) s[i] -= a[i][j]; else s[i] += a[i][j];
		}
		T.build(1, 1, n);
		for (register int i = 1; i <= q; ++i){
			if (Q[i].opt == 1){
				int tmp = 0;
				for (register int j = 0; j < d; ++j)
					if (p & (1 << j)) tmp -= Q[i].b[j]; else tmp += Q[i].b[j];
				T.modify(1, 1, n, Q[i].x, tmp);
			}
			else{
				Answer ans = T.query(1, 1, n, Q[i].l, Q[i].r);
				Q[i].ans = std :: max(Q[i].ans, ans.mx - ans.mn);
			}
		}
	}
	for (register int i = 1; i <= q; ++i)
		if (Q[i].opt == 2) printf("%d\n", Q[i].ans);
}