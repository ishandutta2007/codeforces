#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;
const int inf = (signed) (~0u >> 2);

typedef class SegTreeNode {
	public:
		int v;
		SegTreeNode *l, *r;

		SegTreeNode() : l(NULL), r(NULL) {	}

		void push_up() {
			v = min(l->v, r->v);
		}
} SegTreeNode;

SegTreeNode pool[N << 1];
SegTreeNode *_top = pool;

typedef class SegmentTree {
	public:
		int n;
		SegTreeNode* rt;
		
		void build(SegTreeNode* &p, int l, int r, int* key) {
			p = _top++;
			if (l == r) {
				p->v = key[l];
				return;
			}
			int mid = (l + r) >> 1;
			build(p->l, l, mid, key);
			build(p->r, mid + 1, r, key);
			p->push_up();
		}
		void build(int n, int* key) {
			this->n = n;
			build(rt, 1, n, key);
		}

		int query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->v;
			}
			int mid = (l + r) >> 1;
			if (qr <= mid) {
				return query(p->l, l, mid, ql, qr);
			} else if (ql > mid) {
				return query(p->r, mid + 1, r, ql, qr);
			}
			int a = query(p->l, l, mid, ql, mid);
			int b = query(p->r, mid + 1, r, mid + 1, qr);
			return min(a, b);
		}
		int query(int l, int r) {
			if (l > r)
				return inf;
			return query(rt, 1, n, l, r);
		}

		void modify(SegTreeNode* p, int l, int r, int idx, int v) {
			if (l == r) {
				p->v = v;
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
		void modify(int idx, int v) {
			modify(rt, 1, n, idx, v);
		}
} SegmentTree;

#define pii pair<int, int>
#define ll long long

int n;
SegmentTree st;
vector<pii> G[N];

int g;
ll dep[N];
int sz[N];

int get_sz(int p, int fa) {
	sz[p] = 1;
	for (auto e : G[p])
		if (e.first ^ fa)
			sz[p] += get_sz(e.first, p);
	return sz[p];
}

int get_G(int p, int fa) {
	for (auto e : G[p])
		if ((e.first ^ fa) && ((sz[e.first] << 1) > n))
			return get_G(e.first, p);
	return p;
}

int dfc;
int in[N], out[N], id[N], tour[N];
void dfs(int p, int fa, int fw, int _id) {
	id[p] = _id;
	dep[p] = dep[fa] + fw;
	in[p] = ++dfc, tour[in[p]] = p;
	for (auto E : G[p]) {
		int e = E.first;
		int w = E.second;
		if (e ^ fa) {
			dfs(e, p, w, _id);
		}
	}
	out[p] = dfc;
}

int pans[N];
int rin[N], rout[N];
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v, w; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	get_sz(1, 0);
	g = get_G(1, 0);
	get_sz(g, 0);
	++dfc;
	id[g] = g;
	tour[1] = g;
	rin[g] = rout[g] = 1;
	priority_queue<pii> Q, D;
	for (auto E : G[g]) {
		int e = E.first;
		dfs(e, g, E.second, e);
		rin[e] = rout[e] = sz[e];
		Q.push(pii(rin[e] + rout[e], e));
	}
	st.build(n, tour);
	ll ans = 0;
	in[g] = out[g] = 0;
//	cerr << "grav: " << g << '\n';
	for (int p = 1, q, idp, idq; p <= n; p++) {
		idp = id[p];
		while (!Q.empty() && !D.empty() && Q.top() == D.top())
			Q.pop(), D.pop();
//		assert(Q.top().first <= n - p + 1);
		if (!Q.empty() && Q.top().first == n - p + 1 && (idq = Q.top().second) != idp) {
			q = st.query(in[idq], out[idq]);
		} else {
			q = st.query(1, in[idp] - 1);
			q = min(q, st.query(out[idp] + 1, n));
		}
		idq = id[q];
		if (p ^ g) D.push(pii(rin[idp] + rout[idp], idp));
		if (q ^ g) D.push(pii(rin[idq] + rout[idq], idq));
		rin[idp]--;
		rout[idq]--;
		st.modify(in[q], inf);
		if (p ^ g) Q.push(pii(rin[idp] + rout[idp], idp));
		if (q ^ g) Q.push(pii(rin[idq] + rout[idq], idq));
		pans[p] = q;
		ans += dep[p] + dep[q];
//		cerr << p << " " << q << '\n';
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) {
		printf("%d ", pans[i]);
	}
	return 0;
}