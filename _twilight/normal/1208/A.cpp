#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int T, a, b, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &a, &b, &n);
		int r = n % 3;
		if (r == 1) {
			a = b;
		} else if (r == 2) {
			a ^= b;
		}
		printf("%d\n", a);
	}
	return 0;
}