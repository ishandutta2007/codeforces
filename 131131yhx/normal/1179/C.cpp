#include <bits/stdc++.h>

using namespace std;

int n, m, a[300010], b[300010], Mx[4000010], Tg[4000010];

void pd(int x) {
	if(Tg[x]) Mx[x * 2] += Tg[x], Tg[x * 2] += Tg[x], Mx[x * 2 + 1] += Tg[x], Tg[x * 2 + 1] += Tg[x], Tg[x] = 0;
}

void add(int x, int L, int R, int l, int r, int v) {
	int md = (L + R) / 2;
	if(L == l && R == r) {Tg[x] += v; Mx[x] += v; return;}
	pd(x);
	if(l <= md) add(x * 2, L, md, l, min(md, r), v);
	if(r > md) add(x * 2 + 1, md + 1, R, max(l, md + 1), r, v);
	Mx[x] = max(Mx[x * 2], Mx[x * 2 + 1]);
}

int Do(int x, int L, int R) {
	int md = (L + R) / 2;
	if(L == R) return L;
	pd(x);
	if(Mx[x * 2 + 1] > 0) return Do(x * 2 + 1, md + 1, R); else return Do(x * 2, L, md);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), add(1, 1, 1000000, 1, a[i], 1);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]), add(1, 1, 1000000, 1, b[i], -1);
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) {add(1, 1, 1000000, 1, a[x], -1); add(1, 1, 1000000, 1, a[x] = y, 1);}
		else {add(1, 1, 1000000, 1, b[x], 1); add(1, 1, 1000000, 1, b[x] = y, -1);}
		printf("%d\n", Mx[1] <= 0 ? -1 : Do(1, 1, 1000000));
	}
	return 0;
}