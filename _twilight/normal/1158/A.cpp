#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];
long long ans = 0;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", b + i);
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	if (a[n] > b[1]) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= m; i++)
		ans += b[i];
	if (a[n] == b[1]) {
		for (int i = 1; i < n; i++)
			ans += m * 1ll * a[i];
	} else {
		if (n == 1) {
			puts("-1");
			return 0;
		}
		ans += a[n] + 1ll * a[n - 1] * (m - 1);
		for (int i = 1; i < n - 1; i++) {
			ans += m * 1ll * a[i];
		}
	}
	cout << ans << '\n';
	return 0;
}