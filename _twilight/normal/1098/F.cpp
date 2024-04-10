#include <bits/stdc++.h>
#ifdef local
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 2e5 + 5;
const int bzmax = 19;

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

typedef class SparseTable {
	public:
		int n;
		int *ar;
		int log2[N];
		int f[N][bzmax];

		SparseTable() {	}
		
		void init(int n, int* ar) {
			this->n = n;
			this->ar = ar;
			log2[1] = 0;
			for (int i = 2; i <= n; i++)
				log2[i] = log2[i >> 1] + 1;
			for (int i = 0; i < n; i++)
				f[i][0] = ar[i];
			for (int j = 1; j < bzmax; j++)
				for (int i = 0; i + (1 << j) - 1 < n; i++)
					f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}

		int query(int l, int r) {
			int d = log2[r - l + 1];
//			int rt = min(f[l][d], f[r - (1 << d) + 1][d]);
//			cerr << l << " " << r << " " << rt << '\n';
			return min(f[l][d], f[r - (1 << d) + 1][d]);
		}
} SparseTable;

typedef class Pair3 {
	public:
		int x, y, id;

		Pair3() {	}
		Pair3(int x, int y, int id):x(x), y(y), id(id) {	}
} Pair3;

typedef class SuffixArray {
	protected: 
		Pair3 T1[N], T2[N];
		int cnt[N];

	public:
		int n;
		char *str;
		int sa[N], rk[N], hei[N];
		SparseTable st;

		void set(int n, char* str) {
			this->n = n;
			this->str = str;
			memset(sa, 0, sizeof(sa));
			memset(rk, 0, sizeof(rk));
			memset(hei, 0, sizeof(hei));
		}

		void radix_sort(Pair3* x, Pair3* y) {
			int m = max(n, 256);
			memset(cnt, 0, sizeof(int) * m);
			for (int i = 0; i < n; i++)
				cnt[x[i].y]++;
			for (int i = 1; i < m; i++)
				cnt[i] += cnt[i - 1];
			for (int i = 0; i < n; i++)
				y[--cnt[x[i].y]] = x[i];

			memset(cnt, 0, sizeof(int) * m);
			for (int i = 0; i < n; i++)
				cnt[y[i].x]++;
			for (int i = 1; i < m; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n - 1; ~i; i--)
				x[--cnt[y[i].x]] = y[i];
		}

		void build() {
			for (int i = 0; i < n; i++)
				rk[i] = str[i];
			for (int k = 1; k <= n; k <<= 1) {
				for (int i = 0; i + k < n; i++)
					T1[i] = Pair3(rk[i], rk[i + k], i);
				for (int i = n - k; i < n; i++)
					T1[i] = Pair3(rk[i], 0, i);
				radix_sort(T1, T2);
				int diff = 1;
				rk[T1[0].id] = 1;
				for (int i = 1; i < n; i++)
					rk[T1[i].id] = (T1[i].x == T1[i - 1].x && T1[i].y == T1[i - 1].y) ? (diff) : (++diff);
				if (diff == n)
					break;
			}
			for (int i = 0; i < n; i++)
				sa[--rk[i]] = i;
		}

		void get_height() {
			for (int i = 0, j, k = 0; i < n; i++, (k) ? (k--) : (0)) {
				if (rk[i]) {
					j = sa[rk[i] - 1];
					while (i + k < n && j + k < n && str[i + k] == str[j + k])	k++;
					hei[rk[i]] = k;
				}
			}		
		}

		void init_st() {
			st.init(n, hei);
		}

		int lcp(int x1, int x2) {
			if (x1 == x2)
				return n - x1;
			x1 = rk[x1], x2 = rk[x2];
			if (x1 > x2)
				swap(x1, x2);
			return st.query(x1 + 1, x2);
		}
		
		int compare(int l1, int r1, int l2, int r2) {
			int len_lcp = lcp(l1, l2);
			int len1 = r1 - l1 + 1, len2= r2 - l2 + 1;
			if (len_lcp >= len1 && len_lcp >= len2)
				return (len1 == len2) ? (0) : ((len1 < len2) ? (-1) : (1));
			if (len_lcp < len1 && len_lcp < len2)
				return (str[l1 + len_lcp] < str[l2 + len_lcp]) ? (-1) : (1);
			return (len_lcp >= len1) ? (-1) : (1);
		}
		
		int query(int u, int v) {	// u, v -> sa
			if (u == v)
				return n - sa[u];
			return st.query(u + 1, v);
		}

		const int& operator [] (int p) {
			return sa[p];
		}

		const int& operator () (int p) {
			return hei[p];
		}
} SuffixArray;

typedef class Tree Tree;
typedef class HeavyChain HeavyChain;

typedef class Event {
	public:
		int x, y, id, sgn;	// 0 : modify, non-zero : query

		Event() {	}
		Event(int x, int y, int id) : x(x), y(y), id(id) {	}
		Event(int x, int y, int id, int sgn) : x(x), y(y), id(id), sgn(sgn) {	}

		boolean operator < (Event b) const {
			return (x ^ b.x) ? (x < b.x) : (id < b.id);
		}
} Event;

typedef class FenwickTree {
	public:
		int n;
		ll *ar;
		vector<pair<int, int> > Opt; 

		FenwickTree(int n) : n(n) {
			ar = new ll[(n + 1)];
			pfill(ar, ar + n + 1, 0ll);
		}
		
		void clear() {
			for (auto& e : Opt) {
				add(e.first, -e.second, false);
			}
			Opt.clear();
		}
		void add(int idx, int val, boolean pb = true) {
			if (pb) Opt.emplace_back(idx, val);
			for (++idx ; idx <= n; idx += (idx & (-idx))) {
				ar[idx] += val;
			}
		}
		ll query(int idx) {
			ll rt = 0;
			for (++idx ; idx; idx -= (idx & (-idx))) {
				rt += ar[idx];
			}
			return rt;
		}
		ll query(int l, int r) {
			return (l <= r) ? (query(r) - query(l - 1)) : (0);
		}
} FenwickTree;

FenwickTree fens (N << 1), fenc (N << 1);

class HeavyChain {
	public:
		int st, ed;
		Tree *tr;
		vector<Event> E, E1;
		
		HeavyChain(Tree* tr) : tr(tr) { 		}
		
		void add(Event e) {
//			cerr << st << " " << e.x << " " << e.y << " " << e.id << " " << e.sgn << '\n';
			E.push_back(e);
		}
		void add1(Event e) {
			E1.push_back(e);
		}
		int fix(int x) {
			x -= st;
			(x < 0) && (x = 0);
			(x > ed - st) && (x = ed - st);
			return x;
		}
		void dispose();
};

class Tree {
	public:
		int n;
		int dfs_clock;
		vector<int> G[N << 1];

		int chain_id[N << 1];
		int sz[N << 1], zson[N << 1], tp[N << 1];
		int in[N << 1], tour[N << 1], fa[N << 1], dep[N << 1];

		vector<HeavyChain> chain;

		Tree() {	}
		Tree(int n) : n(n), dfs_clock(0) {	}
		
		void add_edge(int u, int v) {
			G[u].push_back(v);
//			cerr << u << " " << v << '\n';
		}

		void dfs1(int p, int _fa) {
			int mx = -1, &id = zson[p];
			id = -1, fa[p] = _fa, sz[p] = 1;
			for (auto e : G[p]) {
				dfs1(e, p);
				sz[p] += sz[e];
				if (sz[e] > mx) {
					mx = sz[e];
					id = e;
				}
			}
		}

		void dfs2(int p, boolean ontop) {
			in[p] = ++dfs_clock;
			tour[in[p]] = p;
			if (ontop) {
				chain.push_back(HeavyChain(this));
				tp[p] = p;
				chain.back().st = dep[fa[p]], chain.back().ed = dep[p];
			} else {
				tp[p] = tp[fa[p]];
				chain.back().ed = dep[p];
			}
			chain_id[p] = (signed) chain.size() - 1;
			if (~zson[p]) {
				dfs2(zson[p], false);
			}
			for (auto& e : G[p]) {
				if (e != fa[p] && e != zson[p]) {
					dfs2(e, true);
				}
			}
		}

		void add_modify(int p, int x) {
			do {
				int id = chain_id[p];
				chain[id].add(Event(x, dep[p] - dep[fa[tp[p]]], 0));
				p = fa[tp[p]];
			} while (p);
		}

		void add_query(int p, int x, int y, int id) {
			do {
				int cid = chain_id[p];
				chain[cid].add(Event(x, chain[cid].fix(min(y, dep[p])), id, -1));
				p = fa[tp[p]];
			} while (p);
		}

		void add_modify1(int p, int x) {
			do {
				int id = chain_id[p];
				chain[id].add1(Event(x, chain[id].fix(dep[p]), 0));
				p = fa[tp[p]];
			} while (p);
		}

		void add_query1(int p, int x, int y, int id)  {
			do {
				int cid = chain_id[p];
				HeavyChain& ch = chain[cid];
				if (x > ch.st)
					ch.add1(Event(x - ch.st, ch.fix(min(y, dep[p])), id, 1));
				p = fa[tp[p]];
			} while (p);
		}
};

typedef class SegTreeNode {
	public:
		ll sum, tg;
		boolean clr;
		SegTreeNode *l, *r;
		
		void modify(int L, int R, ll v) {
			sum += (R - L + 1) * v;
			tg += v;
		}
		void push_down(int L, int R, int mid) {
			if (clr) {
				l->clr = true, l->sum = l->tg = 0;
				r->clr = true, r->sum = r->tg = 0;
				clr = false;
			}
			if (tg) {
				l->modify(L, mid, tg);
				r->modify(mid + 1, R, tg);
				tg = 0;
			}
		}
		void push_up() {
			sum = l->sum + r->sum;
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->sum = top->tg = 0;
			top->clr = false;
			top->l = top->r = NULL;
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
			build(rt, 1, n);
		}

		ll query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->sum;
			}
			int mid = (l + r) >> 1;
			p->push_down(l, r, mid);
			if (qr <= mid) {
				return query(p->l, l, mid, ql, qr);
			} else if (ql > mid) {
				return query(p->r, mid + 1, r, ql, qr);
			}
			return query(p->l, l, mid, ql, mid) + query(p->r, mid + 1, r, mid + 1, qr);
		}

		void modify(SegTreeNode* p, int l, int r, int ql, int qr, int v) {
			if (l == ql && r == qr) {
				p->modify(l, r, v);
				return;
			}
			int mid = (l + r) >> 1;
			p->push_down(l, r, mid);
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
			(r > n) && (r = n);
			if (l > r) return 0;
			return query(rt, 1, n, l, r);
		}
		void modify(int l, int r, int v) {
			(r > n) && (r = n);
			if (l > r) {
//				cerr << "Warning" << '\n';
				return;
			}
			return modify(rt, 1, n, l, r, v);
		}
		void reset() {
			rt->clr = true;
			rt->sum = rt->tg = 0;
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

int n, m;
Tree *tr;
char str[N];
SuffixArray sa;

inline void init() {
	scanf("%s", str);
	n = strlen(str);
	sa.set(n, str);
	sa.build();
	sa.get_height();
	sa.init_st();
}

int cnt_node;
int node_id[N];
int build_suffix_tree(int l, int r) {
	int curid = ++cnt_node;
	int d = sa.query(l, r);
	tr->dep[curid] = d;
	if (l == r) {
		node_id[sa[l]] = curid;
		return curid;		
	}
	for (int p = l, j, L, R, mid; p <= r; p = j + 1) {
		L = p, R = r;
		int x = str[sa[p] + d];
		while (L <= R) {
			mid = (L + R) >> 1;
			if (str[sa[mid] + d] == x)
				L = mid + 1;
			else
				R = mid - 1;
		}
		j = L - 1;
		x = build_suffix_tree(p, j);
		tr->add_edge(curid, x);
	}
	return curid;
}

ll ans[N];
SegmentTree seg;

void HeavyChain :: dispose() {
	sort(E.begin(), E.end());
	int len = ed - st + 1;
	fens.clear();
	fenc.clear();
	for (auto& e : E) {
//		cerr << e.id << " " << e.x << " " << e.y << '\n';
		if (e.id) {
			ll tmp = fens.query(e.y) + (fenc.query(len) - fenc.query(e.y)) * e.y;
			ans[e.id] += tmp * e.sgn;
//			if (e.id == 2)
//				cerr << "I: " << e.id << " " << -tmp << '\n';
		} else {
			fens.add(e.y, e.y);
			fenc.add(e.y, 1);
		}
	}
//	cerr << fens.Opt.size() << '\n';
//	cerr << fens.Opt[1].first << '\n';

//	cerr << st << '\n';

	// forward scanning, lenx <= lenl
	sort(E1.begin(), E1.end(), [&] (const Event& a, const Event& b) {
		return (a.y ^ b.y) ? (a.y < b.y) : (a.id < b.id);		
	});
	seg.reset();
	for (auto& e : E1) {
//		if (!e.id)
//			cerr << st << " " << e.id << " " << e.x << " " << e.y << " " << e.id << '\n';
		if (e.id) {
			ans[e.id] += seg.query(1, e.x);
//			cerr << "II part1 : " << e.id << " " << seg.query(1, e.x) << '\n';
		} else {
			seg.modify(e.x + 1, e.y + e.x, 1);
		}
	}

	// backward scanning, lenx > lenl
	reverse(E1.begin(), E1.end());
	fens.clear();
	fenc.clear();
	for (auto& e : E1) {
//		cerr << st << " id: " << e.id << " " << e.x << " " << e.y << " " << e.id << '\n';
		if (e.id) {
			ll tmp = 0;
			int c = 0, L = max(0, e.x - e.y);
			c = fenc.query(L, e.x);
			tmp = e.x * 1ll * c - fens.query(L, e.x);
			tmp += e.y * 1ll * fenc.query(0, L - 1);
//			if (e.id == 2)
//				cerr << "II part2 : " << e.id << " " << tmp << '\n';
			ans[e.id] += tmp;
		} else {
			fens.add(e.x, e.x);
			fenc.add(e.x, 1);
		}
	}
}

inline void solve() {
	tr = new Tree(n);
	build_suffix_tree(0, n - 1);
	tr->dfs1(1, 0);
	tr->dfs2(1, true);
	for (int i = 0; i < n; i++) {
		tr->add_modify(node_id[i], i);
		tr->add_modify1(node_id[i], i);
	}
	
	int l, r;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &l, &r);
		--l, --r;
		tr->add_query1(node_id[l], r + 1, r - l + 1, i);
		if (l) {
			tr->add_query(node_id[l], l - 1, r - l + 1, i);
		}
	}
	seg.build(n + 5);
	for (auto &ch : tr->chain) {
		ch.dispose();
	}
	for (int i = 1; i <= m; i++) {
		printf(Auto"\n", ans[i]);
	}
}

int main() {
	init();
	solve();
	return 0;
}