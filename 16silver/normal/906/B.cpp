#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	if (m == 1) {
		if (n == 1) printf("YES\n1");
		else if (n < 4) printf("NO\n");
		else {
			printf("YES\n");
			for (i = 2; i <= n; i += 2) printf("%d\n", i);
			for (i = 1; i <= n; i += 2) printf("%d\n", i);
		}
	}
	else if (m == 2) {
		if (n < 4) printf("NO\n");
		else {
			printf("YES\n");
			if (n & 1) {
				for (i = 2; i <= n; i += 2) printf("%d %d\n", i * 2 - 3, i * 2);
				printf("%d %d\n", 2 * n - 1, 2);
				for (i = 2; i <= n; i += 2) printf("%d %d\n", i * 2 - 1, i * 2 + 2);
			}
			else {
				for (i = 2; i <= n; i += 2) printf("%d %d\n", i * 2 - 1, (n + 1 - i) * 2);
				for (i = 1; i <= n; i += 2) printf("%d %d\n", i * 2 - 1, (n + 1 - i) * 2);
			}
		}
	}
	else if (m == 3) {
		if (n < 3) printf("NO\n");
		else if (n == 3) {
			printf("YES\n5 3 7\n1 8 6\n9 4 2\n");
		}
		else {
			printf("YES\n");
			if (n & 1) {
				for (i = 2; i <= n; i += 2) printf("%d %d %d\n", i * 3 - 5, i * 3 - 1, i * 3 - 3);
				printf("%d %d %d\n", 3 * n - 2, 2, 3 * n);
				for (i = 2; i <= n; i += 2) printf("%d %d %d\n", i * 3 - 2, i * 3 + 2, i * 3);
			}
			else {
				for (i = 2; i <= n; i += 2) printf("%d %d %d\n", i * 3 - 2, (n + 1 - i) * 3 - 1, i * 3);
				for (i = 1; i <= n; i += 2) printf("%d %d %d\n", i * 3 - 2, (n + 1 - i) * 3 - 1, i * 3);
			}
		}
	}
	else {
		printf("YES\n");
		if (m & 1) {
			for (i = 0; i < n; i++) {
				if (i & 1) {
					for (j = 1; j <= m; j += 2) printf("%d ", j + i*m);
					for (j = 2; j <= m; j += 2) printf("%d ", j + i*m);
				}
				else {
					for (j = 2; j <= m; j += 2) printf("%d ", j + i*m);
					for (j = 1; j <= m; j += 2) printf("%d ", j + i*m);
				}
				printf("\n");
			}
		}
		else {
			for (i = 0; i < n; i++) {
				if (i & 1) {
					for (j = 2; j <= m; j += 2) printf("%d ", j + i*m);
					for (j = 1; j <= m; j += 2) printf("%d ", j + i*m);
				}
				else {
					for (j = m - 1; j > 0; j -= 2) printf("%d ", j + i*m);
					for (j = m; j > 0; j -= 2) printf("%d ", j + i*m);
				}
				printf("\n");
			}
		}
	}
}