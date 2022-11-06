#include <bits/stdc++.h>
const int N = 105;
int T, n, x, w[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n & 1) { puts("NO"); continue; }
		int tmp1 = sqrt(n / 2), tmp2 = sqrt(n / 4);
		if (tmp1 * tmp1 == n / 2 || tmp2 * tmp2 * 4 == n) puts("YES");
		else puts("NO");
	}
	return 0;
}