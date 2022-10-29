#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const signed ll llf = (1ll << 50);

typedef class SegTreeNode {
	public:
		ll v, tg;
		SegTreeNode *l, *r;

		SegTreeNode() : v(llf), tg(0), l(NULL), r(NULL) {	}

		void pushUp() {
			v = min(l->v, r->v);
		}

		void modify(ll x) {
			v += x, tg += x;
		}

		void pushDown() {
			l->modify(tg);
			r->modify(tg);
			tg = 0;
		}
} SegTreeNode;

SegTreeNode pool[3000000];
SegTreeNode *top = pool;

SegTreeNode* newnode() {
	return top++;
}

typedef class SegTree {
	public:
		int n;
		SegTreeNode *rt;
	
		SegTree() : rt(NULL) {	}
		SegTree(int n, ll * v) : n(n) {
			build(rt, 1, n, v);
		}

		void build(SegTreeNode*& p, int l, int r, ll *v) {
			p = newnode();
			if (l == r) {
				p->v = v[l];
				return;
			}	
			int mid = (l + r) >> 1;
			build(p->l, l, mid, v);
			build(p->r, mid + 1, r, v);
			p->pushUp();
		}

		void modify(SegTreeNode* p, int l, int r, int ql, int qr, ll v) {
			if (l == ql && r == qr) {
				p->modify(v);
				return;
			}
			if (p->tg)
				p->pushDown();
			int mid = (l + r) >> 1;
			if (qr <= mid)
				modify(p->l, l, mid, ql, qr, v);
			else if (ql > mid)
				modify(p->r, mid + 1, r, ql, qr, v);
			else {
				modify(p->l, l, mid, ql, mid, v);
				modify(p->r, mid + 1, r, mid + 1, qr, v);
			}
			p->pushUp();
		}

		ll query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->v;
			}
			if (p->tg)
				p->pushDown();
			int mid = (l + r) >> 1;
			if (qr <= mid)
				return query(p->l, l, mid, ql, qr);
			if (ql > mid)
				return query(p->r, mid + 1, r, ql, qr);
			ll a = query(p->l, l, mid, ql, mid);
			ll b = query(p->r, mid + 1, r, mid + 1, qr);
			return min(a, b);
		}

		ll query(int l, int r) {
			return query(rt, 1, n, l, r);
		}

		void modify(int l, int r, ll v) {
			modify(rt, 1, n, l, r, v);
		}
} SegTree;

const int N = 5e5 + 5;

typedef class Event {
	public:
		int opt;
		int p, x, y;
		ll v;

		Event(int opt, int p, int x, int y, ll v) : opt(opt), p(p), x(x), y(y), v(v) {	}

		boolean operator < (Event b) const {
			if (p ^ b.p)
				return p < b.p;
			return opt < b.opt;
		}
} Event;

int n, q;
ll ans[N];
ll d[N], dv[N];
int order[N];
vector<int> g[N];
int in[N], out[N];
int m_in[N], m_out[N];
vector<Event> E;

inline void init() {
	scanf("%d%d", &n, &q);
	d[1] = 0;
	for (int i = 2, x, v; i <= n; i++) {
		scanf("%d%d", &x, &v);
		d[i] = d[x] + v;
		g[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].size())
			dv[i] = llf;
		else
			dv[i] = d[i];
	}
}

int dfs_clock;
void dfs(int p) {
	in[p] = ++dfs_clock;
	for (auto e : g[p]) {
		dfs(e);
	}
	out[p] = dfs_clock;
}

inline void solve() {
	dfs(1);
	for (int i = 2; i <= n; i++) {
		if (!g[i].size()) {
			m_in[i] = in[i];
			m_out[i] = in[i];
		}
	}
	m_in[n + 1] = 10000000, m_out[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (!m_out[i])
			m_out[i] = m_out[i - 1];
	}
	for (int i = n; i; i--) {
		if (!m_in[i]) {
			m_in[i] = m_in[i + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		E.push_back(Event(1, in[i], in[i], out[i], -2 * d[i]));
		E.push_back(Event(1, out[i] + 1, in[i], out[i], 2 * d[i]));
		for (auto e : g[i]) {
			E.push_back(Event(1, in[e], in[e], out[e], 2 * d[i]));
			E.push_back(Event(1, out[e] + 1, in[e], out[e], -2 * d[i]));
		}
	}
	for (int i = 1, v, x, y; i <= q; i++) {
		scanf("%d%d%d", &v, &x, &y);
		ans[i] += d[v];
		E.push_back(Event(2, in[v], m_in[x], m_out[y], i));
	}
	sort(E.begin(), E.end());

	SegTree st (n, dv);
	vector<Event> :: iterator pe = E.begin();
	for (int i = 1; i <= n; i++) {
		while (pe != E.end() && pe->p == i) {
			if (pe->opt == 1) {
				st.modify(pe->x, pe->y, pe->v);
			} else {
				ans[pe->v] += st.query(pe->x, pe->y);
			}
			pe++;
		}
	}
	for (int i = 1; i <= q; i++) {
		printf("%I64d\n", ans[i]);
	}
}

int main() {
	init();
	solve();
	return 0;
}