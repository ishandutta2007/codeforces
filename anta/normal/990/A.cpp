#include "bits/stdc++.h"
using namespace std;

int main() {
	long long n; long long m; int a; int b;
	while (~scanf("%lld%lld%d%d", &n, &m, &a, &b)) {
		auto ans = min(n % m * b, (m - 1 - (n - 1) % m) * a);
		printf("%lld\n", ans);
	}
}