#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k, x, col[300], len[300];

int main() {
	scanf("%d %d", &n, &k);
	memset(col, -1, sizeof col);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		if (col[x] != -1) {
			printf("%d ", col[x]);
			continue;
		}
		int tot = k - 1, l = x;
		while (tot and l and col[l - 1] == -1) --l, --tot;
		if (tot and l and len[l - 1] <= tot) {
			int p = len[l - 1];
			// cout << l << " " << p << endl;
			for (int j = l - p; j <= x; ++j) {
				len[j] = k - tot + p, col[j] = l - p;
			}
		} else {
			// cout << l << endl;
			for (int j = l; j <= x; ++j) {
				len[j] = k - tot, col[j] = l;
			}
		}
		printf("%d ", col[x]);
	}
	puts("");
  return 0;
}