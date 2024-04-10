#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const signed int inf = (signed) (~0u >> 1); 

const int N = 1e5 + 5;

typedef class Data {
	public:
		int v, s;

		Data() : v(-1), s(-1) {	}
		Data(int v, int s) : v(v), s(s) {	}

		Data operator + (Data b) {
			return Data(max(v + b.s, b.v), s + b.s);
		}

		Data& operator += (int val) {
			v += val, s += val;
			return *this;
		}
} Data;

typedef class SegTreeNode {
	public:
		Data d;
		SegTreeNode *l, *r;

		SegTreeNode() : d(Data()), l(NULL), r(NULL) {	}
		
		void pushUp() {
			d = l->d + r->d;
		}
} SegTreeNode;

SegTreeNode pool[N * 3];
SegTreeNode *top = pool;

SegTreeNode* newnode() {
	return top++;
}

typedef class SegmentTree {
	public:
		int n;
		SegTreeNode* rt;

		SegmentTree() : rt(NULL) {	}
		SegmentTree(int n) : n(n) {
			build(rt, 1, n);
		}

		void build(SegTreeNode*& p, int l, int r) {
			p = newnode();
			if (l == r) {
				return;
			}
			int mid = (l + r) >> 1;
			build(p->l, l, mid);
			build(p->r, mid + 1, r);
			p->pushUp();
		}

		void modify(SegTreeNode*& p, int l, int r, int idx, int val) {
			if (l == r) {
				p->d += val;
				return;
			}
			int mid = (l + r) >> 1;
			if (idx <= mid) {
				modify(p->l, l, mid, idx, val);
			} else {
				modify(p->r, mid + 1, r, idx, val);
			}
			p->pushUp();
		}

		Data query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->d;
			}
			int mid = (l + r) >> 1;
			if (qr <= mid)
				return query(p->l, l, mid, ql, qr);
			if (ql > mid)
				return query(p->r, mid + 1, r, ql, qr);
			Data a = query(p->l, l, mid, ql, mid);
			Data b = query(p->r, mid + 1, r, mid + 1, qr);
			return a + b;
		}

		void modify(int idx, int val) {
			modify(rt, 1, n, idx, val);
		}

		Data query(int l, int r) {
			return query(rt, 1, n, l, r);
		}
} SegmentTree;

#ifdef local
FILE* fin = fopen("tree.in", "r");
FILE* fout = fopen("tree.out", "w");
#else
FILE* fin = stdin;
FILE* fout = stdout;
#endif
#define pii pair<int, int>

int n, q;
vector<int> g[N];

int dfs_clock;
SegmentTree st;
int sz[N], zson[N], fa[N];
int in[N], out[N], tp[N];

multiset<pii> op;

inline void init() {
	fscanf(fin, "%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {
		fscanf(fin, "%d", fa + i);
		g[fa[i]].push_back(i);
	}
}

void dfs1(int p) {
	int mx = -1, &id = zson[p];
	id = -1, sz[p] = 1;
	for (auto e : g[p]) {
		dfs1(e);
		sz[p] += sz[e];
		if (sz[e] > mx) {
			mx = sz[e], id = e;
		}
	}
}

void dfs2(int p, boolean ontop) {
	tp[p] = ((ontop) ? (p) : (tp[fa[p]]));
	in[p] = ++dfs_clock;
	if (~zson[p]) {
		dfs2(zson[p], false);
	}
	for (auto e : g[p]) {
		if (e ^ zson[p]) {
			dfs2(e, true);
		}		
	}
	out[p] = dfs_clock;
}

void modify(int p) {
	st.modify(in[p], 1);
	op.insert(pii(in[p], 1));
}

int query(int p) {
	int q;
	Data d = Data(-inf, 0);
	do {
		q = tp[p];
		d = st.query(in[q], in[p]) + d;
		p = fa[q];
	} while (p);
	return d.v;
}

void undo(int p) {
	multiset<pii> :: iterator it = op.lower_bound(pii(in[p], -inf)), nxt;
	for ( ; it != op.end() && it->first <= out[p]; it = nxt) {
		nxt = it;
		nxt++;
		st.modify(it->first, -it->second);
		op.erase(it);
	}
	int rt = query(p);
	st.modify(in[p], -rt - 1);
	op.insert(pii(in[p], -rt - 1));
}

inline void solve() {
	dfs1(1);
	dfs2(1, true);
	st = SegmentTree(n);
	int opt, x;
	while (q--) {
		fscanf(fin, "%d%d", &opt, &x);
		if (opt == 1) {
			modify(x);
		} else if (opt == 2) {
			undo(x);
		} else if (opt == 3) {
			int rt = query(x);
			fputs((rt <= -1) ? ("white\n") : ("black\n"), fout);
//			cerr << rt << '\n';
		}
	}
}

int main() {
	init();
	solve();
	return 0;
}