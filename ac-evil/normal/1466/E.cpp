#include <bits/stdc++.h>
typedef long long LL;
const int N = 500005, P = 1e9 + 7;
int T, n, cnt[70];
LL x[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 0; i < 60; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
			for (int j = 0; j < 60; j++) cnt[j] += (x[i] >> j) & 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int tot1 = 0, tot2 = 0;
			for (int j = 0; j < 60; j++)
				if (x[i] & (1LL << j)) {
					tot1 = (tot1 + (1LL<<j)%P*cnt[j]) % P;
					tot2 = (tot2 + (1LL<<j)%P*n) % P;
				} else
					tot2 = (tot2 + (1LL<<j)%P*cnt[j]) % P;
			ans = (ans + 1LL*tot1*tot2) % P;
		}
		printf("%d\n", ans);
	}
	return 0;
}