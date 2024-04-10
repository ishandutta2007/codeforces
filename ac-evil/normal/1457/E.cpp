#include <bits/stdc++.h>
typedef long long LL;
const int N = 500005;
int n, k, L, p, a[N];
LL sgm = 0, ans = 0;
int main() {
	scanf("%d%d", &n, &k); k++;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a+1, a+n+1, std::greater<int>());
	for (p = 1; p <= n && a[p] >= 0; ) ans += sgm, sgm += a[p++];
	if (p > n) goto end;
	ans += ((n-p)/k+1)*sgm;
	for (int i = p; i <= n; i++) ans += 1LL*a[i]*((n-i)/k);
	for (int i = p; i <= n; i++) {
		if (!((n-i)%k)) { sgm += a[i]; continue; }
		if (sgm += a[i], sgm < 0) break;
		ans += sgm;
	}
	end:printf("%lld", ans);
	return 0;
}