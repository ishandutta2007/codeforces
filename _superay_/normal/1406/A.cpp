#include <bits/stdc++.h>
using namespace std;
int n, c[105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i <= 101; i++) {
			c[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			c[x]++;
		}
		int ans = 0, i, j;
		for (i = 0; i <= 101; i++) if (c[i] < 2) break;
		if (c[i] == 0) {
			ans = i + i;
		} else {
			for (j = i + 1; j <= 101; j++) if (c[j] < 1) break;
			ans = i + j;
		}
		printf("%d\n", ans);
	}
	return 0;
}