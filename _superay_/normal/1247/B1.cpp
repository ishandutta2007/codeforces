#include <bits/stdc++.h>
using namespace std;
int n, k, d;
int a[200005], c[1000005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &k, &d);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int tp = 0;
		for (int i = 1; i < d; i++) {
			c[a[i]]++;
			if (c[a[i]] == 1) tp++;
		}
		int ans = k + 1;
		for (int i = d; i <= n; i++) {
			c[a[i]]++;
			if (c[a[i]] == 1) tp++;
			if (i > d) {
				c[a[i - d]]--;
				if (!c[a[i - d]]) tp--;
			}
			ans = min(ans, tp);
		}
		for (int i = n - d + 1; i <= n; i++) c[a[i]]--;
		printf("%d\n", ans);
	}
	return 0;
}