#include <cstdio>
#include <algorithm>
int n, q;
long long a[100005], s[100005], l, r;
long long solve(long long x){
	int k = std :: lower_bound(a + 1, a + n, x) - a - 1;
	return s[k] + (n - k) * x;
}
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%lld", a + i);
	std :: sort(a + 1, a + 1 + n);
	for (register int i = 1; i < n; ++i) a[i] = a[i + 1] - a[i];
	std :: sort(a + 1, a + n);
	for (register int i = 1; i < n; ++i) s[i] = s[i - 1] + a[i];
	scanf("%d", &q);
	while (q--) scanf("%lld%lld", &l, &r), printf("%lld ", solve(r - l + 1));
}