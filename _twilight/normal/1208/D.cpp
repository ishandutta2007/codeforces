#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long
#define pli pair<ll, int>

const ll llf = 1e18;

typedef class SegTreeNode {
	public:
		pli v;
		ll tg;
		SegTreeNode *l, *r;

		SegTreeNode() { }

		void mdf(ll x) {
			tg += x, v.first += x;
		}
		void push_up() {
			v = min(l->v, r->v);
		}
		void push_down() {
			if (tg) {
				l->mdf(tg);
				r->mdf(tg);
				tg = 0;
			}
		}
} SegTreeNode;

const int N = 2e5 + 5;

SegTreeNode pool[N << 1];
SegTreeNode *_top = pool;

typedef class SegmentTree {
	public:
		int n;
		SegTreeNode *rt;

		void build(SegTreeNode*& p, int l, int r, ll* s) {
			p = _top++;
			if (l == r) {
				p->v = pli(s[l], -l);
				return;
			}
			int mid = (l + r) >> 1;
			build(p->l, l, mid, s);
			build(p->r, mid + 1, r, s);
			p->push_up();
		}
		void build(int n, ll* s) {
			this->n = n;
			build(rt, 1, n, s);
		}

		void modify(SegTreeNode* p, int l, int r, int ql, int qr, ll v) {
			if (l == ql && r == qr) {
				p->mdf(v);
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
		void modify(int l, int r, ll v) {
			modify(rt, 1, n, l, r, v);
		}

		int query() {
			return -rt->v.second;
		}
} SegmentTree;

int n;
ll s[N];
int p[N];
SegmentTree st;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", s + i);
	}
	st.build(n, s);
	for (int i = 1; i <= n; i++) {
		int idx = st.query();
		p[idx] = i;
		st.modify(idx, n, -i);
		st.modify(idx, idx, llf);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", p[i]);
	}
	return 0;
}