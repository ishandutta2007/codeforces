#include <bits/stdc++.h>
using namespace std;
const int N = 150005;
struct Node {
	int p, t;
	double val, l, r;
} a[N];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].p);
	long long T = 0, ct = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].t), a[i].val = 1.0 * a[i].p / a[i].t, T += a[i].t;
	sort(a + 1, a + 1 + n, [&](const Node &a, const Node &b) { return a.val > b.val; });
	for (int i = 1, j; i <= n; i = j) {
		for (j = i; j <= n && fabs(a[i].val - a[j].val) < 1e-10; j++);
		for (int k = i; k < j; k++) a[k].l = 1.0 * a[k].p * (ct + a[k].t) / T;
		for (int k = i; k < j; k++) ct += a[k].t;
		for (int k = i; k < j; k++) a[k].r = 1.0 * a[k].p * ct / T;
	}
	sort(a + 1, a + 1 + n, [&](const Node &a, const Node &b) { return a.p < b.p; });
	double ans = 1;
	for (int i = 1, j; i < n; i++) if (a[i].p < a[i + 1].p) {
		double l = 1e18, r = -1e18;
		for (j = i; j >= 1 && a[i].p == a[j].p; j--) l = min(l, a[j].l);
		for (j = i + 1; j <= n && a[i + 1].p == a[j].p; j++) r = max(r, a[j].r);
		if (l + 1e-10 < r) ans = min(ans, (a[i].p - a[i + 1].p) / (l - r));
	}
	printf("%.10lf\n", ans);
	return 0;
}