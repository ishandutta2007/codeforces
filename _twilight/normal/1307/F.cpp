#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

const int N = 2e5 + 5, bzmax = 18;

typedef class SegTreeNode {
	public:
		int tg;
		SegTreeNode *l, *r;
		
		SegTreeNode() : tg(-1), l(NULL), r(NULL) {	}
		SegTreeNode(SegTreeNode* self) : tg(-1), l(self), r(self) {	}
} SegTreeNode;

SegTreeNode pool[N * 60];
SegTreeNode* top = pool;
SegTreeNode nul (&nul);

#define nul &nul

SegTreeNode* newnode() {
	top->l = top->r = NULL;
	return top++;
}

int n, m, K, q;
int dep[N];
int bz[N][bzmax];
vector<int> G[N];

void cover(SegTreeNode* pa, SegTreeNode*& pb, int l, int r, int ql, int qr, int v) {
	pb = newnode();
	*pb = *pa;
	if ((ql ^ l) || (qr ^ r)) {
		int mid = (l + r) >> 1;
		if (qr <= mid) {
			cover(pa->l, pb->l, l, mid, ql, qr, v);
		} else if (ql > mid) {
			cover(pa->r, pb->r, mid + 1, r, ql, qr, v);
		} else {
			cover(pa->l, pb->l, l, mid, ql, mid, v);
			cover(pa->r, pb->r, mid + 1, r, mid + 1, qr, v);
		}
	} else {
		pb->tg = v;
	}
}
void cover(SegTreeNode* pa, SegTreeNode*& pb, int ql, int qr, int v) {
	vmin(qr, n - 1);
	if (ql <= qr) {
		cover(pa, pb, 0, n - 1, ql, qr, v);
	} else {
		pb = pa;
	}
}

int query(SegTreeNode* p, int l, int r, int idx) {
	if (p == nul)
		return -1;
	int rt = p->tg, cmp = 0;
	if (l ^ r) {
		int mid = (l + r) >> 1;
		if (idx <= mid) {
			cmp = query(p->l, l, mid, idx);
		} else {
			cmp = query(p->r, mid + 1, r, idx);
		}
	}
	return max(rt, cmp);
}
int query(SegTreeNode* p, int idx) {
	return query(p, 0, n - 1, idx);
}

int us[N], vs[N], f1[N], f2[N];

int near[N], near2[N];
boolean can_rest[N];
void dfs(int p, int fa) {
	dep[p] = dep[fa] + 1;
	near[p] = (can_rest[p]) ? (dep[p]) : (N << 1);
	bz[p][0] = fa;
	for (int i = 1; i < bzmax; i++) {
		bz[p][i] = bz[bz[p][i - 1]][i - 1];
	}
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs(e, p);
			vmin(near[p], near[e]);		
		}
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	for (int d = dep[u] - dep[v], i = 0; d; d >>= 1, i++) {
		if (d & 1) {
			u = bz[u][i];
		}
	}
	if (u == v)
		return u;
	for (int i = bzmax, x, y; i--; ) {
		x = bz[u][i], y = bz[v][i];
		if (x ^ y) {
			u = x;
			v = y;
		}
	}
	return bz[u][0];
}

void work_near2() {
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		near2[i] = -1;
	for (int i = 1; i <= n; i++) {
		if (can_rest[i]) {
			near2[i] = 0;
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int p = Q.front();
		Q.pop();
		for (auto e : G[p]) {
			if (near2[e] == -1) {
				near2[e] = near2[p] + 1;
				Q.push(e);
			}
		}
	}
}

typedef class Query {
	public:
		int g, *ans; 

		Query(int g, int* ans) : g(g), ans(ans) {	}
} Query;

SegTreeNode* rts[N];
vector<Query> Qs[N];

vector<int> stk;
void solve(int p, int fa) {
	stk.push_back(p);
	int sfa = query(rts[fa], dep[p]);
	sfa = (sfa < 0) ? (p) : (stk[sfa]);
	bz[p][0] = sfa;
	for (int i = 1; i < bzmax; i++)
		bz[p][i] = bz[bz[p][i - 1]][i - 1];
	for (auto x : Qs[p]) {
		int q = x.g;
		int dq = dep[q];
		int u = p;
		for (int i = bzmax, t; i--; ) {
			t = bz[u][i];
			if (dep[t] >= dq) {
				u = t;
			}
		}
		*(x.ans) = near[u] - dq;
		if (near[u] - dq + near2[q] <= K) {
			vmin(*(x.ans), near2[q]);
		}
		vmin(*(x.ans), dep[p] - dq);
		if (dep[p] - dq + near2[q] <= K) {
			vmin(*(x.ans), near2[q]);
		}
	}

	int dr = near[p], l = dr - dep[p];
	if (dr < n) {
		cover(rts[fa], rts[p], dr + 1, dr + K - (l << 1), dep[p]);
		sfa = query(rts[fa], dr);
		sfa = (sfa < 0) ? (p) : (stk[sfa]);
		bz[p][0] = sfa;
	} else {
		rts[p] = rts[fa];
		bz[p][0] = p;
	}
	for (int i = 1; i < bzmax; i++)
		bz[p][i] = bz[bz[p][i - 1]][i - 1];
	for (auto e : G[p]) {
		if (e ^ fa) {
			solve(e, p);		
		}
	}
	stk.pop_back();
}

int main() {
	scanf("%d%d%d", &n, &K, &m);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1, x; i <= m; i++) {
		scanf("%d", &x);
		can_rest[x] = true;
	}
	dep[0] = -1;
	dfs(1, 0);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", us + i, vs + i);
		int g = lca(us[i], vs[i]);
		Qs[us[i]].emplace_back(g, f1 + i);
		Qs[vs[i]].emplace_back(g, f2 + i);
	}
	work_near2();
	for (int i = 0; i <= n; i++) {
		rts[i] = nul;
	}
	solve(1, 0);
	for (int i = 1; i <= q; i++) {
		puts((f1[i] + f2[i] <= K) ? ("YES") : ("NO"));
	}
	return 0;
}