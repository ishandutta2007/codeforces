#include <bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
using std::vector; using std::set;
typedef long long LL;
const int N = 200005;
int T, n, Q, l[N], r[N]; char A[N], B[N];
int w[N*4], tg[N*4];
void pushup(int o) { w[o] = w[lc] + w[rc]; }
void pushdown(int o, int l, int r) {
	if (tg[o] == -1) return;
	tg[lc] = tg[rc] = tg[o];
	int mid = l+r>>1;
	w[lc] = tg[o] * (mid - l + 1), w[rc] = tg[o] * (r - mid);
	tg[o] = -1;
}
void build(int o, int l, int r) {
	tg[o] = -1;
	if (l == r) { w[o] = B[l - 1] == '1'; return; }
	int mid = l+r>>1;
	build(lc, l, mid), build(rc, mid+1, r);
	pushup(o);
}
void modify(int o, int l, int r, int x, int y, int v) {
	if (x <= l && r <= y) { w[o] = v * (r - l + 1), tg[o] = v; return; }
	int mid = l+r>>1; pushdown(o, l, r);
	if (x <= mid) modify(lc, l, mid, x, y, v);
	if (mid < y) modify(rc, mid+1, r, x, y, v);
	pushup(o);
}
int query(int o, int l, int r, int x, int y) {
	if (r < x || y < l) return 0;
	if (x <= l && r <= y) return w[o];
	int mid = l+r>>1; pushdown(o, l, r);
	return query(lc, l, mid, x, y) + query(rc, mid+1, r, x, y);
}
bool check(int o, int l, int r) {
	if (l == r) return (w[o] ? '1' : '0') == A[l - 1];
	int mid = l+r>>1; pushdown(o, l, r);
	return check(lc, l, mid) & check(rc, mid+1, r);
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &Q);
		scanf("%s%s", A, B);
		build(1, 1, n);
		for (int i = 1; i <= Q; i++) scanf("%d%d", &l[i], &r[i]);
		int ok = 1;
		for (int i = Q; i; i--) {
			int x = query(1, 1, n, l[i], r[i]), L = r[i] - l[i] + 1;
			if (x * 2 == L) { ok = 0; break; }
			modify(1, 1, n, l[i], r[i], x * 2 > L);
		}
		ok &= check(1, 1, n);
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}