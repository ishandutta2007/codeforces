#include <bits/stdc++.h>
using std::min;
typedef long long LL;
const int M = 20000005;
int T, c, d, x;
int check[M], p[M], pr[M];
void sieve() {
	pr[1] = 0;
	for (int i = 2; i <= M; i++) {
		if (!check[i]) p[++p[0]] = i, pr[i] = 1;
		for (int j = 1; j <= p[0] && i * p[j] <= M; j++) {
			check[i * p[j]] = 1;
			if (!(i % p[j])) {
				pr[i * p[j]] = pr[i];
				break;
			}
			pr[i * p[j]] = pr[i] + 1;
		}
	}
}
LL work(int x) {
	return 1LL << pr[x];
}
int main() {
	scanf("%d", &T);
	sieve();
	while (T--) {
		LL ans = 0;
		scanf("%d%d%d", &c, &d, &x);
		for (int i = 1; i * i <= x; i++) {
			if (x % i) continue;
			int t = i, y = x / t + d;
			if (!(y % c)) ans += work(y / c);
			if (i * i == x) continue;
			t = x / i; y = x / t + d;
			if (!(y % c)) ans += work(y / c);
		}
		printf("%lld\n", ans);
	}
	return 0;
}