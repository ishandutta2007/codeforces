#include <bits/stdc++.h>

using namespace std;

int n;

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (long long k = 1; k <= n; ++k) {
		if (k == 1) {
			printf("2\n");
			continue;
		}
		long long m = k * (k + 1) * (k + 1) - (k - 1);
		printf("%lld\n", m); 
	}
	return 0;
}