#include <stdio.h>
int x[600005];
int main() {
	char c[10];
	int i, cnt = 0, n, r = 0, p = 1;
	scanf("%d", &n);
	for (i = 0; i < 2 * n; i++) {
		scanf("%s", c);
		if (c[0] == 'a') {
			scanf("%d", &x[cnt]);
			cnt++;
		}
		else {
			if (x[cnt - 1] == p) {
				cnt--;
				x[cnt] = 0;
				p++;
			}
			else {
				x[cnt] = -1;
				p++;
				cnt++;
			}
		}
	}
	p = 0;
	for (i = 0; i < cnt; i++) {
		if (x[i] == -1) {
			if (p == 0) {
				r++;
				p = 1;
			}
		}
		else {
			p = 0;
		}
	}
	printf("%d", r);
}