#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, P, K;
map <int, int> cnt;

inline int add(int x, int y) {
	x += y;
	if (x >= P)
		return x - P;
	if (x < 0)
		return x + P;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % P;
}

inline int sqr(int x) {
	return mul(x, x);
}

int main() {
	scanf("%d%d%d", &N, &P, &K);
	ll ans = 0;
	while (N--) {
		int a;
		scanf("%d", &a);
		ans += cnt[add(sqr(sqr(a)), -mul(K, a))]++;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}