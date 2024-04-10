#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	n += m;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans << 1;
		ans %= 998244353;
	}
	printf("%d\n", ans);
	return 0;
}