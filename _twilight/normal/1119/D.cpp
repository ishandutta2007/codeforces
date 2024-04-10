#include <bits/stdc++.h>
#ifdef local
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 1e5 + 5;

int n, m;
ll a[N], d[N], s[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(Auto"\n", a + i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		d[i] = a[i + 1] - a[i];
	}
	d[n] = 1e18;
	d[n] += 5;
	sort(d + 1, d + n);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + d[i];
	}

	scanf("%d", &m);
	ll L, R;
	while (m--) {
		scanf(Auto""Auto, &L, &R);
		int p = lower_bound(d + 1, d + n + 1, R - L + 1) - d;
		printf(Auto" ", s[p - 1] + (n - p + 1) * (R - L + 1));
	}
	return 0;
}