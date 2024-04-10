#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n;

typedef class Segment {
	public:
		int l, r;
		boolean full;

		Segment() {	}
		Segment(int l, int r, boolean full = false) : l(l), r(r), full(full) {	}

		friend Segment operator + (Segment a, Segment b) {
			if (a.full || b.full) {
				return Segment(0, n - 1, true);
			}
//			cerr << "#" << a.l << " " << a.r << " " << b.l << " " << b.r << '\n';
			if (a.l > a.r) a.r += n;
			if (b.l > b.r) b.r += n;
//			if (a.l < n && a.r < n) a.l += n, a.r += n;
//			if (b.l < n && b.r < n) b.l += n, b.r += n;
//			assert(!(a.r < b.l - 1 || a.l > b.r + 1));
			if (a.r < b.l - 1) {
				assert(a.r < n);
				a.l += n, a.r += n;
			}
			if (b.r < a.l - 1) {
				assert(b.l < n);
				b.l += n, b.r += n;
			}
			assert(!(a.r < b.l - 1 || a.l > b.r + 1));
			Segment rt (min(a.l, b.l), max(a.r, b.r));
			if (rt.r - rt.l >= n - 1) rt.full = true;
			if (rt.l >= n && rt.r >= n) rt.l -= n, rt.r -= n;
			if (rt.r >= n) rt.r -= n;
			return rt;
		}
} Segment;

typedef class SegTreeNode {
	public:
		Segment seg;
		SegTreeNode *l, *r;
		
		void push_up() {
			seg = l->seg + r->seg;
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N * 40];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->seg = Segment(0, 0);
			top->l = top->r = NULL;
			return top++;
		}
		
		int n;
		SegTreeNode* rt;

		SegmentTree() : rt(NULL) {	}
		
		void build(SegTreeNode*& p, int l, int r, Segment* data) {
			p = newnode();
			if (l == r) {
				p->seg = data[l];
				return;
			}
			int mid = (l + r) >> 1;
			build(p->l, l, mid, data);
			build(p->r, mid + 1, r, data);
			p->push_up();
		}

		void build(int n, Segment* data) {
			this->n = n;
			build(rt, 0, n - 1, data);
		}

		Segment query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->seg;
			}
			int mid = (l + r) >> 1;
			if (qr <= mid) {
				return query(p->l, l, mid, ql, qr);
			} else if (ql > mid) {
				return query(p->r, mid + 1, r, ql, qr);
			}
			return query(p->l, l, mid, ql, mid) + query(p->r, mid + 1, r, mid + 1, qr);
		}

		Segment query(int l, int r) {
			if (l <= r) {
				return query(rt, 0, n - 1, l, r);
			}
			return query(rt, 0, n - 1, l, n - 1) + query(rt, 0, n - 1, 0, r);
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N * 40];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

const int bzmax = 18;

int a[N];
Segment segs[N];
SegmentTree st[20];

int main() {
	scanf("%d", &n);
	if (n == 1) {
		puts("0");
		return 0;
	}
	int hn = n >> 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (a[i] >= hn) {
			segs[i] = Segment(0, n - 1, true);
		} else {
			segs[i] = Segment((i - a[i] + n) % n, (i + a[i]) % n);
		}
	}
	st[0].build(n, segs);
	for (int i = 1; i < bzmax; i++) {
		for (int j = 0; j < n; j++) {
			if (!segs[j].full) {
				segs[j] = st[i - 1].query(segs[j].l, segs[j].r);
			}
		}
		st[i].build(n, segs);
	}
	for (int i = 0; i < n; i++) {
		int ans = 0;
		Segment cur (i, i), curn;
		for (int j = bzmax - 1; ~j; j--) {
			if (!(curn = st[j].query(cur.l, cur.r)).full) {
				ans |= (1 << j);
				cur = curn;
			}
		}
		printf("%d ", ans + 1);
	}
	return 0;
}