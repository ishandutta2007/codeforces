#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long pw[N], val[N << 2], add[N << 2], laz[N << 2];
int n, q, a[N];
long long calc(long long a) {for(int i = 1; i <= 9; i++) if(pw[i] >= a) return pw[i] - a; assert(0);}
void pushup(int x) {val[x] = min(val[x << 1], val[x << 1 | 1]);}
void tagmo(int x, long long v) {val[x] = calc(laz[x] = v), add[x] = 0;}
void tagad(int x, long long v) {if(laz[x]) val[x] = calc(laz[x] += v); else assert(val[x] >= v), val[x] -= v, add[x] += v;}
void pushdown(int x) {
	if(laz[x]) tagmo(x << 1, laz[x]), tagmo(x << 1 | 1, laz[x]), laz[x] = 0, assert(!add[x]);
	if(add[x]) tagad(x << 1, add[x]), tagad(x << 1 | 1, add[x]), add[x] = 0;
}
void build(int l, int r, int x) {
	if(l == r) return val[x] = calc(laz[x] = a[l]), void();
	int m = l + r >> 1;
	build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
	pushup(x); // add pushup =.=
}
void modifymo(int l, int r, int ql, int qr, int x, int v) {
	if(ql <= l && r <= qr) return tagmo(x, v);
	int m = l + r >> 1;
	pushdown(x);
	if(ql <= m) modifymo(l, m, ql, qr, x << 1, v);
	if(m < qr) modifymo(m + 1, r, ql, qr, x << 1 | 1, v);
	pushup(x);
}
void modifyad(int l, int r, int ql, int qr, int x, int v) {
	int m = l + r >> 1;
	if(ql <= l && r <= qr && (laz[x] || val[x] >= v)) return tagad(x, v);
	pushdown(x);
	if(ql <= m) modifyad(l, m, ql, qr, x << 1, v);
	if(m < qr) modifyad(m + 1, r, ql, qr, x << 1 | 1, v);
	pushup(x);
}
long long query(int p) {
	int l = 1, r = n, x = 1;
	while(l < r) {
		int m = l + r >> 1;
		pushdown(x);
		if(p <= m) r = m, x <<= 1;
		else l = m + 1, x = x << 1 | 1;
	}
	return laz[x];
}
int main() {
	cin >> n >> q, pw[0] = 1;
	for(int i = 1; i <= 9; i++) pw[i] = pw[i - 1] * 42;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, n, 1);
	for(int i = 1; i <= q; i++) {
		int op, l, r, x;
		cin >> op;
		if(op == 1) cin >> x, cout << query(x) << endl;
		if(op == 2) cin >> l >> r >> x, modifymo(1, n, l, r, 1, x);
		if(op == 3) {
			cin >> l >> r >> x;
			do modifyad(1, n, l, r, 1, x);
			while(val[1] == 0); 
		}
	}
	return 0;
}