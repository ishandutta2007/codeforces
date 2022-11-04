#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, a[N], b[N], c[N], d[N];
bool vis[N * N];
pair<int, int> l1[N * N], l2[N * N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= m; i++) scanf("%d%d", &c[i], &d[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cx = max(0, c[j] - a[i] + 1), cy = max(0, d[j] - b[i] + 1);
			l1[(i - 1) * m + j] = make_pair(cx, (i - 1) * m + j);
			l2[(i - 1) * m + j] = make_pair(cy, (i - 1) * m + j);
		}
	}
	sort(l1 + 1, l1 + 1 + n * m);
	sort(l2 + 1, l2 + 1 + n * m);
	int ans = min(l2[n * m].first, l1[n * m].first);
	for (int x = 1, y = n * m; x <= n * m; x++) {
		vis[l1[x].second] = 1;
		while (y > 0 && vis[l2[y].second]) y--;
		ans = min(ans, l1[x].first + l2[y].first);
	}
	printf("%d\n", ans);
	return 0;
}