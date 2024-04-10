#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	int a = 1, b = 2;
	while (b < n) {
		int s = a + b + (a % 2);
		a = s;
		b = s + 1;
	}
	
	int ans = (a == n || b == n) ? 1 : 0;
	printf("%d\n", ans);
	
	return 0;
}