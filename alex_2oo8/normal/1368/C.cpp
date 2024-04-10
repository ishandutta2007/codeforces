#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	printf("%d\n", 8 + 7 * n);
	
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++) {
			if (x == 1 && y == 1) continue;
			printf("%d %d\n", x, y);
		}
	
	for (int i = 0, p = 2; i < n; i++, p += 2) {
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++) {
				if (x == 1 && y == 1) continue;
				if (x == 0 && y == 0) continue;
				
				printf("%d %d\n", p + x, p + y);
			}
	}
	
	return 0;
}