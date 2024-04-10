#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long x, y, k;
		scanf("%lld%lld%lld", &x, &y, &k);
		long long lim = k * (y + 1);
		printf("%lld\n", (lim - 1 + x - 1 - 1) / (x - 1) + k);
	}
	return 0;
}