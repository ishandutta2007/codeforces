#include <bits/stdc++.h>
const int N = 200005, M = 1 << 20;
int n, Q, rt = 0;
int lc[N * 50], rc[N * 50], tagx[N * 50], tagl[N * 50], tagr[N * 50], sum[N * 50], tot = 0;
void up(int o) {
	tagl[o] = tagl[lc[o]] | tagl[rc[o]];
	tagr[o] = tagr[lc[o]] | tagr[rc[o]];
	sum[o] = sum[lc[o]] + sum[rc[o]];
}
void pushx(int o, int x, int dep) {
	if (x >> dep & 1) std::swap(lc[o], rc[o]);
	int L = tagl[o], R = tagr[o];
	tagl[o] = (L & (x ^ (M - 1))) | (R & x);
	tagr[o] = (L & x) | (R & (x ^ (M - 1)));
	tagx[o] ^= x;
}
void down(int o, int dep) {
	if (!tagx[o]) return;
	pushx(lc[o], tagx[o], dep - 1), pushx(rc[o], tagx[o], dep - 1);
	tagx[o] = 0;
}
void ins(int &o, int x, int dep) {
	if (!o) o = ++tot;
	if (dep == -1) {
		tagl[o] = x ^ (M - 1), tagr[o] = x, sum[o] = 1;
		return;
	}
	x >> dep & 1 ? ins(rc[o], x, dep - 1) : ins(lc[o], x, dep - 1);
	up(o);
}
void split(int &x, int &y, int l, int r, int L, int R, int dep) {
	if (!x) return;
	if (L <= l && r <= R) {
		y = x, x = 0;
		return;
	}
	int mid = l + r >> 1; down(x, dep);
	y = ++tot;
	if (L <= mid) split(lc[x], lc[y], l, mid, L, R, dep - 1);
	if (mid < R) split(rc[x], rc[y], mid + 1, r, L, R, dep - 1);
	up(x), up(y);
}
void merge(int &x, int y, int dep) {
	if (!x || !y) { x += y; return; }
	if (dep == -1) return;
	down(x, dep), down(y, dep);
	merge(lc[x], lc[y], dep - 1), merge(rc[x], rc[y], dep - 1);
	up(x);
}
void pushor(int &o, int x, int dep) {
	if (dep == -1 || !o) return;
	if (!(x & tagl[o] & tagr[o])) {
		pushx(o, x & tagl[o], dep);
		return;
	}
	down(o, dep);
	if (x >> dep & 1) {
		pushx(lc[o], 1 << dep, dep - 1);
		merge(rc[o], lc[o], dep - 1);
		lc[o] = 0;
	}
	pushor(lc[o], x, dep - 1), pushor(rc[o], x, dep - 1);
	up(o);
}
int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		ins(rt, x, 19);
	}
	while (Q--) {
		int ty, l, r, now = 0; scanf("%d%d%d", &ty, &l, &r);
		split(rt, now, 0, M - 1, l, r, 19);
		if (ty == 4) printf("%d\n", sum[now]);
		else {
			int x; scanf("%d", &x);
			if (ty == 1) pushx(now, M - 1, 19), pushor(now, x ^ (M - 1), 19), pushx(now, M - 1, 19);
			if (ty == 2) pushor(now, x, 19);
			if (ty == 3) pushx(now, x, 19);
		}
		merge(rt, now, 19);
	}
	return 0;
}