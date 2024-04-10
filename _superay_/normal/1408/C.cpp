#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, l, a[N];
double t1[N], t2[N];
inline bool check(double mid) {
	int i, j;
	for (i = 1; i < n + 1; i++) if (t1[i] > mid) break;
	for (j = n; j > 0; j--) if (t2[j] > mid) break;
	double x = a[i - 1] + (mid - t1[i - 1]) * i;
	double y = a[j + 1] - (mid - t2[j + 1]) * (n + 1 - j);
	return x < y;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &l);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		a[0] = 0;
		a[n + 1] = l;
		t1[0] = 0;
		for (int i = 1; i <= n + 1; i++) {
			t1[i] = t1[i - 1] + 1.0 * (a[i] - a[i - 1]) / i;
		}
		t2[n + 1] = 0;
		for (int i = n; i >= 0; i--) {
			t2[i] = t2[i + 1] + 1.0 * (a[i + 1] - a[i]) / (n + 1 - i);
		}
		double lo = 0, hi = l;
		for (int t = 0; t < 60; t++) {
			double mid = (lo + hi) / 2.0;
			if (check(mid)) lo = mid;
			else hi = mid;
		}
		printf("%.10lf\n", hi);
	}
	return 0;
}