#include<cstdio>
#include<algorithm>
using namespace std;
int Up[1010][1010], Down[1010][1010];
int n, m;
char p[1010][1010];
long long res;
int main() {
	int i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i] + 1);
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			Up[i][j] = 1;
			if (p[i][j] == p[i - 1][j])Up[i][j] += Up[i - 1][j];
		}
	}
	for (i = n; i >= 1; i--) {
		for (j = 1; j <= m; j++) {
			Down[i][j] = 1;
			if (p[i][j] == p[i + 1][j])Down[i][j] += Down[i + 1][j];
		}
	}
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (Up[i][j] == 1) {
				int H = Up[i][j] + Down[i][j] - 1;
				int uu = i - 1, dd = i + Down[i][j];
				if (Up[uu][j] >= H && Down[dd][j] >= H) {
					int c = 1;
					res++;
					for (k = j + 1;; k++) {
						c++;
						if (p[i][k] == p[i][j] && p[uu][k] == p[uu][j] && p[dd][k] == p[dd][j] && Up[uu][k] >= H && Down[dd][k] >= H && Up[i][k] == Up[i][j] && Down[i][k] == Down[i][j]) {
							res += c;
						}
						else break;
					}
					j = k - 1;
				}
			}
		}
	}
	printf("%lld\n", res);
}