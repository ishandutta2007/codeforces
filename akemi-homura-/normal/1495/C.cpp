#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[505][505];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf(" %s", a[i] + 1);
		for (int i = 1; i <= n; i += 3) {
			for (int j = 1; j <= m; j++) a[i][j] = 'X';
			if (i + 3 <= n) {
				int flag = 0;
				for (int j = 1; j <= m; j++) {
					if (a[i + 1][j] == 'X') {
						a[i + 2][j] = 'X';
						flag = 1;
						break;
					}
					if (a[i + 2][j] == 'X') {
						a[i + 1][j] = 'X';
						flag = 1;
						break;
					}
				}
				if (!flag) {
					a[i + 1][1] = a[i + 2][1] = 'X';
				}
			} else if (n % 3 == 0) {
				int lst = -1;
				for (int j = 1; j <= m; j++) {
					if (a[i + 1][j] == 'X') {
						for (int k = lst + 2; k <= j; k++) a[i + 2][k] = 'X';
						lst = j;
					}
				}
				if (lst != -1) {
					for (int k = lst; k <= m; k++) a[i + 2][k] = 'X';
				} else {
					a[i + 1][1] = 'X';
					for (int k = 1; k <= m; k++) a[i + 2][k] = 'X';
				}
			}
		}
		for (int i = 1; i <= n; i++) printf("%s\n", a[i] + 1);
	}
	return 0;
}