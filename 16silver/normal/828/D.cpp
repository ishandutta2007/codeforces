#include <cstdio>
int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);
	if ((n - 2) % k == 0) {
		printf("%d\n",((n-2)/k)*2+1);
	}
	else {
		printf("%d\n",((n-2)/k)*2+2);
	}
	for (i = 2; i < k + 2; i++) {
		printf("1 %d\n", i);
	}
	for (i = k + 2; i <= n; i++) {
		printf("%d %d\n", i - k, i);
	}
}