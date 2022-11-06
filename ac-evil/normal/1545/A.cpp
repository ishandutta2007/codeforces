#include <bits/stdc++.h>
const int N = 1e5 + 5;
int T, n, a[N], b[N], c[N][2];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), b[i] = a[i], c[a[i]][i & 1]++;
		std::sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++)
			c[b[i]][i & 1]--;
		int ok = 1;
		for (int i = 1; i <= n; i++) {
			if (c[a[i]][0] || c[a[i]][1]) ok = 0;
			c[a[i]][0] = c[a[i]][1] = 0;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}