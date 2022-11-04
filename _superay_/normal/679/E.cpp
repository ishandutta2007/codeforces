#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long pw[12];
inline int Fnd(long long x) {
	return lower_bound(pw, pw + 12, x) - pw;
}
int n, q;
long long t1[N * 4], t3[N * 4], mn[N * 4];
int t2[N * 4];
inline void add_tag1(int i, long long dt, int ps) {
	mn[i] = t1[i] = dt;
	t2[i] = ps;
	t3[i] = 0;
}
inline void add_tag2(int i, long long dt) {
	if (t2[i]) {
		t1[i] -= dt;
		while (t1[i] < 0) t1[i] += pw[t2[i] + 1] - pw[t2[i]], t2[i]++;
		mn[i] = t1[i];
	} else {
		mn[i] -= dt;
		t3[i] += dt;
	}
}
inline void pushdown(int i) {
	if (t2[i]) add_tag1(i << 1, t1[i], t2[i]), add_tag1(i << 1 | 1, t1[i], t2[i]), t1[i] = t2[i] = 0;
	if (t3[i]) add_tag2(i << 1, t3[i]), add_tag2(i << 1 | 1, t3[i]), t3[i] = 0;
}
void modify(int i, int l, int r, int lf, int rg, long long dt, int ps) {
	if (lf <= l && r <= rg) {
		add_tag1(i, dt, ps);
		return;
	}
	pushdown(i);
	int mid = (l + r) >> 1;
	if (lf <= mid) modify(i << 1, l, mid, lf, rg, dt, ps);
	if (rg > mid) modify(i << 1 | 1, mid + 1, r, lf, rg, dt, ps);
	mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
}
void add(int i, int l, int r, int lf, int rg, long long dt) {
	if (lf <= l && r <= rg && (t2[i] || mn[i] >= dt)) {
		add_tag2(i, dt);
		return;
	}
	pushdown(i);
	int mid = (l + r) >> 1;
	if (lf <= mid) add(i << 1, l, mid, lf, rg, dt);
	if (rg > mid) add(i << 1 | 1, mid + 1, r, lf, rg, dt);
	mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
}
long long query(int i, int l, int r, int pos) {
	if (l == r) return pw[t2[i]] - t1[i];
	pushdown(i);
	int mid = (l + r) >> 1;
	if (pos <= mid) return query(i << 1, l, mid, pos);
	else return query(i << 1 | 1, mid + 1, r, pos);
}
int main() {
	for (int i = pw[0] = 1; i < 12; i++) pw[i] = 42 * pw[i - 1];
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int x, j;
		scanf("%d", &x);
		j = Fnd(x);
		modify(1, 1, n, i, i, pw[j] - x, j);
	}
	while (q--) {
		int ty;
		scanf("%d", &ty);
		if (ty == 1) {
			int pos;
			scanf("%d", &pos);
			printf("%lld\n", query(1, 1, n, pos));
		} else if (ty == 2) {
			int l, r, x, j;
			scanf("%d%d%d", &l, &r, &x);
			j = Fnd(x);
			modify(1, 1, n, l, r, pw[j] - x, j);
		} else {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			while (true) {
				add(1, 1, n, l, r, x);
				if (mn[1]) break;
			}
		}
	}
	return 0;
}