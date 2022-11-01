#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

double n, l, v1, v2, k;

int main (int argc, char const *argv[]) {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	scanf("%lf %lf %lf %lf %lf", &n, &l, &v1, &v2, &k);
	double s = l/(1.0 + ((2.0 * v1)/(v1 + v2)) * ceil((n - k)/k));
	double ans = (l - s)/v1 + s/v2;
	printf("%0.12f\n", ans);
	return 0;
}