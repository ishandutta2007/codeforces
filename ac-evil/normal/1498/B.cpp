#include <bits/stdc++.h>
using std::sort;
typedef long long LL;
int T, n, W, cnt[21];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &W);
		for (int i = 0; i < 20; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			for (int j = 0; j < 20; j++)
				if (x == 1 << j) { cnt[j]++; break; }
		}
		int ans = 0;
		for (;;) {
			int ok = 0;
			for (int i = 0; i < 20; i++)
				if (cnt[i]) { ok = 1; break; }
			if (!ok) break;
			ans++;
			int now = W;
			for (int i = 19; ~i; i--)
				while (now >= 1 << i && cnt[i]) cnt[i]--, now -= 1 << i;
		}
		printf("%d\n", ans);
	}
	return 0;
}