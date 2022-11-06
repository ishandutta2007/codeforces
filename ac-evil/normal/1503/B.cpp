#include <bits/stdc++.h>
const int N = 105;
int n, col, ok[N][N];
int ask() {
	int x; scanf("%d", &x); return x;
}
void go(int c, int i, int j) {
	printf("%d %d %d\n", c, i, j);
	ok[i][j] = c;
	fflush(stdout);
}
int main() {
	scanf("%d", &n);
	memset(ok, 0, sizeof ok);
	int cnt1 = 0, cnt2 = 0, over1 = 0, over2 = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if ((i + j) & 1) over2++; else over1++;
	for (int i = 1; i <= n * n; i++) {
		col = ask();
		if (cnt1 < over1 && cnt2 < over2) {
			if (col == 1) {
				for (int x = 1; x <= n; x++)
					for (int y = 1; y <= n; y++)
						if (((x + y) & 1) && !ok[x][y]) {
							go(2, x, y); cnt2++; goto end;
						}
			} else {
				for (int x = 1; x <= n; x++)
					for (int y = 1; y <= n; y++)
						if (!((x + y) & 1) && !ok[x][y]) {
							go(1, x, y); cnt1++; goto end;
						}
			}
		} else {
			for (int x = 1; x <= n; x++)
				for (int y = 1; y <= n; y++)
					if (!ok[x][y]) {
						if (cnt1 == over1) {
							if (col == 2) {
								go(3, x, y);
							} else {
								go(2, x, y);
							}
						} else {
							if (col == 1) {
								go(3, x, y);
							} else {
								go(1, x, y);
							}
						}
						goto end;
					}
		}
		end:;
		// printf("%d %d %d %d\n", cnt1, over1, cnt2, over2);
	}
	return 0;
}