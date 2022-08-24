#include<cstdio>
#include<algorithm>
using namespace std;
int n, c, w[20], D[20][2];
long long a;
int main() {
	int i, j, k, l;
	scanf("%lld", &a);
	for (i = 0; i < 15; i++) {
		w[i+1] = a % 10;
		a /= 10;
	}
	for (i = 0; i <= 15; i++)for (j = 0; j < 2; j++)D[i][j] = -1e9;
	D[0][0] = 0;
	for (i = 1; i <= 15; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 10; k++) {
				for (l = 0; l < 10; l++) {
					if ((j + k + l) % 10 == w[i]) {
						D[i][(j + k + l) / 10] = max(D[i][(j + k + l) / 10], D[i-1][j] + k + l);
					}
				}
			}
		}
	}
	printf("%d\n", D[15][0]);
}