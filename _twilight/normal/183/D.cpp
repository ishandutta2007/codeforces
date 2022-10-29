#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e3 + 5, M = 305;

int n, m;
double a[M][N];
double f[M][N], T[N], s[M];

void calculate(int k) {
	s[k] -= f[k][n];
	for (int i = 1; i <= n; i++) {
		T[i] = T[i - 1] * (1 - a[k][i]) + f[k][i - 1] * a[k][i];
	}
	for (int i = 0; i <= n; i++) {
		f[k][i] = T[i];	
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1, x; j <= m; j++) {
			scanf("%d", &x);
			a[j][i] = x * 1.0 / 1000;
		}
	}
	for (int i = 1; i <= m; i++) {
		f[i][0] = 1, s[i] = 1;
		for (int j = 1; j <= n; j++) {
			f[i][j] = f[i][j - 1] * (1 - a[i][j]);
		}
		calculate(i);
	}
	double ans = 0.0;
	for (int i = 1; i <= n; i++) {
		double mx = 0.0;
		int id = -1;
		for (int j = 1; j <= m; j++) {
			if (s[j] > mx) {
				mx = s[j];
				id = j;
			}
		}
		assert(id != -1);
		ans += mx;
		calculate(id);
	}
	printf("%.9lf\n", ans);
	return 0;
}