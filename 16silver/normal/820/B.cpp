#include <cstdio>
int main() {
	int n, a, k;
	scanf("%d %d", &n, &a);
	k = (a*n + 90) / 180;
	if (k > n - 2) k = n - 2;
	else if (k < 1) k = 1;
	printf("%d %d %d", 1, n, k + 1);
}