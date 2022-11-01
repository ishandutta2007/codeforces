#include <stdio.h>
int main() {
	int x[50][50], N, i, j, k, l, r = 1, p;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &x[i][j]);
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			p = 0;
			if (x[i][j] == 1) p = 1;
			for (k = 0; k < N; k++) {
				for (l = 0; l < N; l++) {
					if (x[i][j] == x[k][j] + x[i][l]) p = 1;
				}
			}
			if (p == 0) r = 0;
		}
	}
	if (r == 0) {
		printf("No");
	}
	else printf("Yes");
}