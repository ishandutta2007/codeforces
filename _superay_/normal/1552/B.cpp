#include <bits/stdc++.h>
using namespace std;
int n, r[50005][5];
inline bool Better(int x, int y) {
	int ret = 0;
	for (int j = 0; j < 5; j++) ret += (r[x][j] < r[y][j]);
	return ret >= 3;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) for (int j = 0; j < 5; j++) scanf("%d", &r[i][j]);
		int ans = 1;
		for (int i = 2; i <= n; i++) {
			if (Better(i, ans)) ans = i;
		}
		for (int i = 1; i <= n; i++) if (ans != i && !Better(ans, i)) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}