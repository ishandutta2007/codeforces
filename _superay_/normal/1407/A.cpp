#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int c[2] = {0, 0};
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			c[x]++;
		}
		if (c[0] >= c[1]) {
			printf("%d\n", c[0]);
			for (int i = 1; i <= c[0]; i++)
				printf("0 ");
			printf("\n");
		} else {
			if (c[1] % 2) c[1]--;
			printf("%d\n", c[1]);
			for (int i = 1; i <= c[1]; i++)
				printf("1 ");
			printf("\n");
		}
	}
	return 0;
}