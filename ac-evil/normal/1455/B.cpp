#include <bits/stdc++.h>
int T, x;
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &x);
		int ans = 1;
		for (; ; ans++) {
			if (1LL*(ans+1)*ans/2 == x || 1LL*(ans-1)*ans/2-1 <= x && x <= 1LL*(ans+1)*ans/2-2) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}