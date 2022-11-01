#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5;

struct node {
	int lo, hi;
	ll sum;
};

node merge(node a, node b) {
	return {min(a.lo, b.lo), max(a.hi, b.hi), a.sum + b.sum};
}

node t[4 * maxn];
int n, m, a[maxn];

void build(int v, int l, int r) {
	if(l == r) t[v] = {a[l], a[l], a[l]};
	else {
		int m = (l + r) >> 1;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m + 1, r);
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

void push(int v, int len) {
	if(t[v].lo != t[v].hi) return;
	int x = t[v].lo;
	t[v * 2 + 1].lo = t[v * 2 + 1].hi = t[v * 2 + 2].lo = t[v * 2 + 2].hi = x;
	t[v * 2 + 1].sum = ll((len + 1) >> 1) * x;
	t[v * 2 + 2].sum = ll(len >> 1) * x;
}

ll get(int v, int l, int r, int l1, int r1) {
	if(r < l1 || r1 < l) return 0;
	if(l1 <= l && r <= r1) return t[v].sum;
	push(v, r - l + 1);
	int m = (l + r) >> 1;
	return get(v * 2 + 1, l, m, l1, r1) + get(v * 2 + 2, m + 1, r, l1, r1);
}

void upd1(int v, int l, int r, int l1, int r1, int x) {
	if(r < l1 || r1 < l || t[v].hi < x) return;
	if(l1 <= l && r <= r1 && t[v].lo == t[v].hi) {
		int y = t[v].lo % x;
		t[v] = {y, y, ll(r - l + 1) * y};
		return;
	}
	push(v, r - l + 1);
	int m = (l + r) >> 1;
	upd1(v * 2 + 1, l, m, l1, r1, x);
	upd1(v * 2 + 2, m + 1, r, l1, r1, x);
	t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

void upd2(int v, int l, int r, int pos, int x) {
	if(l == r) t[v] = {x, x, x};
	else {
		push(v, r - l + 1);
		int m = (l + r) >> 1;
		if(pos <= m) upd2(v * 2 + 1, l, m, pos, x);
		else upd2(v * 2 + 2, m + 1, r, pos, x);
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(0, 0, n - 1);
	while(m--) {
		int type; cin >> type;
		if(type == 1) {
			int l, r; cin >> l >> r; l--; r--;
			cout << get(0, 0, n - 1, l, r) << '\n';
		} else if(type == 2) {
			int l, r, x; cin >> l >> r >> x; l--; r--;
			upd1(0, 0, n - 1, l, r, x);
		} else {
			int k, x; cin >> k >> x; k--;
			upd2(0, 0, n - 1, k, x);
		}
	}
}