#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5;

int n, q, a[maxn];
int t[4 * maxn];

void build(int v, int l, int r) {
	if(l == r) t[v] = a[l];
	else {
		int m = (l + r) >> 1;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m + 1, r);
		t[v] = __gcd(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

void upd(int v, int l, int r, int pos, int x) {
	if(l == r) t[v] = x;
	else {
		int m = (l + r) >> 1;
		if(pos <= m) upd(v * 2 + 1, l, m, pos, x);
		else upd(v * 2 + 2, m + 1, r, pos, x);
		t[v] = __gcd(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

int root, rootl, rootr;

int get1(int v, int l, int r, int l1, int r1, int x) {
	if(r1 < l || r < l1) return 0;
	if(l1 <= l && r <= r1)
		if(t[v] % x != 0) { root = v, rootl = l, rootr = r; return 1; }
		else return 0;
	int m = (l + r) >> 1;
	return get1(v * 2 + 1, l, m, l1, r1, x) + get1(v * 2 + 2, m + 1, r, l1, r1, x);
}

bool get2(int v, int l, int r, int x) {
	if(l == r) return true;
	int m = (l + r) >> 1;
	if(t[v * 2 + 1] % x != 0 && t[v * 2 + 2] % x != 0) return false;
	if(t[v * 2 + 1] % x != 0) return get2(v * 2 + 1, l, m, x);
	else return get2(v * 2 + 2, m + 1, r, x);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(0, 0, n - 1);
	cin >> q;
	while(q--) {
		int type; cin >> type;
		if(type == 1) {
			int l, r, x; cin >> l >> r >> x; l--; r--;
			int z = get1(0, 0, n - 1, l, r, x);
			if(z == 0) { cout << "YES\n"; continue; }
			if(z > 1) { cout << "NO\n"; continue; }
			cout << (get2(root, rootl, rootr, x) ? "YES\n" : "NO\n");
		} else {
			int pos, x; cin >> pos >> x; pos--;
			upd(0, 0, n - 1, pos, x);
		}
	}
}