#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, u, r, d, l;
		scanf("%d%d%d%d%d", &n, &u, &r, &d, &l);
		int ans = 0;
		for (int mask = 0; mask < (1 << 4); mask++) {
			int ur = mask >> 0 & 1, rd = mask >> 1 & 1, dl = mask >> 2 & 1, lu = mask >> 3 & 1;
			int x1 = u - ur - lu;
			int x2 = r - ur - rd;
			int x3 = d - rd - dl;
			int x4 = l - dl - lu;
			if (min(min(x1, x2), min(x3, x4)) >= 0 && max(max(x1, x2), max(x3, x4)) <= n - 2) {
				ans = 1;
				break;
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}