#include <bits/stdc++.h>
//#pragma GCC optimize ("unroll-loops")

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 2e5 + 42;
int n; 

int mn[4 * maxn], sub[4 * maxn];

void push(int v, int l, int r) {
	mn[v] -= sub[v];
	if(r - l > 1) {
		sub[2 * v] += sub[v];
		sub[2 * v + 1] += sub[v];
	}
	sub[v] = 0;
}

void upd(int p, int c, int v = 1, int l = 0, int r = n) {
	push(v, l, r);
	if(r - l == 1) {
		mn[v] = c;
	} else {
		int m = (l + r) / 2;
		if(p < m) {
			upd(p, c, 2 * v, l, m);
		} else {
			upd(p, c, 2 * v + 1, m, r);
		}
		push(2 * v, l, m);
		push(2 * v + 1, m, r);
		mn[v] = min(mn[2 * v], mn[2 * v + 1]);
	}
}

int get(int v = 1, int l = 0, int r = n) {
	push(v, l, r);
	if(r - l == 1) {
		return l;
	} else {
		int m = (l + r) / 2;
		push(2 * v, l, m);
		push(2 * v + 1, m, r);
		if(mn[2 * v + 1] == 0) {
			return get(2 * v + 1, m, r);
		} else {
			return get(2 * v, l, m);
		}
	}
}

void ad(int a, int b, int c, int v = 1, int l = 0, int r = n) {
	push(v, l, r);
	if(a <= l && r <= b) {
		sub[v] += c;
		push(v, l, r);
	} else if(r <= a || b <= l) {
		return;
	} else {
		int m = (l + r) / 2;
		ad(a, b, c, 2 * v, l, m);
		ad(a, b, c, 2 * v + 1, m, r);
		mn[v] = min(mn[2 * v], mn[2 * v + 1]);
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		upd(i, t);
	}
	int ans[n];
	for(int i = 0; i < n; i++) {
		int x = get();
		upd(x, 1e18);
		ad(x, n, i + 1);
		ans[x] = i;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] + 1 << " \n"[i + 1 == n];
	}
}