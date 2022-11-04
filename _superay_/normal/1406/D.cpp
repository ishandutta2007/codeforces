#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, q;
long long cur = 0;
long long a[N];
inline void Add(int i, long long x) {
	if (i == 1 || a[i] > 0) cur -= a[i];
	a[i] += x;
	if (i == 1 || a[i] > 0) cur += a[i];
}
inline long long Calc(long long x) {
	if (x % 2 == 0) return x / 2;
	else return (x + 1) / 2;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
	for (int i = 1; i <= n; i++) {
		if (i == 1 || a[i] > 0) cur += a[i];
	}
	printf("%lld\n", Calc(cur));
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		long long x;
		scanf("%d%d%lld", &l, &r, &x);
		Add(l, x);
		if (r < n) Add(r + 1, -x);
		printf("%lld\n", Calc(cur));
	}
	return 0;
}