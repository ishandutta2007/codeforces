#include <bits/stdc++.h>
using namespace std;
int n, a[105], b[105], c[105], ans[105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
		ans[1] = a[1];
		for (int i = 2; i < n; i++) {
			if (a[i] == ans[i - 1]) {
				ans[i] = b[i];
			} else ans[i] = a[i];
		}
		if (a[n] != ans[n - 1] && a[n] != ans[1]) {
			ans[n] = a[n];
		} else if (b[n] != ans[n - 1] && b[n] != ans[1]) ans[n] = b[n];
		else ans[n] = c[n];
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}