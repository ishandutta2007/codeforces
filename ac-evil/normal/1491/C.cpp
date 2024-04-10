#include <bits/stdc++.h>
using std::min; using std::max;
typedef long long LL;
const int N = 5005;
int T, n, a[N]; LL cnt[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		LL ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			ans += max(a[i] - cnt[i] - 1, 0LL);
			for (int j = 2; j <= min(n - i, a[i]); j++) cnt[i + j]++;
			cnt[i + 1] += max(0LL, cnt[i] - a[i] + 1);
		}
		//for (int i = 1; i <= n; i++) printf("%d ", cnt[i]);
		printf("%lld\n", ans);
	}
	return 0;
}