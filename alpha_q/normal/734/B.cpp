#include <bits/stdc++.h>

using namespace std;

long long x = 32, y = 256;
long long k2, k3, k5, k6;

int main (int argc, char const *argv[]) {
	scanf("%lld %lld %lld %lld", &k2, &k3, &k5, &k6);

	long long res = 0;
	for (int i = 0; i <= k2; ++i) {
		long long twox = (long long) i;
		long long twoy = k2 - twox;
		long long now = 0LL;
		long long z = min(twox, k3);
		now += x * z;
		z = min(twoy, min(k5, k6));
		now += y * z;
		res = max(res, now);
	}

	printf("%lld\n", res);
	return 0;
}