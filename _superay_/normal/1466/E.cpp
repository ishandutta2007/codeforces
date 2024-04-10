#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int mod = 1000000007;
int n, cnt[60];
long long a[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			for (int j = 0; j < 60; j++) if (a[i] >> j & 1) cnt[j]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int r1 = 0, r2 = 0;
			for (int j = 0; j < 60; j++) if (a[i] >> j & 1) {
				r1 = (r1 + (1ll << j) % mod * cnt[j]) % mod;
			}
			for (int j = 0; j < 60; j++) {
				if (a[i] >> j & 1) r2 = (r2 + (1ll << j) % mod * n) % mod;
				else r2 = (r2 + (1ll << j) % mod * cnt[j]) % mod;
			}
			ans = (ans + 1ll * r1 * r2) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}