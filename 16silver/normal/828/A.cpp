#include <cstdio>
int main() {
	int n, a, b, x, y, z, i, t, r = 0;
	scanf("%d %d %d", &n, &a, &b);
	x = a;
	y = b;
	z = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t == 1) {
			if (x > 0) {
				x--;
			}
			else if (y > 0) {
				y--;
				z++;
			}
			else if (z > 0) {
				z--;
			}
			else {
				r++;
			}
		}
		else {
			if (y > 0) {
				y--;
			}
			else {
				r += 2;
			}
		}
	}
	printf("%d", r);
}