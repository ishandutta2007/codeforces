#include<bits/stdc++.h>
using namespace std;

const int N = 15;

int n, a[N], f[N][2][2];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int tot = 0;
		while (n) a[++tot] = n % 10, n /= 10;
		memset(f, 0, sizeof(f));
		f[0][0][0] = 1;
		for (int i = 0; i < tot; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++) if (f[i][j][k]) {
					for (int l = 0; l <= 9; l++) {
						if (l + j <= a[i + 1]) {
							f[i + 1][k][0] += f[i][j][k];
						}
						else {
							f[i + 1][k][1] += f[i][j][k];
						}
					}
				}
		printf("%d\n", f[tot][0][0] - 2);
	}
	return 0;
}