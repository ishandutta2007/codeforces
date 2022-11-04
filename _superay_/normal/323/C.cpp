#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, p[N], q[N], fuck[N];
struct Node {
	int lson, rson, cnt;
} st[N * 21];
int tot;
void Ins(int &x, int y, int l, int r, int pos) {
	x = ++tot;
	st[x] = st[y];
	st[x].cnt++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) Ins(st[x].lson, st[y].lson, l, mid, pos);
	else Ins(st[x].rson, st[y].rson, mid + 1, r, pos);
}
int Qry(int x, int l, int r, int lf, int rg) {
	if (!x) return 0;
	if (lf <= l && r <= rg) return st[x].cnt;
	int mid = (l + r) >> 1, ret = 0;
	if (lf <= mid) ret += Qry(st[x].lson, l, mid, lf, rg);
	if (rg > mid) ret += Qry(st[x].rson, mid + 1, r, lf, rg);
	return ret;
}
int rt[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		p[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		q[x] = i;
	}
	for (int i = 1; i <= n; i++) fuck[p[i]] = q[i];
	for (int i = 1; i <= n; i++) Ins(rt[i], rt[i - 1], 1, n, fuck[i]);
	int yhtakioi;
	scanf("%d", &yhtakioi);
	int orzyht = 0;
	while (yhtakioi--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		l1 = ((l1 - 1 + orzyht) % n) + 1;
		r1 = ((r1 - 1 + orzyht) % n) + 1;
		if (l1 > r1) swap(l1, r1);
		l2 = ((l2 - 1 + orzyht) % n) + 1;
		r2 = ((r2 - 1 + orzyht) % n) + 1;
		if (l2 > r2) swap(l2, r2);
		orzyht = Qry(rt[r1], 1, n, l2, r2) - Qry(rt[l1 - 1], 1, n, l2, r2);
		printf("%d\n", orzyht);
		orzyht++;
	}
	return 0;
}