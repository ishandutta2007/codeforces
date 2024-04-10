#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 5e5 + 5;

template <typename T>
T smin(T a) {
	return a;
}
template <typename T, typename ...args>
T smin(T a, args... b) {
	return min(a, smin(b...));
}

#define ll long long

typedef class Item {
	public:
		int t, dt, a, b;

		void read() {
			scanf("%d%d%d", &t, &a, &b);
		}
		boolean operator < (Item x) const {
			return b > x.b;
		}
} Item;

typedef class SegTreeNode {
	public:
		int mx, tg;
		SegTreeNode *l, *r;
		
		void upd(int _tg) {
			mx += _tg;
			tg += _tg;
		}
		void push_down() {
			if (tg) {
				l->upd(tg);
				r->upd(tg);
				tg = 0;
			}
		}
		void push_up() {
			mx = max(l->mx, r->mx);
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->mx = 0, top->tg = 0;
			top->l = top->r = NULL;
			return top++;
		}
		
		int n;
		SegTreeNode* rt;

		SegmentTree() : rt(NULL) {	}
		
		void build(SegTreeNode*& p, int l, int r, int* pos, int c0) {
			p = newnode();
			if (l ^ r) {
				int mid = (l + r) >> 1;
				build(p->l, l, mid, pos, c0);
				build(p->r, mid + 1, r, pos, c0);
				p->push_up();
			} else {
				p->mx = c0 - pos[l];
			}
		}

		void build(int n, int *pos, int c0) {
			this->n = n;
			top = pool;
			build(rt, 0, n, pos, c0);
		}

		int query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->mx;
			}
			p->push_down();
			int mid = (l + r) >> 1;
			if (qr <= mid) {
				return query(p->l, l, mid, ql, qr);
			} else if (ql > mid) {
				return query(p->r, mid + 1, r, ql, qr);
			}
			int a = query(p->l, l, mid, ql, mid);
			int b = query(p->r, mid + 1, r, mid + 1, qr);
			return max(a, b);
		}

		void modify(SegTreeNode* p, int l, int r, int ql, int qr, int v) {
			if (l == ql && r == qr) {
				p->upd(v);
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

		ll query(int l, int r) {
			return query(rt, 0, n, l, r);
		}
		void modify(int l, int r, int v) {
			return modify(rt, 0, n, l, r, v);
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

int T;
int n, m, c, c0;
Item a[N];
int pos[N];
SegmentTree st;
priority_queue<Item> Q;

void solve() {
	scanf("%d%d%d%d", &n, &m, &c, &c0);
	pos[0] = 0;
	for (int i = 1; i <= n; i++) {
		a[i].read();
		pos[i] = a[i].t;
	}
	sort(pos + 1, pos + n + 1);
	sort(a + 1, a + n + 1, [&] (const Item& a, const Item& b) {	return a.t < b.t;	});
	int qaq = 0;
	for (int i = 1; i <= n; i++) {
		while (pos[qaq] < a[i].t)
			++qaq;
		a[i].dt = qaq;
	}
	st.build(n, pos, c0);
	int R = c0;
	Item *pa = a + 1, *_pa = a + n + 1;
	ll ans = 0;
	while (!Q.empty())
		Q.pop();
	while (R < m) {
		while (pa != _pa && pa->t <= R)
			Q.push(*pa), pa++;
		if (Q.empty()) {
			puts("-1");
			return;
		}
		Item it = Q.top();
		Q.pop();
		int lim = c - st.query(it.dt, n);
		lim = min(lim, it.a);
		if (!lim)
			continue;
		if (pa != _pa) {
			lim = min(lim, pa->t - R);
		} else {
			lim = min(lim, m - R);	
		}
		R += lim;
		ans += 1ll * it.b * lim;
		it.a -= lim;
		st.modify(it.dt, n, lim);
		if (it.a)
			Q.push(it);
	}
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}