#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 3e5 + 5;

int n, m, k;
int a[N];
ll f[14];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll cmp = 0, sum = 0;
		for (int j = 0; j <= i && j < m; j++) {
			sum += a[i - j];
			cmp = max(cmp, sum);
		}
		f[i % m] = max(f[i % m] + sum, cmp) - k;
		ans = max(ans, f[i % m]);
	}
	printf("%lld\n", ans);
	return 0;
}