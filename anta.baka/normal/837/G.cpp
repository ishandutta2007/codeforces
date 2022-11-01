#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
	ll sum;
	node *l, *r;
};

typedef node *pnode;

pnode build(int l, int r) {
	pnode res = new node;
	if(l == r) {
		res->sum = 0;
		res->l = res->r = NULL;
	} else {
		int m = (l + r) / 2;
		res->l = build(l, m);
		res->r = build(m + 1, r);
		res->sum = res->l->sum + res->r->sum;
	}
	return res;
}

pnode upd(pnode v, int l, int r, int pos, int x) {
	pnode res = new node;
	if(l == r) {
		res->sum = v->sum + x;
		res->l = res->r = NULL;
	} else {
		int m = (l + r) / 2;
		if(pos <= m) {
			res->l = upd(v->l, l, m, pos, x);
			res->r = v->r;
		} else {
			res->l = v->l;
			res->r = upd(v->r, m + 1, r, pos, x);
		}
		res->sum = res->l->sum + res->r->sum;
	}
	return res;
}

ll get(pnode v, int l, int r, int l1, int r1) {
	if(r < l1 || r1 < l)
		return 0;
	if(l1 <= l && r <= r1)
		return v->sum;
	int m = (l + r) / 2;
	return get(v->l, l, m, l1, r1) + get(v->r, m + 1, r, l1, r1);
}

const int ro = 2e5 + 1;
const int mod = 1e9;

int n, q;
vector<pnode> rt1, rt2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cin.tie(0);
	rt1.push_back(build(0, ro));
	rt2.push_back(build(0, ro));
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x1, x2, y1, a, b, y2;
		cin >> x1 >> x2 >> y1 >> a >> b >> y2;
		pnode root = rt1.back();
		root = upd(root, 0, ro, 0, y1);
		root = upd(root, 0, ro, x1 + 1, b - y1);
		root = upd(root, 0, ro, x2 + 1, y2 - b);
		rt1.push_back(root);
		root = rt2.back();
		root = upd(root, 0, ro, x1 + 1, a);
		root = upd(root, 0, ro, x2 + 1, -a);
		rt2.push_back(root);
	}
	cin >> q;
	ll last = 0;
	while(q--) {
		int l, r, x;
		cin >> l >> r >> x;
		x = (x + last) % mod;
		ll x1 = min(x, ro);
		last = (get(rt2[r], 0, ro, 0, x1) - get(rt2[l - 1], 0, ro, 0, x1)) * x + (get(rt1[r], 0, ro, 0, x1) - get(rt1[l - 1], 0, ro, 0, x1)); // ??
		cout << last << '\n';
	}
}