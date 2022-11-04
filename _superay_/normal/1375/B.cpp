#include <bits/stdc++.h>
using namespace std;
int a[305][305];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
		int bad = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int cur = 4 - (i == 1 || i == n) - (j == 1 || j == m);
				if (a[i][j] > cur) {
					bad = 1;
				}
				a[i][j] = cur;
			}
		}
		if (bad) puts("NO");
		else {
			puts("YES");
			for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) printf("%d%c", a[i][j], " \n"[j == m]);
		}
	}
	return 0;
}