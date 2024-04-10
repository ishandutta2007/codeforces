#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, k, p, a[N], b[N];

int main() {
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= k; ++i) {
		scanf("%d", b + i);
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + k + 1);
	int best = 2e9 + 100;
	for (int i = 1, j = n; j <= k; ++i, ++j) {
		int cur = 0;
		for (int s = 1, t = i; s <= n; ++s, ++t) {
			cur = max(cur, abs(a[s] - b[t]) + abs(b[t] - p));			
		}
		best = min(best, cur);
	}
	printf("%d\n", best);
	return 0;
}