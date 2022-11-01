#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int n; long long k, a[100005];
	scanf("%d %I64d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
	k *= 2;
	long long x = floor((sqrt(1.0 + 4.0 * k) - 1.0)/2.0);
	k -= x * (x + 1); k /= 2;
	if (k == 0) k = x;
	printf("%I64d\n", a[k]);
	return 0;
}