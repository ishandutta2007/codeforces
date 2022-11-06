#include <bits/stdc++.h>
typedef long long LL;
const int N = 200005;
int T, n; LL k, x[N];
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		LL d = x[2] - x[1];
		for (int i = 3; i <= n; i++) d = gcd(d, x[i] - x[i-1]);
		printf("%s\n", (k - x[1]) % d == 0 ? "YES" : "NO");
	}
	return 0;
}