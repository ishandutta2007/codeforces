#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char p[120], A[10100][120], B[10100][120], res[120];
int SA[110], SB[110], Z[110];
int main() {
	int i, j;
	scanf("%d", &n);

	printf("? %d %d\n", 1, n);
	fflush(stdout);
	if (n == 1) {
		scanf("%s", p);
		printf("! %s\n", p);
		fflush(stdout);
		return 0;
	}
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
	printf("! %s\n", res);

}