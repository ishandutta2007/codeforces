#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define ll long long

typedef class Node {
	public:
		ll f;
		ll tg_f;
		int tg_rk;
		int sz, rd, rk;

		Node *l, *r;

		void upd(ll df, int dk) {
			f += df;
			rk += dk;
			tg_f += df;
			tg_rk += dk;
		}
		void push_down() {
			if (tg_f || tg_rk) {
				if (l) l->upd(tg_f, tg_rk);
				if (r) r->upd(tg_f, tg_rk);
				tg_f = tg_rk = 0;
			}
		}
		void push_up() {
			sz = 1;
			if (l) sz += l->sz;
			if (r) sz += r->sz;
		}
		boolean check(ll a) {
			return f >= a * rk;
		}
} Node;

void split(Node* p, int a, Node* &L, Node* &R) {
	if (!p) {
		L = R = NULL;
		return;
	}
	p->push_down();
	if (p->check(a)) {
		split(p->r, a, (L = p)->r, R);
	} else {
		split(p->l, a, L, (R = p)->l);
	}
	p->push_up();
}
Node* merge(Node* a, Node* b) {
	if (!a) return b;
	if (!b) return a;
	a->push_down();
	b->push_down();
	if (a->rd < b->rd) {
		a->r = merge(a->r, b);
		a->push_up();
		return a;
	}
	b->l = merge(a, b->l);
	b->push_up();
	return b;
}

int n;
Node pool[N];
Node* _top = pool;

Node* newnode(ll f, int rk) {
	_top->f = f, _top->rk = rk;
	_top->l = _top->r = NULL;
	_top->rd = rand();
	_top->sz = 1;
	return _top++;
}

ll ans = 0, cur = 0;
void calc(Node* p) {
	if (!p) return;
	p->push_down();
	calc(p->l);
	ans = max(ans, cur += p->f);
	calc(p->r);
}

int main() {
	scanf("%d", &n);
	Node* rt = newnode(0, 0), *a, *b, *np;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		split(rt, x, a, b);
		np = newnode(a->sz * 1ll * x, a->sz);
		if (b)
			b->upd(x, 1);
		a = merge(a, np);
		rt = merge(a, b);
	}
	calc(rt);
	printf("%lld\n", ans);
	return 0;
}