#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ '0');
	return f ? x : -x;
}
void print(int x){
	if (x == 0) return putchar('0'), void(0);
	if (x < 0) putchar('-'), x = -x;
	int cnt = 0, num[25];
	while (x) num[++cnt] = x % 10, x /= 10;
	for (register int i = cnt; i; --i) putchar(num[i] + '0');
}
#define N 100005
int n, m, A[N];
struct node{
	int sum, lmx, lxp, rmx, rxp, mx, xpl, xpr, lmn, lnp, rmn, rnp, mn, npl, npr;
	void upd(){
		sum *= -1, lmx *= -1, lmn *= -1, rmx *= -1, rmn *= -1, mx *= -1, mn *= -1;
		std :: swap(lmx, lmn), std :: swap(lxp, lnp);
		std :: swap(rmx, rmn), std :: swap(rxp, rnp);
		std :: swap(mx, mn), std :: swap(xpl, npl), std :: swap(xpr, npr);
	}
	node operator + (const node &b) const {
		node r;
		r.sum = sum + b.sum;
		if (lmx > sum + b.lmx) r.lmx = lmx, r.lxp = lxp; else r.lmx = sum + b.lmx, r.lxp = b.lxp;
		if (b.rmx > rmx + b.sum) r.rmx = b.rmx, r.rxp = b.rxp; else r.rmx = rmx + b.sum, r.rxp = rxp;
		if (mx > b.mx) r.mx = mx, r.xpl = xpl, r.xpr = xpr; else r.mx = b.mx, r.xpl = b.xpl, r.xpr = b.xpr;
		if (rmx + b.lmx > r.mx) r.mx = rmx + b.lmx, r.xpl = rxp, r.xpr = b.lxp;
		if (lmn < sum + b.lmn) r.lmn = lmn, r.lnp = lnp; else r.lmn = sum + b.lmn, r.lnp = b.lnp;
		if (b.rmn < rmn + b.sum) r.rmn = b.rmn, r.rnp = b.rnp; else r.rmn = rmn + b.sum, r.rnp = rnp;
		if (mn < b.mn) r.mn = mn, r.npl = npl, r.npr = npr; else r.mn = b.mn, r.npl = b.npl, r.npr = b.npr;
		if (rmn + b.lmn < r.mn) r.mn = rmn + b.lmn, r.npl = rnp, r.npr = b.lnp;
		return r;
	}
};
struct Segment_Tree{
	node a[N << 2];
	int lz[N << 2];
	void build(int u, int l, int r){
		if (l == r){
			lz[u] = 0;
			a[u].sum = a[u].lmx = a[u].rmx = a[u].mx = a[u].lmn = a[u].rmn = a[u].mn = A[l];
			a[u].lxp = a[u].rxp = a[u].xpl = a[u].xpr = a[u].lnp = a[u].rnp = a[u].npl = a[u].npr = l;
			return;
		}
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	void down(int u){
		if (lz[u]) a[u << 1].upd(), lz[u << 1] ^= 1, a[u << 1 | 1].upd(), lz[u << 1 | 1] ^= 1, lz[u] = 0;
	}
	void modify_val(int u, int l, int r, int x, int y){
		if (l == r) return a[u].sum = a[u].lmx = a[u].rmx = a[u].mx = a[u].lmn = a[u].rmn = a[u].mn = y, void(0);
		int md = (l + r) >> 1;
		down(u);
		if (x <= md) modify_val(u << 1, l, md, x, y);
		else modify_val(u << 1 | 1, md + 1, r, x, y);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	void modify(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return a[u].upd(), lz[u] ^= 1, void(0);
		int md = (l + r) >> 1;
		down(u);
		if (L <= md) modify(u << 1, l, md, L, R);
		if (R > md) modify(u << 1 | 1, md + 1, r, L, R);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	node query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return a[u];
		int md = (l + r) >> 1;
		down(u);
		if (R <= md) return query(u << 1, l, md, L, R);
		else if (L > md) return query(u << 1 | 1, md + 1, r, L, R);
		else return query(u << 1, l, md, L, R) + query(u << 1 | 1, md + 1, r, L, R);
	}
}T;
int cnt, x[25], y[25], ans;
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) A[i] = read();
	T.build(1, 1, n);
	m = read();
	while (m--){
		int opt = read(), l = read(), r = read(), k;
		if (opt == 0) T.modify_val(1, 1, n, l, r);
		else{
			k = read(), cnt = 0, ans = 0;
			for (register int i = 1; i <= k; ++i){
				node tmp = T.query(1, 1, n, l, r);
				if (tmp.mx < 0) break;
				ans += tmp.mx;
				++cnt, x[cnt] = tmp.xpl, y[cnt] = tmp.xpr, T.modify(1, 1, n, tmp.xpl, tmp.xpr);
			}
			printf("%d\n", ans);
			for (register int i = cnt; i; --i) T.modify(1, 1, n, x[i], y[i]);
		}
	}
}