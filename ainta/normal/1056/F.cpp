#include<cstdio>
#include<algorithm>
using namespace std;
int n, res;
double C, T;
struct point {
	int a, p;
	bool operator<(const point &p)const {
		return a > p.a;
	}
}w[110];
double D[110][110][1010], U[110], po[110];
void Solve() {
	int i, j, k;
	scanf("%d", &n);
	scanf("%lf%lf", &C, &T);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].a, &w[i].p);
	}
	po[0] = 1.0;
	for (i = 1; i <= n; i++) {
		po[i] = po[i - 1] / 0.9;
	}
	sort(w + 1, w + n + 1);
	res = 0;
	for (i = 0; i <= n; i++)for (j = 0; j <= i; j++)for (k = 0; k <= 10 * j; k++)D[i][j][k] = 1e18;
	D[0][0][0] = 0.0;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			for (k = 0; k <= 10 * j; k++) {
				if (D[i][j][k] > 1e17)continue;
				D[i + 1][j][k] = min(D[i][j][k], D[i + 1][j][k]);
				D[i + 1][j + 1][k + w[i + 1].p] = min(D[i + 1][j + 1][k + w[i + 1].p], D[i][j][k] + po[j + 1] * w[i + 1].a);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i * 10; j++) {
			if (D[n][i][j] > 1e17)continue;
			double tt = (T*C - 10 * i*C - 1) / (2 * C);
			if (tt < 0)tt = 0.0;
			if (D[n][i][j] / (1 + tt*C) + 10 * i + tt <= T) {
				res = max(res, j);
			}
		}
	}
	printf("%d\n", res);
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}