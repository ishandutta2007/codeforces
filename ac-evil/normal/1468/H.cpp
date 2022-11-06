#include <bits/stdc++.h>
const int N = 200005;
int T, n, k, m, a[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
		if (((n-m) % (k-1))) { puts("NO"); continue; }
		int ok = 0;
		for (int i = 1; i <= m; i++)
			if (a[i]-i >= k/2 && n+i-m-a[i] >= k/2) { ok = 1; break; }
		puts(ok ? "YES" : "NO");
	}
	return 0;
}