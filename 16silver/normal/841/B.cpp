#include <stdio.h>
int main() {
	int n, i, t, e = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t % 2 == 1) e = 1;
	}
	if (e == 1) printf("First");
	else printf("Second");
}