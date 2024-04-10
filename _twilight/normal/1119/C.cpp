#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 505;

int n, m;
char A[N][N], B[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1, x; j <= m; j++) {
			scanf("%d", &x);
			A[i][j] = x;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1, x; j <= m; j++) {
			scanf("%d", &x);
			B[i][j] = x;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				A[i][j] ^= 1;
				A[i + 1][j] ^= 1;
				A[i][j + 1] ^= 1;
				A[i + 1][j + 1] ^= 1; 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i][j] != B[i][j]) {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}