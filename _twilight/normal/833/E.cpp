#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;
const int inf = (signed) (~0u >> 1);

typedef class Event {
	public:
		int p, op, id;
	
		Event(int p, int op, int id) : p(p), op(op), id(id) {	}

		boolean operator < (Event b) const {
			return p < b.p;
		}
} Event;

typedef class pii {
	public:
		int x, y;

		pii(int x, int y) : x(x), y(y) {
			(x > y) && (x = y);
		}

		boolean operator < (pii b) const {
			return (x ^ b.x) ? (x < b.x) : (y < b.y);
		}
} pii;

typedef class SegTreeNode {
	public:
		int v;
		SegTreeNode *l, *r;
		
		SegTreeNode() {}
		
		void push_up() {
			v = max(l->v, r->v);
		}
} SegTreeNode;

SegTreeNode pool[N << 1];
SegTreeNode *_top = pool;

typedef class SegmentTree {
	public:
		int n;
		SegTreeNode* rt;

		SegmentTree() {	}
		SegmentTree(int n) : n(n) {
			build(rt, 1, n);
		}

		void build(SegTreeNode* &p, int l, int r) {
			p = _top++;
			if (l == r) {
				return;
			}
			int mid = (l + r) >> 1;
			build(p->l, l, mid);
			build(p->r, mid + 1, r);
		}

		void modify(SegTreeNode *p, int l, int r, int idx, int v) {
			if (l == r) {
				p->v += v;
				return;
			}
			int mid = (l + r) >> 1;
			if (idx <= mid) {
				modify(p->l, l, mid, idx, v);
			} else {
				modify(p->r, mid + 1, r, idx, v);
			}
			p->push_up();
		}

		int query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->v;
			}
			int mid = (l + r) >> 1;
			if (qr <= mid) {
				return query(p->l, l, mid, ql, qr);
			} else if (ql > mid) {
				return query(p->r, mid + 1, r, mid + 1, qr);
			}
			int a = query(p->l, l, mid, ql, mid);
			int b = query(p->r, mid + 1, r, mid + 1, qr);
			return max(a, b);
		}

		void modify(int idx, int v) {
			modify(rt, 1, n, idx, v);
		}
		int query(int l, int r) {
			if (l > r) {
				return 0;
			}
			return query(rt, 1, n, l, r);
		}
} SegmentTree;

#define par pair<int, int>

int n, C, m;
set<int> cur;
int f[N], g[N];
map<pii, int> G;
vector<Event> E;
vector<int> st, fr;
int L[N], R[N], c[N];

par ps[N];
int id[N];
SegmentTree seg;

int get_position(int cost) {
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (ps[mid].first <= cost) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return l - 1;
}

int main() {
	scanf("%d%d", &n, &C);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", L + i, R + i, c + i);
		E.emplace_back(L[i], 1, i);
		E.emplace_back(R[i], -1, i);
		ps[i] = par(c[i], i);
	}
	E.emplace_back(0, 0, 0);
	sort(E.begin(), E.end());
	sort(ps + 1, ps + n + 1);
	for (int i = 1; i <= n; i++) {
		id[ps[i].second] = i;
	}
	if (n) {
		seg = SegmentTree(n);
	}
	int freelen = 0, blank = 0;
	for (int i = 0, j = 0; i < (signed) E.size(); i = j) {
		for ( ; j < (signed) E.size() && E[j].p == E[i].p; j++) {
			if (E[j].op == 1) {
				cur.insert(E[j].id);
			} else if (E[j].op == -1) {
				cur.erase(cur.find(E[j].id));
			}
		}
		int len = ((j == (signed) E.size()) ? (inf >> 1) : (E[j].p - E[i].p));
		if (!cur.size()) {
			st.push_back(E[i].p + len);
			fr.push_back(freelen + (blank += len));
		} else if (cur.size() == 1) {
			int x = *cur.begin();
			if (c[x] > C) {
				continue;
			}
			int px = id[x];
			seg.modify(px, -f[x]);
			f[x] += len, g[x] += len;
			int _ = get_position(C - c[x]);
			_ = seg.query(1, _) + f[x];
			g[x] = max(g[x], _);
			seg.modify(px, f[x]);
			int old = freelen;
			freelen = max(f[x], freelen);
			freelen = max(g[x], freelen);
			if (old ^ freelen) {
				st.push_back(E[j].p);
				fr.push_back(freelen + blank);
			}
		} else if (cur.size() == 2) {
			int x = *cur.begin(), y = *--cur.end();
			if (c[x] + c[y] <= C) {
				int com = (G[pii(x, y)] += len);
				int old = freelen;
				g[x] = max(g[x], f[x] + f[y] + com);
				g[y] = max(g[y], f[x] + f[y] + com);
				freelen = max(g[x], freelen);
				freelen = max(g[y], freelen);
				if (old ^ freelen) {
					st.push_back(E[j].p);
					fr.push_back(freelen + blank);
				}
			}
		}
	}
	scanf("%d", &m);
	int x;
	while (m--) {
		scanf("%d", &x);
		int l = 0, r = (signed) fr.size() - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (fr[mid] >= x) {
				r = mid  - 1;
			} else {
				l = mid + 1;
			}
		}
		++r;
		printf("%d\n", st[r] - (fr[r] - x));
	}
	return 0;
}