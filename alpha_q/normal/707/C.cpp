#include <bits/stdc++.h>

using namespace std;

long long n;

int main (int argc, char const *argv[]) {
	scanf("%lld", &n);

	if (n == 1 or n == 2) {
		printf("-1\n");
		return 0;
	}

	if (n & 1) {
		long long x = (n * n - 1) >> 1;
		printf("%lld %lld\n", x, x + 1);
		return 0;
	}

	long long x = (n >> 1) * (n >> 1);
	printf("%lld %lld\n", x - 1, x + 1);
	return 0;
}