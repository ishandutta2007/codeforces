#include<cstdio>
#include<algorithm>
using namespace std;
int D[510][51000], res, N = 500, n;
int main() {
	int i, j;
	scanf("%d", &n);
	if (n > 500) {
		printf("%lld\n", n * 49ll - 247);
		return 0;
	}
	D[0][0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= (i - 1) * 50; j++) {
			D[i][j + 50] |= D[i-1][j];
			D[i][j + 10] |= D[i-1][j];
			D[i][j + 5] |= D[i-1][j];
			D[i][j + 1] |= D[i-1][j];
		}
	}
	for (i = 1; i <= n * 50; i++)if (D[n][i])res++;
	printf("%d\n", res);
}