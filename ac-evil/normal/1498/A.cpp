#include <bits/stdc++.h>
typedef long long LL;
int T; LL n;
LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	//freopen("ques.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		while (1) {
			LL _n = n; int sum = 0;
			while (_n) sum += _n % 10, _n /= 10;
			if (gcd(n, sum) > 1) { printf("%lld\n", n); break; }
			n++;
		}
	}
	return 0;
}