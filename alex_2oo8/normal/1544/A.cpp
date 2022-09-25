#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d", &n);
		
		int x = 0;
		while (n > 0) {
			x = max(x, n % 10);
			n /= 10;
		}
		
		printf("%d\n", x);
	}
	
	return 0;
}