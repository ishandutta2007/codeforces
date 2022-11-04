#include <bits/stdc++.h>
using namespace std;
int main() {
	char op[10];
	int n, h;
	scanf("%s %d%d", op, &n, &h);
	if (op[0] == 'B') {
		printf("%d\n", n);
		return 0;
	}
	double ans = n, pw = 1.0, pw2 = 1.0;
	for (int i = 1; i <= h; i++) {
		pw *= 0.5;
		pw2 *= 2;
		double ppw = 1.0;
		for (int j = 1; j <= n; j++) {
			ans += (n - j) * pw * ppw * 0.5 * (pw2 - j) / (pw2 - 1);
			ppw *= (1 - pw);
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}