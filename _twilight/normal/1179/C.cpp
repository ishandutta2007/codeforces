#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int V = 1e6 + 1;
const int N = 3e5 + 5;

typedef class SegTreeNode {
	public:
		int v, tg;
		SegTreeNode *l, *r;

		SegTreeNode() : v(0), l(NULL), r(NULL) {	}

		void modify(int x) {
			tg += x;
			v += x;
		}
		void push_up() {
			v = max(l->v, r->v);
		}
		void push_down() {
			if (tg) {
				l->modify(tg);
				r->modify(tg);
				tg = 0;
			}
		}
} SegTreeNode;

SegTreeNode _pool[V << 2];
SegTreeNode *_top = _pool;

typedef class SegmentTree {
	public:
		int n;
		SegTreeNode* rt;

		SegmentTree() {	}
		SegmentTree(int n) : n(n) {
			build(rt, 1, n);
		}

		void build(SegTreeNode*& p, int l, int r) {
			p = _top++;
			if (l == r) {
				return;
			}
			int mid = (l + r) >> 1;
			build(p->l, l, mid);
			build(p->r, mid + 1, r);
		}
		
		void modify(SegTreeNode* p, int l, int r, int ql, int qr, int v) {
			if (l == ql && r == qr) {
				p->modify(v);
				return;
			}
			p->push_down();
			int mid = (l + r) >> 1;
			if (qr <= mid) {
				modify(p->l, l, mid, ql, qr, v);
			} else if (ql > mid) {
				modify(p->r, mid + 1, r, ql, qr, v);
			} else {
				modify(p->l, l, mid, ql, mid, v);
				modify(p->r, mid + 1, r, mid + 1, qr, v);
			}
			p->push_up();
		}

		int query(SegTreeNode* p, int l, int r) {
			if (l == r) {
				return (p->v > 0) ? (l) : (l - 1);
			}
			p->push_down();
			int mid = (l + r) >> 1;
			if (p->r->v > 0) {
				return query(p->r, mid + 1, r);
			}
			return query(p->l, l, mid);
		}

		void modify(int l, int r, int v) {
			modify(rt, 1, n, l, r, v);
//			cerr << "miaomiao: " << l << " " << r << " " << v << '\n';
		}
		int query() {
			int ret = query(rt, 1, n);
			ret = (ret + 1) >> 1;
			if (!ret)
				return -1;
			return ret;
		}
} SegmentTree;

int n, m, q;
int a[N], b[N];
SegmentTree st (V << 1);

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		st.modify(1, (a[i] << 1) - 1, 1);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", b + i);
		st.modify(1, (b[i] << 1), -1);
	}
	scanf("%d", &q);
	int opt, x, y;
	while (q--) {
		scanf("%d%d%d", &opt, &x, &y);
		if (opt == 1) {
			st.modify(1, (a[x] << 1) - 1, -1);
			st.modify(1, ((a[x] = y) << 1) - 1, 1);
		} else {
			st.modify(1, (b[x] << 1), 1);
			st.modify(1, ((b[x] = y) << 1), -1);
		}
		int ans = st.query();
		printf("%d\n", ans);
	}
	return 0;
}