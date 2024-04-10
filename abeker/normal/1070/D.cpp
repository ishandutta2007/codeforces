#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	ll rest = 0, ans = 0;
	while (N--) {
		ll x;
		scanf("%lld", &x);
		x += rest;
		if (!N) {
			ans += (x + K - 1) / K;
			break;
		}
		if (x < K && rest) {
			ans++;
			rest = 0;
			continue;
		}
		ans += x / K;
		rest = x % K;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}