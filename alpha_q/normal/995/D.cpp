#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long double ld;

const int LG = 50;
const int N = 1 << 19;

int n, r;
ld f[N], sum = 0, two[LG];

int main() {
	two[0] = 1;
	for (int i = 1; i < LG; ++i) {
		two[i] = two[i - 1] + two[i - 1];
	}
	scanf("%d %d", &n, &r);
	for (int i = 0; i < 1 << n; ++i) {
		double x;
		scanf("%lf", &x);
		f[i] = x;
		sum += f[i];
	}
	ld ans = sum / two[n];
	printf("%0.12f\n", (double) ans);
	while (r--) {
		int at; double x;
		scanf("%d %lf", &at, &x);
		sum -= f[at];
		f[at] = x;
		sum += f[at];
		ld ans = sum / two[n];
		printf("%0.12f\n", (double) ans);
	}
  return 0;
}