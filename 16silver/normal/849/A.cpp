#include <cstdio>
int main() {
	int n, a[100], i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	if (n % 2 == 1 && a[0] % 2 == 1 && a[n - 1] % 2 == 1) printf("Yes");
	else printf("No");
}