#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[305 * 305];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n * m; i++) scanf("%d", &a[i].first), a[i].second = i;
		sort(a + 1, a + 1 + n * m);
		for (int i = 1; i <= n * m; i++) a[i].second *= -1;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			sort(a + (i - 1) * m + 1, a + i * m + 1);
			for (int j = 1; j <= m; j++) {
				for (int k = 1; k < j; k++) if (a[(i - 1) * m + j].second < a[(i - 1) * m + k].second) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}