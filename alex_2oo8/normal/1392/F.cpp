#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000;

long long s(long long x, int n) {
	if (n > x) n = x;
	
	return x * n - n * (n - 1LL) / 2;
}

long long a[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%lld", a + i);
	
	long long S = accumulate(a, a + n, 0LL);
	for (int i = n - 1, f = 1; i >= 0; i--) {
		long long x = 0;
		for (long long p = (1LL << 40); p > 0; p /= 2) {
			x += p;
			if ((f == 1 && x > a[i]) || s(x, i + 1) > S) x -= p;
		}
		
		if (a[i] > x) f = 0;
		
		a[i] = x;
		S -= x;
	}
	
	for (int i = 0; i < n; i++) printf("%lld ", a[i]);
	printf("\n");
	
	return 0;
}