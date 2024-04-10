#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b, n;
		scanf("%d%d%d", &a, &b, &n);
		int c = 0;
		while (a <= n && b <= n) {
			if (a > b) swap(a, b);
			a += b;
			c++;
		}
		printf("%d\n", c);
	}
	return 0;
}