#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, r1, r2, r3, d, a[N];
long long p1[N], p2[N], f[N];
int main() {
	scanf("%d%d%d%d%d", &n, &r1, &r2, &r3, &d);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		p1[i] = min(min(1ll * r1 * a[i] + r3, 1ll * r1 * (a[i] + 2) + 2ll * d), 1ll * r2 + 1ll * r1 + 2ll * d);
		p2[i] = min(min(1ll * r1 * a[i] + r3, 1ll * r1 * (a[i] + 2)), 1ll * r2 + 1ll * r1);
	}
	f[0] = 0;
	long long mn = 1e18;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + p1[i];
		if (i > 1) {
			mn = min(mn, f[i - 2] - 2ll * d * (i - 1) + p2[i - 1]) + p2[i];
		}
		f[i] = min(f[i], mn + 2ll * d * i);
	}
	long long sum = 0;
	for (int i = n; i >= 1; i--) {
		if (i < n) sum += p2[i];
		else sum += p1[i];
		f[n] = min(f[n], f[i - 1] + sum + 1ll * d * (n - i));
	}
	printf("%lld\n", f[n] + 1ll * d * (n - 1));
	return 0;
}