#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	long long ans = 0;
	for (int i = 0, S = 0, x; i < n; i++) {
		ignore = scanf("%d", &x);
		int t = min(S, x / 2);
		ans += t;
		S -= t;
		x -= 2 * t;
		ans += x / 3;
		x %= 3;
		S += x;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}