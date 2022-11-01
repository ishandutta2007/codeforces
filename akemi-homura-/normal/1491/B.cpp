#include <bits/stdc++.h>
using namespace std;
int n, u, v, a[105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &u, &v);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = 2100000000;
		for (int i = 1; i < n; i++) {
			if (abs(a[i] - a[i + 1]) > 1) ans = 0;
		}
		if (ans) {
			for (int i = 1; i <= n; i++) {
				int has = 0;
				if (i > 1 && a[i] != a[i - 1]) has = 1;
				if (i < n && a[i] != a[i + 1]) has = 1;
				if (has) {
					ans = min(ans, min(u, v));
				} else {
					ans = min(ans, v + min(u, v));
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}