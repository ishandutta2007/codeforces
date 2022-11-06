#include <bits/stdc++.h>
const int N = 105, M = 3e6 + 10, offset = 1.5e6 + 5, P = 1e9 + 7;
int n, c[N], b[N], f[M], g[M], Q, x;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i < n; i++)
		scanf("%d", &b[i]);
	scanf("%d%d", &Q, &x);
	int mx = c[1], mn = x;
	if (mx < 0) { puts("0"); return 0; }
	for (int i = std::max(0, mn); i <= mx; i++)
		f[i + offset] = 1;
	// for (int j = mn; j <= mx; j++)
		// printf("[%d]%d ", j, f[j + offset]);
	// puts("");
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += b[i];
		// delta = a - sum \in [i * b[i], c[i + 1] + i * b[i]]
		// f[i + delta] <- f[i]
		// f[j] <- f[j - delta] j - delta \in [j - i * b[i] - c[i + 1], j - i * b[i]]
		memset(g, 0, sizeof g);
		mx += c[i + 1] + i * b[i]; mn = std::max(-(int)1e6, (i + 1) * (x + sum));
		for (int j = mn - i * b[i] - c[i + 1] - 1; j <= mx - i * b[i]; j++)
			g[j + offset] = (g[j - 1 + offset] + f[j + offset]) % P;
		memset(f, 0, sizeof f);
		for (int j = mn; j <= mx; j++)
			f[j + offset] = (g[j - i * b[i] + offset] - g[j - i * b[i] - c[i + 1] - 1 + offset] + P) % P;
		// for (int j = mn; j <= mx; j++)
			// printf("[%d]%d ", j, f[j + offset]);
		// puts("");
	}
	int ans = 0;
	for (int i = n * (x + sum); i <= 1.5e6; i++)
		ans = (ans + f[i + offset]) % P;
	printf("%d\n", ans);
	return 0;
}