#include <bits/stdc++.h>
#define pb push_back
using std::max; using std::min; using std::vector;
const int N = 500005;
int n, a[N], l[N], r[N], f[N], cnt[N], d[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (!l[a[i]]) l[a[i]] = i;
		r[a[i]] = i; cnt[a[i]]++;
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i-1];
		if (r[a[i]] == i) f[i] = max(f[i], f[l[a[i]] - 1] + cnt[a[i]]);
	}
	int ans = f[n];
	for (int l = n, r = n; r; r = l-1) {
		while (l && a[l-1] == a[r]) l--;
		d[a[l]] += r - l + 1, ans = max(ans, f[l - 1] + d[a[l]]);
	}
	printf("%d\n", n - ans);
	return 0;
}