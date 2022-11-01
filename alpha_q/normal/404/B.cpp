#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; double a, d;
	cin >> a >> d >> n;
	int side = 0; double dist = 0.0;
	for (int i = 1; i <= n; i++) {
		dist += d;
		side += floor(dist/a), dist -= a * floor(dist/a), side %= 4;
		if (side == 0) printf("%0.10lf 0.0000000000\n", dist);
		if (side == 1) printf("%0.10lf %0.10lf\n", a, dist);
		if (side == 2) printf("%0.10lf %0.10lf\n", a - dist, a);
		if (side == 3) printf("0.0000000000 %0.10lf\n", a - dist);
	}
	return 0;
}