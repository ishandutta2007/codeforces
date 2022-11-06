#include <bits/stdc++.h>
const int N = 200005, M = 10000005;
int T, n, k, a[N], la[N], b[M];
int check[5005], p[5005];
void sieve() {
	for (int i = 2; i <= 5000; i++) {
		if (!check[i]) p[++p[0]] = i;
		for (int j = 1; j <= p[0] && i * p[j] <= 5000; j++) {
			check[i * p[j]] = 1;
			if (!(i % p[j])) break;
		}
	}
}
int main() {
	scanf("%d", &T);
	sieve();
	while (T--) {
		scanf("%d%d", &n, &k);
		int ans = 1, pt = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			for (int j = 1; j <= p[0]; j++) {
				int t = p[j] * p[j];
				if (t > a[i]) break;
				while (!(a[i] % t)) a[i] /= t;
			}
			la[i] = b[a[i]], b[a[i]] = i;
			if (la[i] >= pt) ans++, pt = i;
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++) b[a[i]] = 0;
	}
	return 0;
}