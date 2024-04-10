#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int B = 20;
const int V = N * B;
struct Node {
	int cnt, tag, has0, has1, lson, rson;
} tr[V];
int sz_tr, stk[V], sz_stk;
inline int NewNode() {
	int p;
	if (sz_stk) p = stk[sz_stk--];
	else p = ++sz_tr;
	tr[p].cnt = tr[p].tag = tr[p].has0 = tr[p].has1 = tr[p].lson = tr[p].rson = 0;
	return p;
}
inline void DelNode(int p) {
	stk[++sz_stk] = p;
}
inline void pushup(int p, int b) {
	tr[p].cnt = tr[tr[p].lson].cnt + tr[tr[p].rson].cnt;
	tr[p].has0 = tr[tr[p].lson].has0 | tr[tr[p].rson].has0;
	tr[p].has1 = tr[tr[p].lson].has1 | tr[tr[p].rson].has1;
	if (tr[p].lson) tr[p].has0 |= (1 << b);
	if (tr[p].rson) tr[p].has1 |= (1 << b);
}
inline void Tag(int p, int x, int b) {
	if (!p || b == -1) return;
	if (x >> b & 1) swap(tr[p].lson, tr[p].rson);
	int tmp = (tr[p].has0 ^ tr[p].has1) & x;
	tr[p].has0 ^= tmp, tr[p].has1 ^= tmp;
	tr[p].tag ^= x;
}
inline void pushdown(int p, int b) {
	if (tr[p].tag) {
		Tag(tr[p].lson, tr[p].tag, b - 1);
		Tag(tr[p].rson, tr[p].tag, b - 1);
		tr[p].tag = 0;
	}
}
void Insert(int &p, int x, int b) {
	if (!p) p = NewNode();
	if (b == -1) {
		tr[p].cnt = 1;
		return;
	}
	if (x >> b & 1) Insert(tr[p].rson, x, b - 1);
	else Insert(tr[p].lson, x, b - 1);
	pushup(p, b);
}
int Merge(int p, int q, int b) {
	if (!p || !q) return p | q;
	if (b == -1) {
		DelNode(q);
		return p;
	}
	pushdown(p, b);
	pushdown(q, b);
	tr[p].lson = Merge(tr[p].lson, tr[q].lson, b - 1);
	tr[p].rson = Merge(tr[p].rson, tr[q].rson, b - 1);
	DelNode(q);
	pushup(p, b);
	return p;
}
void Split(int p, int k, int &l, int &r, int b) {
	if (!p) {
		l = r = 0;
		return;
	}
	if (b == -1) {
		l = p;
		r = 0;
		return;
	}
	pushdown(p, b);
	if (k >> b & 1) {
		l = p;
		r = NewNode();
		Split(tr[p].rson, k, tr[l].rson, tr[r].rson, b - 1);
	} else {
		l = NewNode();
		r = p;
		Split(tr[p].lson, k, tr[l].lson, tr[r].lson, b - 1);
	}
	pushup(l, b);
	pushup(r, b);
}
void Or(int p, int k, int b) {
	if (!p || !(tr[p].has0 >> k & 1)) return;
	if (!(tr[p].has1 >> k & 1)) {
		Tag(p, 1 << k, b);
		return;
	}
	pushdown(p, b);
	if (b == k) {
		tr[p].rson = Merge(tr[p].lson, tr[p].rson, b - 1);
		tr[p].lson = 0;
		pushup(p, b);
		return;
	}
	Or(tr[p].lson, k, b - 1);
	Or(tr[p].rson, k, b - 1);
	pushup(p, b);
}
void And(int p, int k, int b) {
	if (!p || !(tr[p].has1 >> k & 1)) return;
	if (!(tr[p].has0 >> k & 1)) {
		Tag(p, 1 << k, b);
		return;
	}
	pushdown(p, b);
	if (b == k) {
		tr[p].lson = Merge(tr[p].lson, tr[p].rson, b - 1);
		tr[p].rson = 0;
		pushup(p, b);
		return;
	}
	And(tr[p].lson, k, b - 1);
	And(tr[p].rson, k, b - 1);
	pushup(p, b);
}
int root;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (n--) {
		int x;
		scanf("%d", &x);
		Insert(root, x, B - 1);
	}
	while (m--) {
		int ty, l, r, x;
		scanf("%d%d%d", &ty, &l, &r);
		int lp = 0, rp = 0;
		if (l) Split(root, l - 1, lp, root, B - 1);
		Split(root, r, root, rp, B - 1);
		if (ty == 1) {
			scanf("%d", &x);
			for (int i = 0; i < B; i++) if (!(x >> i & 1)) And(root, i, B - 1);
		} else if (ty == 2) {
			scanf("%d", &x);
			for (int i = 0; i < B; i++) if (x >> i & 1) Or(root, i, B - 1);
		} else if (ty == 3) {
			scanf("%d", &x);
			Tag(root, x, B - 1);
		} else {
			printf("%d\n", tr[root].cnt);
		}
		root = Merge(Merge(lp, root, B - 1), rp, B - 1);
	}
	return 0;
}