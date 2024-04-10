#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
long long a, x[N];

int main (int argc, char const *argv[]) {
	scanf("%d %lld", &n, &a);
	for (int i = 1; i <= n; ++i) scanf("%lld", x + i);
	sort (x + 1, x + n + 1);

	if (n == 1) {
		printf("0\n");
		return 0;
	}

	long long p1, p2, q1, q2;
	p1 = p2 = q1 = q2 = 0;

	if (a < x[1]) p1 = p2 = x[n - 1] - a;
	else if (a > x[n - 1]) p1 = p2 = a - x[1];
	else p1 = a - x[1] + x[n - 1] - x[1], p2 = x[n - 1] - a + x[n - 1] - x[1];

	if (a < x[2]) q1 = q2 = x[n] - a;
	else if (a > x[n]) q1 = q2 = a - x[2];
	else q1 = a - x[2] + x[n] - x[2], q2 = x[n] - a + x[n] - x[2];

	long long ans = min(min(p1, p2), min(q1, q2));
	printf("%lld\n", ans);
    return 0;
}