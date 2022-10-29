#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 4e5 + 5;

#define ll long long

inline ll pw2(int x) {
	return 1ll * x * x;
}

typedef class SplayNode {
	public:
		int sz, vsz;
		ll sz2, vsz2;
		SplayNode *fa, *ch[2];

		SplayNode() : sz(0), vsz(0) {	}

		boolean isroot() {
			return !fa || (fa->ch[0] != this && fa->ch[1] != this);
		}
		int which() {
			return isroot() ? -1 : fa->ch[1] == this;
		}
		void upd(SplayNode* q, int sgn = 1) {
			sz += sgn * q->sz;
			sz2 += sgn * pw2(q->sz);		
		}
		void push_up() {
			sz = vsz + 1, sz2 = vsz2;
			if (ch[0])	upd(ch[0]);
			if (ch[1])	upd(ch[1]);
		}
} SplayNode;

typedef class LinkCutTree {
	public:
		ll ans;
		int *fa;
		vector<int> P;
		SplayNode* pool;
		boolean *havefa;

		void init(int n, int* fa, int* sz) {
			this->fa = fa;
			pool = new SplayNode[(n + 1)];
			havefa = new boolean[(n + 1)];
			pool[0].ch[0] = pool[0].ch[1] = NULL;
			pool[0].fa = NULL;
			pool[0].sz = n + 1, pool[0].vsz = n;
			for (int i = 0; i <= n; i++) {
				pool[i].sz2 = 0;
				havefa[i] = i != 0;
			}
			for (int i = 1; i <= n; i++) {
				pool[i].ch[0] = pool[i].ch[1] = NULL;
				pool[i].fa = pool + fa[i];
				pool[i].sz = sz[i], pool[i].vsz = sz[i] - 1;
				pool[i].fa->sz2 += pw2(sz[i]);
			}
			for (int i = 0; i <= n; i++) {
				pool[i].vsz2 = pool[i].sz2;
			}
			ans = 1ll * n * n;
		}

		void rotate(SplayNode* p) {
			int d = p->which();
			int df = p->fa->which();
			SplayNode* fa = p->fa;
			fa->ch[d] = p->ch[d ^ 1];
			p->ch[d ^ 1] = fa;
			if (~df)
				fa->fa->ch[df] = p;
			p->fa = fa->fa;
			fa->fa = p;
			if (fa->ch[d])
				fa->ch[d]->fa = fa;
			fa->push_up();
			p->push_up();
		}

		void splay(SplayNode* p) {
			for ( ; !p->isroot(); rotate(p)) {
				if (!p->fa->isroot()) {
					rotate((p->which() == p->fa->which()) ? (p->fa) : (p));
				}
			}
		}

		void access(SplayNode* p) {
			SplayNode* q = NULL;
			while (p) {
				splay(p);
				if (p->ch[1]) {
					p->vsz += p->ch[1]->sz;
					p->vsz2 += pw2(p->ch[1]->sz);
				}
				if (q) {
					p->vsz -= q->sz;
					p->vsz2 -= pw2(q->sz);
				}
				p->ch[1] = q;
				q = p, p = p->fa;
			}
		}

		ll query(SplayNode* p) {
			access(p);
			splay(p);
			if (!p->ch[0])
				return p->sz2;
			while (p->ch[0])
				p = p->ch[0];
			splay(p);
			return pw2(p->ch[1]->sz);
		}
		ll query(int x) {
			return query(pool + x);
		}

		void link(SplayNode* p, SplayNode* q) {
			access(p);
			splay(p);
			access(q);
			splay(q);
			p->fa = q;
			q->upd(p);
			q->vsz += p->sz;
			q->vsz2 += pw2(p->sz);
		}
		void link_fa(int p) {
			ans -= query(p);
			if (havefa[fa[p]])
				ans -= query(fa[p]);
			link(pool + p, pool + fa[p]);
			ans += query(p);
			havefa[p] = true;
		}

		void cut(SplayNode* p) {
			access(p);
			splay(p);
			assert(p->ch[0]);
			SplayNode* q = p->ch[0];
			p->upd(q, -1);
			p->ch[0] = q->fa = NULL;
		}
		void cut(int p) {
			ans -= query(p);
			cut(pool + p);
			ans += query(p);
			if (havefa[fa[p]])
				ans += query(fa[p]);
			havefa[p] = false;
			P.push_back(p);
		}

		void reverse(int p) {
			if (havefa[p]) {
				cut(p);
			} else {
				link_fa(p);
			}
		}

		void reset() {
			for (auto p : P) {
				if (!havefa[p]) {
					link_fa(p);
				}
			}
			P.clear();
		}
} LinkCutTree;

typedef class Event {
	public:
		int t, p;

		Event(int t, int p) : t(t), p(p) {	}
} Event;

int n, m;
ll res[N];
LinkCutTree lct;
vector<int> G[N];
vector<Event> E[N];
int c[N], fa[N], sz[N];

void dfs(int p, int fa) {
	::fa[p] = fa;
	sz[p] = 1;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs(e, p);
			sz[p] += sz[e];
		}
	}
}

void solve(vector<Event>& E) {
	ll lastans = lct.ans;
	res[0] += lastans;
	for (auto e : E) {
		int t = e.t;
		int p = e.p;
		res[t] -= lastans;
		lct.reverse(p);
		res[t] += (lastans = lct.ans);
//		cerr << t << " " << p << " " << lct.ans << " " << lct.pool[0].sz2 << '\n'; 
	}
	lct.reset();
//	cerr << "FIN: " << lct.ans << '\n';
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
		E[c[i]].emplace_back(0, i);
	}
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1, p, nc; i <= m; i++) {
		scanf("%d%d", &p, &nc);
		E[c[p]].emplace_back(i, p);
		E[c[p] = nc].emplace_back(i, p);
	}
	lct.init(n, fa, sz);
	for (int i = 1; i <= n; i++) {
		solve(E[i]);
	}
	ll n3 = 1ll * n * n * n, ans = 0;
	for (int i = 0; i <= m; i++) {
		ans += res[i];
		printf("%lld\n", n3 - ans);
	}
	return 0;
}