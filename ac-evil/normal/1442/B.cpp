#include <bits/stdc++.h>
const int N = 2e5 + 5, P = 998244353;
int T, n, m, a[N], ia[N], b[N], la[N], ne[N], tag[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), ia[a[i]] = i;
		std::fill(tag + 1, tag + n + 1, 0);
		for (int i = 1; i <= m; i++)
			scanf("%d", &b[i]), tag[ia[b[i]]] = 1;
		tag[0] = tag[n + 1] = 1;
		for (int i = 1; i <= n; i++)
			la[i] = i - 1, ne[i] = i + 1;
		int ans = 1;
		for (int i = 1; i <= m; i++) {
			int u = ia[b[i]], x = la[u], y = ne[u];
			if (tag[x] && tag[y]) { ans = 0; break; }
			if (!tag[x] && !tag[y]) ans = ans * 2 % P;
			ne[x] = y; la[y] = x;
		}
		printf("%d\n", ans);
	}
	return 0;
}