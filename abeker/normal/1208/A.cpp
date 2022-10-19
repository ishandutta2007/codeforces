#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b, n;
		scanf("%d%d%d", &a, &b, &n);
		if (n % 3 == 1)
			printf("%d\n", b);
		else if (n % 3 == 2)
			printf("%d\n", a ^ b);
		else
			printf("%d\n", a);
	}
	return 0;
}