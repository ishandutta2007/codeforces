#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, a[N], mx[N], val[N];
long long d[N], s[N];
struct segtree {
	int val[N << 2];
	void init() {memset(val, 0xcf, (n + 2 << 2) << 2);}
	void modify(int l, int r, int p, int x, int v) {
		val[x] = max(val[x], v);
		if(l == r) return;
		int m = l + r >> 1;
		if(p <= m) modify(l, m, p, x << 1, v);
		else modify(m + 1, r, p, x << 1 | 1, v);
	}
	int query(int l, int r, int ql, int qr, int x) {
		if(ql > qr) return -1e9;
		if(ql <= l && r <= qr) return val[x];
		int m = l + r >> 1, ans = -1e9;
		if(ql <= m) ans = query(l, m, ql, qr, x << 1);
		if(m < qr) ans = max(ans, query(m + 1, r, ql, qr, x << 1 | 1));
		return ans;
	}
} x, y;
void solve() {
	cin >> n;
	x.init(), y.init(), d[0] = s[0] = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), d[i] = s[i] = s[i - 1] + a[i];
	sort(d, d + n + 1);
	for(int i = 0; i <= n; i++) s[i] = lower_bound(d, d + n + 1, s[i]) - d, val[i] = -1e9;
	val[s[0]] = 0, x.modify(0, n, s[0], 1, 0), y.modify(0, n, s[0], 1, 0);
	for(int i = 1; i <= n; i++) {
		int res = val[s[i]];
		res = max(res, x.query(0, n, 0, s[i] - 1, 1) + i);
		res = max(res, y.query(0, n, s[i] + 1, n, 1) - i);
		x.modify(0, n, s[i], 1, res - i);
		y.modify(0, n, s[i], 1, res + i);
		val[s[i]] = max(val[s[i]], res);
		if(i == n) cout << res << endl;
	}
}
int main() {
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}