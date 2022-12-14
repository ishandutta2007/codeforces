#include <stdio.h>

int n, p, k;

int main() {
	scanf("%d%d%d", &n, &p, &k);

	if(p - k > 1) printf("<< ");
	for(int i = p - k; i <= p + k; i++) if(1 <= i && i <= n) printf((i == p) ? "(%d) " : "%d ", i);
	if(p + k < n) printf(">> ");

	return 0;
}