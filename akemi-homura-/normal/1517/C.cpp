#include <bits/stdc++.h>
using namespace std;
int n, p[505];
int ans[505][505];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		int x = i, y = i;
		ans[x][y] = p[i];
		for (int j = 0; j < p[i] - 1; j++) {
			if (y > 1 && !ans[x][y - 1]) y--;
			else x++;
			ans[x][y] = p[i];
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) printf("%d%c", ans[i][j], " \n"[j == i]);
	return 0;
}