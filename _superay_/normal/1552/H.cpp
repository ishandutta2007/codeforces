#include <bits/stdc++.h>
using namespace std;
inline int F(int d) {
	printf("? %d\n", 200 * (200 / d));
	for (int x = d; x <= 200; x += d) for (int y = 1; y <= 200; y++) printf("%d %d ", x, y);
	printf("\n");
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}
int f[9];
int main() {
	int lo = 1, hi = 8;
	f[0] = F(1);
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		f[mid] = F(1 << mid);
		if (f[mid] * (1 << mid) == f[0]) lo = mid + 1;
		else hi = mid;
	}
	int h = abs(2 * f[hi] - f[0] / (1 << (hi - 1)));
	int w = f[0] / h;
	printf("! %d\n", 2 * (h + w - 2));
	fflush(stdout);
	return 0;
}