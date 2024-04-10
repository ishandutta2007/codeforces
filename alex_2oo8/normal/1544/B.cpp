#include <bits/stdc++.h>

using namespace std;

const int MX = 20;

char s[MX][MX + 1];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n, m;
		ignore = scanf("%d %d", &n, &m);
		
		for (int i = 0; i < m; i++) {
			printf("%d", (i + 1) % 2);
		}
		
		printf("\n");
		
		for (int i = 1; i < n - 1; i++) {
			printf("%d", (i - 1) % 2);
			
			for (int j = 1; j < m - 1; j++) printf("0");
			
			printf("%d\n", (i - 1) % 2);
		}
		
		printf("%d", n % 2);
		for (int i = 1; i < m - 2; i++) {
			printf("%d", (i - 1) % 2);
		}
		
		printf("0%d\n", n % 2);
	}
	
	return 0;
}