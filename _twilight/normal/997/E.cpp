#include <bits/stdc++.h>
using namespace std;

const int N = 120005;

#define ll long long

typedef class Data {
	public:
		int mi, c;

		Data() {	}
		Data(int mi, int c = 1) : mi(mi), c(c) {	}

		Data operator + (Data b) const {
			if (mi < b.mi) {
				return *this;
			} else if (mi > b.mi) {
				return b;
			}
			return Data(mi, c + b.c);
		}
} Data;

typedef class Tag {
	public:
		bool empty;
		int sum;
		Data d;

		Tag() : empty(true), sum(0), d(0, 0) {	}
		Tag(int x) : empty(false), sum(x), d(x, 1) {	}

		Tag operator + (Tag b) const {
			if (empty)
				return b;
			if (b.empty)
				return *this;
			Tag rt;
			rt.empty = false;
			rt.sum = sum + b.sum;
			b.d.mi += sum;
			rt.d = d + b.d;
			return rt;
		}
} Tag;

typedef class SegTreeNode {
	public:
		Data v;
		ll s;
		Tag tg;
		SegTreeNode *l, *r;

		void upd(Tag x) {
			if (x.d.mi + v.mi == 0)
				s += 1ll * x.d.c * v.c;
			v.mi += x.sum;
			tg = tg + x;
		}
		void push_down() {
			if (!tg.empty) {
				l->upd(tg);
				r->upd(tg);
				tg.empty = true;
			}
		}
		void push_up() {
			v = l->v + r->v;
			s = l->s + r->s;
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->v = Data(1, 1);
			top->s = 0;
			top->tg.empty = true;
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
				p->push_up();
			}
		}

		void build(int n) {
			this->n = n;
			build(rt, 1, n);
		}

		ll query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->s;
			}
			int mid = (l + r) >> 1;
			p->push_down();
			if (qr <= mid) {
				return query(p->l, l, mid, ql, qr);
			} else if (ql > mid) {
				return query(p->r, mid + 1, r, ql, qr);
			}
			return query(p->l, l, mid, ql, mid) + query(p->r, mid + 1, r, mid + 1, qr);
		}

		void modify(SegTreeNode* p, int l, int r, int ql, int qr, Tag v) {
			if (l == ql && r == qr) {
				p->upd(v);
				return;
			}
			int mid = (l + r) >> 1;
			p->push_down();
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

		ll query(int l, int r) {
			return query(rt, 1, n, l, r);
		}
		void modify(int l, int r, Tag v) {
//			cerr << l << " " << r << " " << v.sum << '\n';
			return modify(rt, 1, n, l, r, v);
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

typedef class Event {
	public:
		int l, r, id;

		Event(int l, int r, int id) : l(l), r(r), id(id) {	}

		bool operator < (Event b) const {
			return r < b.r;
		}
} Event;

int n, m;
int p[N];
ll ans[N];
int stkmi[N];
int stkmx[N];
vector<Event> E;
SegmentTree st;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", p + i);
	}
	scanf("%d", &m);
	for (int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		E.emplace_back(l, r, i);
	}
	sort(E.begin(), E.end());
	st.build(n);
	auto it = E.begin(), _it = E.end();
	int tpmi = 0, tpmx = 0;
	for (int i = 1; i <= n; i++) {
		while (tpmx && p[i] > p[stkmx[tpmx]]) {
			int r = stkmx[tpmx--];
			int l = stkmx[tpmx] + 1;
			st.modify(l, r, p[i] - p[r]);
		}
		stkmx[++tpmx] = i;
		while (tpmi && p[i] < p[stkmi[tpmi]]) {
			int r = stkmi[tpmi--];
			int l = stkmi[tpmi] + 1;
			st.modify(l, r, p[r] - p[i]);
		}
		stkmi[++tpmi] = i;
		st.modify(1, i, -1);
		while (it != _it && (*it).r == i) {
			ans[(*it).id] = st.query((*it).l, i);
			it++;
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}
//