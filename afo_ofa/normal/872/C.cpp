#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int n;
		scanf("%d", &n);
		if (n == 1 || n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {
			puts("-1");
			continue;
		}
		int temp = n % 4;
		switch (temp) {
			case (0) : {
				printf("%d\n", n / 4);
				break;
			}
			case (1) : {
				printf("%d\n", (n - 9) / 4 + 1);
				break;
			}
			case (2) : {
				printf("%d\n", (n - 2) / 4);
				break;
			}
			case (3) : {
				printf("%d\n", (n - 9) / 4 + 1);
				break;
			}
		}
	}
	return 0;
}