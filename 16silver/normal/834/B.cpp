#include <stdio.h>
char x[1000006];
int a[1000008] = { 0 };
int fir[26], lst[26];
int main() {
	int n, k, i;
	for (i = 0; i < 26; i++) {
		fir[i] = -1;
		lst[i] = -1;
	}
	scanf("%d %d", &n, &k);
	scanf("%s", x);
	for (i = 0; i < n; i++) {
		if (fir[x[i] - 'A'] == -1) fir[x[i] - 'A'] = i;
		lst[x[i] - 'A'] = i;
	}
	for (i = 0; i < 26; i++) {
		if (fir[i] != -1) {
			a[fir[i]]++;
			a[lst[i]+1]--;
		}
	}
	for (i = 1; i <= n; i++) {
		a[i] = a[i - 1] + a[i];
		if (a[i] > k) break;
	}
	if (i == n + 1) printf("NO");
	else printf("YES");
}