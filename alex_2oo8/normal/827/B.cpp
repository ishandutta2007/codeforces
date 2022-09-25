#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	ignore = scanf("%d %d", &n, &k);
	
	int a = (n - 1 + k - 1) / k, ans = 2 * a;
	if ((a - 1) * (k - 1) + a >= n - 1) ans--;
	
	printf("%d\n", ans);
	
	int p = 2;
	while (k > 0) {
		int b = (n - 1 + k - 1) / k;
		printf("1 %d\n", p);
		for (int i = 1; i < b; i++) {
			printf("%d %d\n", p, p + 1);
			p++;
		}
		
		p++;
		n -= b;
		k--;
	}
	
	return 0;
}