#include<cstdio>
#include<algorithm>
using namespace std;
long long C[2010][2010], Mod = 998244353;
int BIT[2010][2], n, w[2010], p[2010], U[2010], RU[2010], po[2010];
void Add(int a, int pv, int b) {
	while (a <= n) {
		BIT[a][pv] += b;
		a += (a&-a);
	}
}
int Sum(int a, int pv) {
	int s = 0;
	while (a) {
		s += BIT[a][pv];
		a -= (a&-a);
	}
	return s;
}
int main() {
	int i, j;
	C[0][0] = 1;
	for (i = 2; i <= 2000; i++) {
		C[i][0] = (i - 1)*(C[i - 1][0] + C[i - 2][0]) % Mod;
	}
	for (i = 0; i <= 2000; i++) {
		for (j = 1; j <= 2000; j++) {
			if (i)C[i][j] = i * C[i - 1][j];
			C[i][j] = (C[i][j] + j * C[i][j - 1]) % Mod;
		}
	}
	scanf("%d", &n);
	po[0] = 1;
	for (i = 1; i <= n; i++) {
		po[i] = po[i - 1] * C[n][0] % Mod;
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	long long res = 0, ss = 0;
	for (i = 1; i <= n; i++) {
		int s = w[i]-1 -Sum(w[i] - 1, 0);
		ss = (ss + s * C[0][n - i]) % Mod;
		Add(w[i], 0, 1);
	}
	res = ss * po[n - 1] % Mod;
	for (i = 1; i < n; i++) {
		for (j = 1; j <= n; j++) {
			BIT[j][0] = 0, BIT[j][1] = 0;
			p[j] = w[j];
			U[j] = RU[j] = 0;
			scanf("%d", &w[j]);
		}
		for (j = 1; j <= n; j++)Add(j, 0, 1);
		ss = 0;
		int ca = n, cb = 0;

		for (j = 1; j <= n; j++) {
			int ck = 0;
			if (RU[p[j]])ck = 1;
			int c1 = Sum(w[j] - 1, 0);
			int c2 = Sum(w[j] - 1, 1);
			if (!ck) {
				if (p[j] < w[j])c1--;
				ss = (ss + c1 * C[ca - 2][cb + 1]) % Mod;
				ss = (ss + c2 * C[ca - 1][cb]) % Mod;
			}
			else {
				ss = (ss + c1 * C[ca - 1][cb]) % Mod;
				ss = (ss + c2 * C[ca][cb - 1]) % Mod;
			}
			
			U[p[j]] = w[j];
			RU[w[j]] = p[j];
			if (!ck) {
				Add(p[j], 0, -1);
				Add(p[j], 1, 1);
			}
			if (U[w[j]]) {
				Add(w[j], 1, -1);
			}
			else {
				Add(w[j], 0, -1);
			}
			if (!ck) {
				if (U[w[j]])ca--;
				else ca -= 2, cb++;
			}
			else {
				if (U[w[j]])cb--;
				else ca--;
			}
		}
		res = (res + ss * po[n - 1 - i]) % Mod;
	}
	printf("%lld\n", res);
	return 0;
}