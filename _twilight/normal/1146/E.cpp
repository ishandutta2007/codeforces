#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int __abs(int x) {
	return (x < 0) ? (-x) : (x);
}

typedef class SegTreeNode {
	public:
		int tag_rev, tag_cov;
		SegTreeNode *l, *r;
		
		void upd_rev(int sgn) {
			tag_rev *= sgn;
			tag_cov *= sgn;
		}
		void upd_cov(int sgn) {
			tag_rev = 1;
			tag_cov = sgn;
		}
		void push_down() {
			if (tag_rev != 1) {
				l->upd_rev(tag_rev);
				r->upd_rev(tag_rev);
				tag_rev = 1;
			}
			if (tag_cov) {
				l->upd_cov(tag_cov);
				r->upd_cov(tag_cov);
				tag_cov = 0;
			}
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->tag_rev = 1;
			top->tag_cov = 0;
			return top++;
		}
		
		int n;
		SegTreeNode* rt;

		SegmentTree() : rt(NULL) {	}
		
		void build(SegTreeNode*& p, int l, int r) {
			p = newnode();
			if (l ^ r) {
				int mid = (l + r) >> 1;
				build(p->l, l, mid);
				build(p->r, mid + 1, r);
			}
		}
		void build(int n) {
			this->n = n;
			build(rt, 0, n);
		}

		int query(SegTreeNode* p, int l, int r, int idx, int x) {
			if (l == r) {
				x *= p->tag_rev;
				if (p->tag_cov) {
					(x < 0) && (x = -x);
					x *= p->tag_cov;
				}
				return x;
			}
			p->push_down();
			int mid = (l + r) >> 1;
			if (idx <= mid)
				return query(p->l, l, mid, idx, x);
			return query(p->r, mid + 1, r, idx, x);
		}
		int query(int x) {
			int y = __abs(x);
			return query(rt, 0, n, y, x);
		}

		void modify_cov(SegTreeNode* p, int l, int r, int ql, int qr, int sgn) {
			if (l == ql && r == qr) {
				p->upd_cov(sgn);
				return;
			}
			p->push_down();
			int mid = (l + r) >> 1;
			if (qr <= mid) {
				modify_cov(p->l, l, mid, ql, qr, sgn);
			} else if (ql > mid) {
				modify_cov(p->r, mid + 1, r, ql, qr, sgn);
			} else {
				modify_cov(p->l, l, mid, ql, mid, sgn);
				modify_cov(p->r, mid + 1, r, mid + 1, qr, sgn);
			}
		}
		void modify_rev(SegTreeNode* p, int l, int r, int ql, int qr, int sgn) {
			if (l == ql && r == qr) {
				p->upd_rev(sgn);
				return;
			}
			p->push_down();
			int mid = (l + r) >> 1;
			if (qr <= mid) {
				modify_rev(p->l, l, mid, ql, qr, sgn);
			} else if (ql > mid) {
				modify_rev(p->r, mid + 1, r, ql, qr, sgn);
			} else {
				modify_rev(p->l, l, mid, ql, mid, sgn);
				modify_rev(p->r, mid + 1, r, mid + 1, qr, sgn);
			}
		}

		void rev(int l, int r, int sgn) {
			modify_rev(rt, 0, n, l, r, sgn);
		}
		void cov(int l, int r, int sgn) {
			modify_cov(rt, 0, n, l, r, sgn);
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

int n, q;
int a[N];
char s[10];
SegmentTree st;


int main() {
	scanf("%d%d", &n, &q);
	st.build(100001);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	int x;
	const int V = 1e5 + 1;
	while (q--) {
		scanf("%s%d", s, &x);
		if (x == 0) {
			if (s[0] == '<') {
				st.cov(0, V, 1);
			} else {
				st.cov(0, V, -1);
			}
		} else if (x > 0) {
			if (s[0] == '<') {
				st.rev(0, x - 1, -1);
				st.cov(x, V, 1);
			} else {
				st.cov(x + 1, V, -1);
			}
		} else if (x < 0) {
			if (s[0] == '<') {
				st.cov(-x + 1, V, 1);
			} else {
				st.rev(0, -x - 1, -1);
				st.cov(-x, V, -1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", st.query(a[i]));
	}
	return 0;
}