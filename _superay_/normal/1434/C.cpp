#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
inline long long calc(long long i) {
	return -(i + 1) * a + (i + 1) * i / 2 * b * d;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (a > b * c) {
			puts("-1");
			continue;
		}
		long long t = c / d;
		long long lo = 0, hi = t;
		while (hi - lo > 0) {
			long long mid = (lo + hi) / 2;
			if (calc(mid) > calc(mid + 1)) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		long long ans = calc(hi);
		printf("%lld\n", -ans);
	}
	return 0;
}