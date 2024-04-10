#include<bits/stdc++.h>

using namespace std;

const int MX = 10000;

int a[100][100], r[MX], c[MX], x[MX], t[MX];

int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", t + i);
		if (t[i] == 3) {
			scanf("%d %d %d", r + i, c + i, x + i);
		}
		else scanf("%d", x + i);
	}
	
	for (int i = q - 1; i >= 0; i--) {
		if (t[i] == 1) {
			int save = a[x[i] - 1][m - 1];
			for (int j = m - 1; j > 0; j--) a[x[i] - 1][j] = a[x[i] - 1][j - 1];
			a[x[i] - 1][0] = save;
		}
		else if (t[i] == 2) {
			int save = a[n - 1][x[i] - 1];
			for (int j = n - 1; j > 0; j--) a[j][x[i] - 1] = a[j - 1][x[i] - 1];
			a[0][x[i] - 1] = save;
		}
		else {
			a[r[i] - 1][c[i] - 1] = x[i];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
	
	return 0;
}