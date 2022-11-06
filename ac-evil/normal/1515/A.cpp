#include <bits/stdc++.h>
const int N = 105;
int T, n, x, w[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		int sum = 0, ok = 1;
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);//, sum += w[i];
			// if (i > 1 && w[i] != w[i - 1]) ok = 0;
		}
		std::sort(w + 1, w + n + 1);
		for (int i = 1; i <= n; i++) {
			sum += w[i];
			if (sum == x) {
				if (i < n) std::swap(w[i], w[n]);
				else ok = 0;
				break;
			}
		}
		if (ok) {
			puts("YES");
			for (int i = 1; i <= n; i++) printf("%d ", w[i]);
			puts("");
		} else puts("NO");
	}
	return 0;
}