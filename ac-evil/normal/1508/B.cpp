#include <bits/stdc++.h>
typedef long long LL;
int T, n; LL k;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &k);
		if (n <= 62 && 1LL << (n - 1) < k) { puts("-1"); continue; }
		for (int i = 1; i <= n; i++) {
			if (n - i >= 62) printf("%d ", i);
			else {
				for (int j = 0; j < 60; j++) {
					LL tmp = n - i - j - 1 >= 0 ? 1LL << (n - i - j - 1) : 1;
					if (tmp < k) k -= tmp;
					else {
						for (int k = i + j; k >= i; k--) printf("%d ", k);
						i += j; break;
					}
				}
			}
		}
		puts("");
	}
	return 0;
}