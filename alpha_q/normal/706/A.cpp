#include <bits/stdc++.h>

using namespace std;

int n;
double a, b, x, y, v, t = 1e17;

int main (int argc, char const *argv[]) {
	scanf("%lf %lf", &a, &b);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf %lf %lf", &x, &y, &v);
		double cur = hypot(a - x, b - y)/v;
		t = min(t, cur);
	}
	printf("%0.12f\n", t);
	return 0;
}