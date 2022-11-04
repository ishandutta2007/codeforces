#include <bits/stdc++.h>
using namespace std;
int n, a[400005], b[400005], p[400005], vis[400005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++) p[a[i]] = b[i], vis[i] = 0;
		int ans = 1;
		for (int i = 1; i <= n; i++) if (!vis[i]) {
			ans = 2 * ans % 1000000007;
			int j = i;
			while (!vis[j]) {
				vis[j] = 1;
				j = p[j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}