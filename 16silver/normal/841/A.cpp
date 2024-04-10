#include <stdio.h>
int main() {
	int n, k, i, q[26];
	char c[150];
	scanf("%d %d", &n, &k);
	scanf("%s", c);
	for (i = 0; i < 26; i++) q[i] = 0;
	for (i = 0; i < n; i++) q[c[i] - 'a']++;
	for (i = 0; i < 26; i++) {
		if (q[i] > k) break;
	}
	if (i == 26) printf("YES");
	else printf("NO");
}