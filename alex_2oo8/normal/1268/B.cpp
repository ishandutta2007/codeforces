#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	long long f = 0, g = 0;
	for (int i = 0, a; i < n; i++) {
		ignore = scanf("%d", &a);
		(i % 2 == 0 ? f : g) += a / 2;
		(i % 2 == 1 ? f : g) += (a + 1) / 2;
	}
	
	printf("%lld\n", min(f, g));
	
	return 0;
}