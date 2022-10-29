#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

#define ll long long

typedef class SkewNode {
	public:
		ll w, tg;
		int id;
		SkewNode *l, *r;

		SkewNode() {	}
		SkewNode(ll w, int id) : w(w), tg(0), id(id), l(NULL), r(NULL) {	}

		void modify(ll d) {
			w += d;
			tg += d;
		}
		void push_down() {
			if (tg) {
				if (l) l->modify(tg);
				if (r) r->modify(tg);
				tg = 0;
			}
		}
} SkewNode;

SkewNode pool[N];
SkewNode *_top = pool;

SkewNode* newnode(ll w, int id) {
	*_top = SkewNode(w, id);
	return _top++;
}

SkewNode* merge(SkewNode* a, SkewNode* b) {
	if (!a) return b;
	if (!b) return a;
	a->push_down();
	b->push_down();
	if (a->w > b->w)
		swap(a, b);
	a->l = merge(a->l, b);
	swap(a->l, a->r);
	return a;
}

int n, m;
ll f[N];
SkewNode* g[N];
vector<int> G[N], H[N];
int d[N], s[N], t[N], w[N];
void dfs(int p, int fa) {
	SkewNode *&rt = g[p];
	ll sum = 0;
	d[p] = d[fa] + 1;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs(e, p);
			sum += f[e];
		}
	}
	for (auto e : G[p]) {
		if (e ^ fa) {
			SkewNode* q = g[e];
			q->modify(sum - f[e]);
			rt = merge(rt, q);
		}
	}
	for (auto id : H[p]) {
		rt = merge(rt, newnode(w[id] + sum, id));
	}
	if (fa) {
		while (rt && d[t[rt->id]] >= d[p]) {
			rt->push_down();
			rt = merge(rt->l, rt->r);
		}
		if (!rt) {
			throw 1;
		}
		f[p] = rt->w;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", s + i, t + i, w + i);
		H[s[i]].push_back(i);
	}
	try {
		dfs(1, 0);
	} catch (int) {
		puts("-1");
		return 0;
	}
	ll ans = 0;
	for (auto e : G[1]) {
		ans += f[e];
	}
	printf("%lld\n", ans);
	return 0;
}