#include<bits/stdc++.h>
#define ls d << 1
#define rs d << 1 | 1
using namespace std;

typedef long long LL;

const int N = 200005;

int n, q, a[N];
class tree {
	public:
		int lval, rval, llen, rlen;
		LL ans;
		bool tag;
}t[N * 4];

tree update(tree a, tree b) {
	tree c;
	c.lval = a.lval; c.rval = b.rval;
	c.ans = a.ans + b.ans;
	c.llen = a.llen; c.rlen = b.rlen;
	c.tag = 0;
	if (a.rval <= b.lval) {
		c.ans += (LL)a.rlen * b.llen;
		if (a.tag) c.llen += b.llen;
		if (b.tag) c.rlen += a.rlen;
		c.tag = a.tag & b.tag;
	}
	return c;
}

void build(int d, int l, int r) {
	if (l == r) {
		t[d].ans = 1;
		t[d].lval = t[d].rval = a[l];
		t[d].llen = t[d].rlen = t[d].tag = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	t[d] = update(t[ls], t[rs]);
}

void modify(int d, int l, int r, int x, int y) {
	if (l == r) {
		t[d].lval = t[d].rval = y;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid) modify(ls, l, mid, x, y);
	else modify(rs, mid + 1, r, x, y);
	t[d] = update(t[ls], t[rs]);
}

tree query(int d, int l, int r, int x, int y) {
	if (x <= l && r <= y) return t[d];
	int mid = (l + r) / 2;
	if (y <= mid) return query(ls, l, mid, x, y);
	else if (x > mid) return query(rs, mid + 1, r, x, y);
	else return update(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	while (q--) {
		int op, x, y; scanf("%d%d%d", &op, &x, &y);
		if (op == 1) modify(1, 1, n, x, y);
		else printf("%lld\n", query(1, 1, n, x, y).ans);
	}
	return 0;
}