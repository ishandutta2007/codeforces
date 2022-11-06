#include <bits/stdc++.h>
#define pb push_back
using std::vector;
int T, n;
vector<int> a, b;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		a.clear(), b.clear();
		for (int i = 1; i <= n * 2; i++) {
			int x, y; scanf("%d%d", &x, &y);
			if (x == 0) a.pb(abs(y));
			else b.pb(abs(x));
		}
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());
		double ans = 0;
		for (int i = 0; i < n; i++)
			ans += sqrt(1LL * a[i] * a[i] + 1LL * b[i] * b[i]);
		printf("%.10lf\n", ans);
	}
	return 0;
}