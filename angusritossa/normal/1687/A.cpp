#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MAXN 200010
ll arr[MAXN], pre[MAXN];
void solve() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	ll ans = 0;
	if (k >= n) {
		ll extra = k-n;
		for (int i = 0; i < n; i++) {
			ll a;
			scanf("%lld", &a);
			ans += a + extra + i;
		}
	} else {
		ll extra = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &arr[i]);
			pre[i] = pre[i-1]+arr[i];
			if (i <= k) extra += i-1;
		}
		for (int i = 1; i <= n-k+1; i++) {
			ll am = extra - pre[i-1] + pre[i+k-1];
			ans = max(ans, am);
		}
	}
	printf("%lld\n", ans);

}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}