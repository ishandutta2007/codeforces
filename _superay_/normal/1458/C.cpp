#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005], ans[1005][1005], p[4], c[4];
char str[100005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]), a[i][j]--;
		scanf(" %s", str + 1);
		p[1] = 1, p[2] = 2, p[3] = 3;
		c[1] = c[2] = c[3] = 0;
		for (int i = 1; i <= m; i++) {
			if (str[i] == 'R') {
				c[2] = (c[2] + 1) % n;
			} else if (str[i] == 'L') {
				c[2] = (c[2] - 1 + n) % n;
			} else if (str[i] == 'D') {
				c[1] = (c[1] + 1) % n;
			} else if (str[i] == 'U') {
				c[1] = (c[1] - 1 + n) % n;
			} else if (str[i] == 'I') {
				swap(p[2], p[3]);
				swap(c[2], c[3]);
			} else {
				swap(p[1], p[3]);
				swap(c[1], c[3]);
			}
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			int b[4];
			b[1] = i, b[2] = j, b[3] = a[i][j];
			ans[(b[p[1]] + c[1]) % n][(b[p[2]] + c[2]) % n] = (b[p[3]] + c[3]) % n + 1;
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) printf("%d%c", ans[i][j], " \n"[j == n - 1]);
	}
	return 0;
}