#include <bits/stdc++.h>

using namespace std;

const int MX = 20000;

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0, b = 0, x; i < n; i++) {
		ignore = scanf("%d", &x);
		if (x % 2 != 0) {
			int sgn = 1;
			if (x < 0) {
				x *= -1;
				x += 1;
				sgn *= -1;
			}
			x /= 2;
			x *= sgn;
			x += b;
			b ^= 1;
		}
		else x /= 2;
		
		printf("%d\n", x);
	}
	
	return 0;
}