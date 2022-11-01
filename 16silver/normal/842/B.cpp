#include <stdio.h>
int main() {
	int r, d, n, xk, yk, rk, i, ans = 0;
	scanf("%d %d", &r, &d);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &xk, &yk, &rk);
		if (r-rk>0 && ((r - d + rk)*(r - d + rk) <= xk*xk + yk*yk) && ((r - rk)*(r - rk) >= xk*xk + yk*yk)) ans++;
	}
	printf("%d", ans);
}