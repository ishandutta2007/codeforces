#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	int x = 1;
	while (x * x < n) x++;
	
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++) {
			int v = j * x + x - i;
			if (v > n) continue;
			printf("%d ", v);
		}
	
	printf("\n");
	
	return 0;
}