#include <bits/stdc++.h>

using namespace std;

const int MX = 20;

int cnt[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0, x; i < n; i++) {
		ignore = scanf("%d", &x);
		for (int j = 0; j < MX; j++) {
			cnt[j] += x & 1;
			x /= 2;
		}
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < MX; j++) {
			if (cnt[j] > i) s += 1 << j;
		}
		
		ans += s * 1LL * s;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}