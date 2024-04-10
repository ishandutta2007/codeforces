#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const signed inf = (signed) (~0u >> 1);

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

typedef class Segment {
	public:
		int l, r, id;
		
		void read() {
			scanf("%d%d%d", &l, &r, &id);
		}
		
		boolean operator < (Segment b) const {
			if (l ^ b.l)
				return l > b.l;
			if (r ^ b.r)
				return r < b.r;
			return id < b.id;
		}
} Segment;

typedef class SegTreeNode {
	public:
		int val;		// max {r}
		SegTreeNode *l, *r;
		
		SegTreeNode() {	}
		SegTreeNode(int val, SegTreeNode* l, SegTreeNode* r) : val(val), l(l), r(r) {	}
		
		void pushUp() {
			val = max((l) ? (l->val) : (inf), (r) ? (r->val) : (inf));
		}	
} SegTreeNode;	

const int Lim = 4e6 + 5;

SegTreeNode pool[Lim];
SegTreeNode *top = pool;

SegTreeNode* newnode() {
	if (top >= pool + Lim)
		return new SegTreeNode(inf, NULL, NULL);
	top->val = inf;
	return top++;
}

typedef class DurableSegTree {
	public:
		int n, maxver;
		SegTreeNode **rts;
		
		DurableSegTree(int n, int maxver) : n(n), maxver(maxver) {
			rts = new SegTreeNode*[(maxver + 1)];
			pfill(rts, rts + maxver + 1, (SegTreeNode*) NULL);
		}
		
		void modify(SegTreeNode* pre, SegTreeNode*& p, int l, int r, int idx, int val) {
			p = newnode();
			if (pre)
				*p = *pre;
			if (l == r) {
				p->val = min(p->val, val);
				return ;
			}
			int mid = (l + r) >> 1;
			if (idx <= mid)
				modify((pre) ? (pre->l) : (NULL), p->l, l, mid, idx, val);
			else
				modify((pre) ? (pre->r) : (NULL), p->r, mid + 1, r, idx, val);
			p->pushUp(); 
		}
		
		int query(SegTreeNode *p, int l, int r, int ql, int qr) {
			if (!p)
				return inf;
			if (l == ql && r == qr)
				return p->val;
			int mid = (l + r) >> 1;
			if (qr <= mid)
				return query(p->l, l, mid, ql, qr);
			if (ql > mid)
				return query(p->r, mid + 1, r, ql, qr);
			int a = query(p->l, l, mid, ql, mid);
			int b = query(p->r, mid + 1, r, mid + 1, qr);
			return max(a, b);
		}
		
		SegTreeNode*& operator [] (int p) {
			return rts[p];
		}
} DurableSegTree;

int n, m, q;
Segment *ss;

inline void init() {
	scanf("%d%d%d", &m, &q, &n);
	ss = new Segment[(n + 1)];
	for (int i = 1; i <= n; i++) {
		ss[i].read();
	}
}

int search(int x) {
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (ss[mid].l >= x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l - 1;
}

inline void solve() {
	DurableSegTree dst(m, n);
	sort(ss + 1, ss + n + 1);
	for (int i = 1; i <= n; i++) {
		dst.modify(dst[i - 1], dst[i], 1, m, ss[i].id, ss[i].r);
	}
	int a, b, x, y;
	while (q--) {
		scanf("%d%d%d%d", &a, &b, &x, &y);
		int idx = search(x);
		puts((dst.query(dst[idx], 1, m, a, b) > y) ? ("no") : ("yes"));
		fflush(stdout);
	}
}

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	init();
	solve();
	return 0;
}