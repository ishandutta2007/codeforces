#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	ignore = scanf("%d %d", &n, &k);
	
	map<int, int> cnt;
	cnt[0]++;
	for (int i = 0, s = 0, x; i < n; i++) {
		ignore = scanf("%d", &x);
		s ^= x;
		cnt[s]++;
	}
	
	long long ans = n * (n + 1ll) / 2;
	
	for (auto p : cnt) {
		int x = p.first, c = p.second;
		int y = x ^ ((1 << k) - 1);
		int d = cnt[y];
		
		int f = c + d;
		ans -= (f / 2) * (f / 2 - 1ll) / 2;
		ans -= ((f + 1) / 2) * ((f + 1) / 2 - 1ll) / 2;
		
		cnt[x] = cnt[y] = 0;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}