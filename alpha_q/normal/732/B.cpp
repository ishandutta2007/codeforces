#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, k, a[N], add = 0;

int main (int argc, char const *argv[]) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);

	for (int i = 2; i <= n; ++i) {
		if (a[i - 1] + a[i] < k) {
			int more = k - a[i] - a[i - 1];
			add += more, a[i] += more;
		}
	}

	printf("%d\n", add);
	for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
	puts("");
    return 0;
}