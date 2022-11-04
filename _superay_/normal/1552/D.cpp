#include <bits/stdc++.h>
using namespace std;
int n, a[15];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int ans = 0;
		for (int mask = 1; mask < (1 << n); mask++) {
			for (int nmask = mask; ; nmask = (nmask - 1) & mask) {
				int s = 0;
				for (int i = 0; i < n; i++) if (mask >> i & 1) {
					if (nmask >> i & 1) s += a[i];
					else s -= a[i];
				}
				if (!s) { ans = 1; break; }
				if (!nmask) break;
			}
			if (ans) break;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}