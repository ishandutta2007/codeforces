#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int a;
		ignore = scanf("%d", &a);
		int x = a;
		for (int i = 0; i < 30; i++) a |= (a >> 1);
		if (a == x) {
			a = 1;
			for (int d = 2; d * d <= x; d++)
				if (x % d == 0) {
					a = x / d;
					break;
				}
		}
		printf("%d\n", a);
	}
	
	return 0;
}