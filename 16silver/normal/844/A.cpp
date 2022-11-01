#include <stdio.h>
#include <string.h>
int main() {
	char c[1010];
	int k, i, r[26], l, q = 0;
	scanf("%s", c);
	scanf("%d", &k);
	l = strlen(c);
	for (i = 0; i < 26; i++) r[i] = 0;
	if (k > l) printf("impossible");
	else {
		for (i = 0; i < l; i++) r[c[i] - 'a'] = 1;
		for (i = 0; i < 26; i++) q += r[i];
		printf("%d", (k < q ? 0 : k - q));
	}
}