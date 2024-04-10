#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, c[N], q, x;

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", c + i);
	sort (c + 1, c + n + 1);
	scanf("%d", &q); while (q--) {
		scanf("%d", &x);
		int res = upper_bound(c + 1, c + n + 1, x) - c - 1;
		printf("%d\n", res);
	}
	return 0;
}