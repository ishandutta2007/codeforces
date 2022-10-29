#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n, r;
int *x;
double *y;

inline void init() {
	scanf("%d%d", &n, &r);
	x = new int[(n + 1)];
	y = new double[(n + 1)];
	for (int i = 1; i <= n; i++)
		scanf("%d", x + i);
}

inline void solve() {
	int d = r << 1;
	for (int i = 1; i <= n; i++) {
		y[i] = r;
		for (int j = 1; j < i; j++) {
			if (abs(x[i] - x[j]) <= d) {
				y[i] = max(y[i], y[j] + sqrt(d * d - (x[i] - x[j]) * (x[i] - x[j])));
			}
		}
		printf("%.9lf ", y[i]);
	}
}

int main() {
	init();
	solve();
	return 0;
}