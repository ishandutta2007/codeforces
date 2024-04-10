#include <bits/stdc++.h>
#define chkmax(a, b) a = max(a, b)
using std::min; using std::max; using std::swap;
const int N = 100005, B = 350, M = N / B + 5;
int n, Q, a[N], bl[N], la[N], ma[M], c[M], L[M];
void update(int i) {
	ma[i] = 0;
	for (int j = L[i]; j <= min(n, L[i + 1] - 1); j++)
		a[j] = max(a[j] - c[i], 1), la[j] = a[j] < L[i] ? a[j] : la[a[j]], chkmax(ma[i], a[j]);
	c[i] = 0;
}
void slow(int l, int r, int x) {
	int i = bl[l]; update(i); ma[i] = 0;
	for (int j = L[i]; j < l; j++) chkmax(ma[i], a[j]);
	for (int j = l; j <= r; j++)
		a[j] = max(a[j] - x, 1), la[j] = a[j] < L[i] ? a[j] : la[a[j]], chkmax(ma[i], a[j]);
	for (int j = r + 1; j <= min(n, L[i + 1] - 1); j++)
		la[j] = a[j] < L[i] ? a[j] : la[a[j]], chkmax(ma[i], a[j]);
}
void modify(int l, int r, int x) {
	int idl = bl[l], idr = bl[r];
	if (idl == idr) { slow(l, r, x); return; }
	slow(l, L[idl + 1] - 1, x), slow(L[idr], r, x);
	for (int i = idl + 1; i <= idr - 1; i++)
		if (c[i] = min(n, c[i] + x), ma[i] >= L[i]) update(i);
}
int query(int x, int y) {
	while (x != y) {
		if (x < y) swap(x, y);
		if (max(la[x] - c[bl[x]], 1) == max(la[y] - c[bl[y]], 1))
			x = max(a[x] - c[bl[x]], 1);
		else
			x = max(la[x] - c[bl[x]], 1);
	}
	return x;
}
int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) bl[i] = (i + B - 1) / B;
	for (int i = 1; i <= bl[n] + 1; i++) L[i] = (i - 1) * B + 1;
	for (int i = 1; i <= n; i++)
		chkmax(ma[bl[i]], a[i]), la[i] = a[i] < L[bl[i]] ? a[i] : la[a[i]];
	while (Q--) {
		int op; scanf("%d", &op);
		if (op == 1) { int l, r, x; scanf("%d%d%d", &l, &r, &x); modify(l, r, x); }
		else { int x, y; scanf("%d%d", &x, &y); printf("%d\n", query(x, y)); }
	}
	return 0;
}