#include <bits/stdc++.h>
using std::sort; using std::vector; using std::min; using std::lower_bound;
typedef long long LL;
const int N = 30005, SZ = N * 5;
int T, n, c, Q, a[N]; LL w[N][5];
LL C(int n, int m) {
	LL res = 1;
	for (int i = n; i > n - m; i--)
		res = res * i / (n - i + 1);
	return res;
}
struct Node { int l, r; LL w; };
struct Queue {
	Node a[SZ]; int l, r;
	void clr() { l = r = 0; }
	void B(Node x) { a[r++] = x; r %= SZ; }
	void F(Node x) { if (!l) l = SZ; a[--l] = x; }
} q[5];
int ql[N][5], qr[N][5];
vector<LL> val[5];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &c, &Q);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= c; i++)
			val[i].clear(), q[i].clr(), q[i].B({0, 0, 1});
		for (int i = 0; i <= n; i++) {
			w[i][0] = 1;
			for (int j = 1; j <= c; j++)
				w[i][j] = w[i][j - 1] + (i ? C(i - 1, j) : 0);
		}
		for (int i = n; i; i--) {
			int m = min(c, n - i), b[m + 1];
			for (int j = 1; j <= m; j++) b[j] = j;
			sort(b + 1, b + m + 1, [&](int x, int y) { return a[i + x] < a[i + y]; });
			for (int j = m; j; j--)
				if (a[i + b[j]] < a[i])
					for (int k = b[j]; k <= c; k++)
						q[k].F({i, i + b[j], w[n - (i + b[j])][k - b[j]]});
			for (int j = 1; j <= m; j++)
				if (a[i + b[j]] > a[i])
					for (int k = b[j]; k <= c; k++)
						q[k].B({i, i + b[j], w[n - (i + b[j])][k - b[j]]});
			for (int j = 1; j <= c; j++)
				ql[i][j] = q[j].l, qr[i][j] = q[j].r;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= c; j++)
				ql[i][j] = (ql[i][j] - q[j].l + SZ) % SZ, qr[i][j] = (qr[i][j] - q[j].l + SZ) % SZ;
		for (int i = 1; i <= c; i++) {
			for (int j = q[i].l; j != q[i].r; j = (j + 1) % SZ)
				val[i].push_back((val[i].size() ? val[i][val[i].size() - 1] : 0) + q[i].a[j].w);
		}
		while (Q--) {
			int x; LL y; scanf("%d%lld", &x, &y);
			if (w[n][c] < y) { puts("-1"); continue; }
			int i = c, now = 1;
			for (;;) {
			    if (!i) { printf("%d\n", a[x]); break; }
				LL y0 = ql[now][i] ? val[i][ql[now][i] - 1] : 0;
				int pos = lower_bound(val[i].begin() + ql[now][i], val[i].begin() + qr[now][i], y + y0) - val[i].begin();
				Node tmp = q[i].a[(q[i].l + pos) % SZ];
				if (!tmp.l || x <= tmp.r) {
					printf("%d\n", !tmp.l || x < tmp.l ? a[x] : a[tmp.r - x + tmp.l]);
					break;
				}
				y -= val[i][pos] - y0 - w[n - tmp.r][i - (tmp.r - tmp.l)], i -= tmp.r - tmp.l, now = tmp.r + 1;
			}
		}
	}
	return 0;
}