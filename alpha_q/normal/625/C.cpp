#include <bits/stdc++.h>

using namespace std;

int main () {
	long long n, k, i, j, ret;
	scanf ("%I64d %I64d", &n, &k);
	ret = n * (n - 1) * (n - 1) + k * n * (n + 1);
	ret /= 2; printf ("%I64d\n", ret);
	
	long long st = 1, tt = k * n - n + 1;
	for (j = 1; j <= n; j++) {
		for (i = 1; i < k; i++) printf ("%I64d ", st++);
		for (i = k; i <= n; i++) printf ("%I64d ", tt++);
		printf ("\n");
	}
	return 0;
}