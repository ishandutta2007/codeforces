#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s = 0, k = 0;
	ignore = scanf("%d", &n);
	for (int i = 0, x; i < n; i++) {
		ignore = scanf("%d", &x);
		s += x;
		k = max(k, x);
	}
	
	while (n * k - s <= s) k++;
	
	printf("%d\n", k);
	
	return 0;
}