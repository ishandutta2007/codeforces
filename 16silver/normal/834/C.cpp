#include <stdio.h>
int cuberoot(int x) {
	int fr = 0, la = 1001, mid, p;
	while (la - fr > 0) {
		mid = (fr + la) / 2;
		p = mid*mid*mid;
		if (p == x) return mid;
		else if (p > x) la = mid;
		else fr = mid + 1;
	}
	if (fr*fr*fr == x) return fr;
	else return -1;
}
int main() {
	int n, a, b, p, q, r, i, t;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		p = a;
		q = b;
		r = p%q;
		while (r > 0) {
			p = q;
			q = r;
			r = p%q;
		}
		a = a / q;
		b = b / q;
		if (q%a != 0) {
			printf("No\n");
		}
		else {
			q = q / a;
			if (q%b != 0) {
				printf("No\n");
			}
			else {
				q = q / b;
				if (cuberoot(q) == -1) {
					printf("No\n");
				}
				else printf("Yes\n");
			}
		}
	}
}