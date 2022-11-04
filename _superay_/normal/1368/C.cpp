#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", 7 * n + 8);
	printf("0 0\n");
	printf("0 1\n");
	printf("0 2\n");
	printf("1 0\n");
	printf("1 2\n");
	printf("2 0\n");
	printf("2 1\n");
	printf("2 2\n");
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", 2 * i, 2 * i + 1);
		printf("%d %d\n", 2 * i, 2 * i + 2);
		printf("%d %d\n", 2 * i + 1, 2 * i);
		printf("%d %d\n", 2 * i + 1, 2 * i + 2);
		printf("%d %d\n", 2 * i + 2, 2 * i);
		printf("%d %d\n", 2 * i + 2, 2 * i + 1);
		printf("%d %d\n", 2 * i + 2, 2 * i + 2);
	}
	return 0;
}