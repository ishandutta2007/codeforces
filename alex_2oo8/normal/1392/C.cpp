#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d", &n);
		
		long long ans = 0;
		for (int i = 0, x = 0, a; i < n; i++) {
			ignore = scanf("%d", &a);
			ans += max(x - a, 0);
			x = a;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}