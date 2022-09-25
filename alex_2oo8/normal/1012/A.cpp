#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int a[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) ignore = scanf("%d", a + i);
	
	sort(a, a + 2 * n);
	
	long long ans = (a[n - 1] - a[0]) * 1ll * (a[2 * n - 1] - a[n]);
	
	for (int i = n; i < 2 * n - 1; i++) {
		long long x = (a[2 * n - 1] - a[0]) * 1ll * (a[i] - a[i - n + 1]);
		ans = min(ans, x);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}