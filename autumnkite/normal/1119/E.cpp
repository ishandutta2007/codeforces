#include <cstdio>
#include <algorithm>
int n, a[300005];
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
	long long now = 0, ans = 0;
	for (register int i = 1; i <= n; ++i){
		long long cnt = std :: min(now, 1ll * a[i] >> 1);
		now -= cnt, ans += cnt, a[i] -= cnt << 1;
		ans += a[i] / 3, a[i] %= 3, now += a[i];
	}
	printf("%lld", ans);
}