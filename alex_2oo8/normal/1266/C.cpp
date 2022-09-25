#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	
	if (n * m == 1) {
		printf("%d\n", 0);
		return 0;
	}
	
	if (m == 1) {
		for (int i = 1; i <= n; i++) printf("%d\n", i + 1);
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = n + 1; j <= n + m; j++)
			printf("%d ", i * j);
		printf("\n");
	}
		
	return 0;
}