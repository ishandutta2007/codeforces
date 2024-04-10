#include <bits/stdc++.h>
const int N = 505, P = 998244353;
int T, n, a[N * 2][N * 2], ban[N * 2], use[N * 2], cnt[N * 2], fa[N * 2], exist[N * 2], ok[N][N];
int fset(int x) { return fa[x] == x ? x : fa[x] = fset(fa[x]); }
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n * 2; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n * 2; i++) ban[i] = use[i] = 0;
		for (int i = 1, tmp = 1; tmp <= n; i = i % n + 1, tmp++) {
			for (int j = 1; j <= n; j++) cnt[j] = 0;
			for (int j = 1; j <= n * 2; j++)
				if (!ban[j]) cnt[a[j][i]]++;
			for (int j = 1; j <= n * 2; j++)
				if (!ban[j] && !use[j] && cnt[a[j][i]] == 1) {
					// printf("%d %d\n", i, j);
					use[j] = 1;
					for (int k = 1; k <= n * 2; k++)
						if (j != k && !ban[k] && !use[k]) {
							for (int l = 1; l <= n; l++)
								if (a[j][l] == a[k][l]) { ban[k] = 1; tmp = 0; break; }
						}
				}
		}
		for (int i = 1; i <= n * 2; i++) fa[i] = i;
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) cnt[i] = 0;
			for (int i = 1; i <= n * 2; i++) {
				if (ban[i]) continue;
				if (cnt[a[i][j]] == 0) cnt[a[i][j]] = i;
				else fa[fset(i)] = fset(cnt[a[i][j]]);
			}
		}
		int tot = 0;
		for (int i = 1; i <= n * 2; i++) exist[i] = 0;
		for (int i = 1; i <= n * 2; i++) {
			if (ban[i]) continue;
			int j = fset(i); exist[j]++;
		}
		for (int i = 1; i <= n * 2; i++) tot += exist[i] > 1;
		// for (int i = 1; i <= n * 2; i++) printf("%d ", exist[i]); puts("");
		int ans = 1;
		for (int i = 1; i <= tot; i++) ans = ans * 2 % P;
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				ok[i][j] = 1;
		for (int i = 1, count = 0; i <= n * 2; i++) {
			if (ban[i]) continue;
			int flag = 1;
			if (!use[i])
				for (int j = 1; j <= n; j++)
					if (!ok[j][a[i][j]]) { flag = 0; break; }
			if (flag) {
				printf("%d ", i);
				count++;
				if (count == n) break;
				for (int j = 1; j <= n; j++)
					ok[j][a[i][j]] = 0;
			}
		}
		puts("");
		// for (int i = 1; i <= n * 2; i++) printf("%d ", ban[i]); puts("");
		// puts("ok");
	}
	return 0;
}