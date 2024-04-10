#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
long long d[N], x[N], f[N], g[N], stk[N];
pair<long long, long long> ar1[N], ar2[N];
set<long long> st;
int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n + 1; i++) {
		scanf("%lld", &x[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		d[i] *= 2;
	}
	int tp = 0;
	f[0] = 1e18;
	stk[0] = 0;
	for (int i = 1; i <= n; i++) {
		while (x[i] > f[stk[tp]]) {
			tp--;
		}
		if (d[i] > x[i] - x[stk[tp]]) {
			f[i] = x[i] + (d[i] - (x[i] - x[stk[tp]]));
			if (f[i] >= x[n + 1]) {
				puts("0");
				return 0;
			}
			while (f[stk[tp]] <= f[i]) tp--;
			stk[++tp] = i;
		} else f[i] = -1e18;
	}
	tp = 0;
	g[n + 1] = -1e18;
	stk[0] = n + 1;
	for (int i = n; i >= 1; i--) {
		while (x[i] < g[stk[tp]]) {
			tp--;
		}
		if (d[i] > x[stk[tp]] - x[i]) {
			g[i] = x[i] - (d[i] - (x[stk[tp]] - x[i]));
			while (g[stk[tp]] >= g[i]) tp--;
			stk[++tp] = i;
		} else g[i] = 1e18;
	}
	long long ans = x[n + 1] - x[0];
	int t1 = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i] != -1e18) {
			ans = min(ans, x[n + 1] - x[i]);
			ar1[++t1] = make_pair(f[i], x[i]);
		}
	}
	int t2 = 0;
	for (int i = 1; i <= n; i++) {
		if (g[i] != 1e18) {
			ans = min(ans, x[i] - x[0]);
			ar2[++t2] = make_pair(g[i], x[i]);
		}
	}
	sort(ar1 + 1, ar1 + 1 + t1);
	sort(ar2 + 1, ar2 + 1 + t2);
	for (int i = 1, j = 1; i <= t1; i++) {
		while (j <= t2 && ar2[j].first <= ar1[i].first) {
			st.insert(ar2[j].second);
			j++;
		}
		auto it = st.upper_bound(ar1[i].second);
		if (it != st.end()) {
			ans = min(ans, (*it) - ar1[i].second);
		}
	}
	printf("%.10lf\n", ans / 2.0);
	return 0;
}