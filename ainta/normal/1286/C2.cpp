#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[120], A[10100][120], B[10100][120], res[120];
int SA[110], SB[110], Z[110], Pre[110];
int SS[110], Suf[110];
void Do(int n) {
	int i, j;
	printf("? %d %d\n", 1, n);
	fflush(stdout);
	for (i = 0; i < n*(n + 1) / 2; i++) {
		scanf("%s", A[i]);
		int c = 0;
		for (j = 0; A[i][j]; j++)c += A[i][j] - 'a';
		int L = j;
		SA[L] += c;
	}
	printf("? %d %d\n", 1, n - 1);
	fflush(stdout);

	for (i = 0; i < n*(n - 1) / 2; i++) {
		scanf("%s", B[i]);
		int c = 0;
		for (j = 0; B[i][j]; j++)c += B[i][j] - 'a';
		int L = j;
		SB[L] += c;
	}

	for (i = 1; i <= n; i++) {
		Z[i] = SA[i] - SB[i];
		res[n - i] = Z[i] - Z[i - 1] + 'a';
	}

}
int main() {
	int i, j, k;
	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("? %d %d\n", 1, n);
		fflush(stdout);
		scanf("%s", p);
		printf("! %s\n", p);
		fflush(stdout);
		return 0;
	}
	if (n == 2) {

		printf("? %d %d\n", 1, 1);
		fflush(stdout);
		scanf("%s", p);
		res[0] = p[0];
		printf("? %d %d\n", 2, 2);
		fflush(stdout);
		scanf("%s", p);
		res[1] = p[0];
		res[2] = 0;
		printf("! %s\n", res);
		return 0;
	}

	Do((n + 1) / 2);

	printf("? %d %d\n", 1, n);
	fflush(stdout);

	for (i = 0; i < (n + 1) / 2; i++) {
		Pre[i + 1] = Pre[i] + res[i] - 'a';
	}

	for (i = 0; i < n*(n + 1) / 2; i++) {
		scanf("%s", A[i]);
		int c = 0;
		for (j = 0; A[i][j]; j++)c += A[i][j] - 'a';
		int L = j;
		SS[L] += c;
	}
	int tot = SS[n];

	for (i = 1; i <= n / 2; i++) {
		int z = SS[n-i];
		for (j = 1; j < i; j++) {
			int s = 0;
			for (k = 0; k < i - j; k++) {
				s += res[n - k - 1] - 'a';
			}
			z -= tot - (s + Pre[j]);
		}

		z -= (tot - Pre[i]);
		Suf[i] = tot - z;
		res[n - i] = Suf[i] - Suf[i - 1] + 'a';
	}
	printf("! %s\n", res);
	fflush(stdout);

}