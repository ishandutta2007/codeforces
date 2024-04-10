#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const long long INF = 9e18 + 10;

int m, k;
long long n, x, s;
long long a[N], b[N], c[N], d[N];

bool ok (long long t) {
	long long need = n;
	int pos = upper_bound(d + 1, d + k + 1, s) - d - 1;
	need -= c[pos];
	if (t/x >= need) return 1;

	for (int i = 1; i <= m; ++i) {
		if (b[i] > s) continue;
		long long need = n;
		long long rem = s - b[i];
		int pos = upper_bound(d + 1, d + k + 1, rem) - d - 1;
		need -= c[pos];
		if (t/a[i] >= need) return 1;
	}

	return 0;
}

int main (int argc, char const *argv[]) {
	c[0] = 0;
	scanf("%lld %d %d", &n, &m, &k);
	scanf("%lld %lld", &x, &s);
	for (int i = 1; i <= m; ++i) scanf("%lld", a + i);
	for (int i = 1; i <= m; ++i) scanf("%lld", b + i);
	for (int i = 1; i <= k; ++i) scanf("%lld", c + i);
	for (int i = 1; i <= k; ++i) scanf("%lld", d + i);

	long long lo = 0, hi = INF;
	while (lo < hi) {
		long long mid = (lo + hi)/2LL;
		if (ok(mid)) hi = mid;
		else lo = mid + 1;
	}

	printf("%lld\n", lo);
	return 0;
}