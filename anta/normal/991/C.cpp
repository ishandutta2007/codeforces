#include "bits/stdc++.h"
using namespace std;

int main() {
	long long n;
	while (~scanf("%lld", &n)) {
		long long lo = 1, up = n;
		while (up - lo > 0) {
			long long k = (lo + up) / 2;
			long long x = n, y = 0;
			while (x > 0) {
				auto t = min(x, k);
				x -= t, y += t;
				x -= x / 10;
			}
			if (y * 2 >= n)
				up = k;
			else
				lo = k + 1;
		}
		printf("%lld\n", up);
	}
}