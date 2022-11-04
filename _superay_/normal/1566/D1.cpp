#include <bits/stdc++.h>
using namespace std;
int n, m, a[305], pos[305];
pair<int, int> b[305];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) scanf("%d", &a[i]), b[i] = make_pair(a[i], -i);
		sort(b + 1, b + 1 + m);
		for (int i = 1; i <= m; i++) pos[-b[i].second] = i;
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j < i; j++) if (pos[j] < pos[i]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}