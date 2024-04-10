#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MAXN 100010
#define SQRT 150
ll a[MAXN];
int ans = 1, n, coun;
unordered_map<ll, int> amWith;
ll vals[MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (ll diff = -SQRT; diff <= SQRT; diff++) {
		for (ll i = 0; i < n; i++) {
			vals[i] = a[i] - i*diff;
		}
		sort(vals, vals+n);
		int c = 0;
		ll pre = 0;
		for (int i = 0; i < n; i++) {
			if (vals[i] != pre) {
				c = 0;
				pre = vals[i];
			}
			c++;
			ans = max(ans, c);
		}
	}
	int SQRT2 = (120000)/SQRT;
	for (int i = 0; i < n; i++) {
		int num = min(n, i+SQRT2);
		amWith.clear();
		for (int j = i+1; j < num; j++) {
			ll diff = a[j]-a[i];
			ll diff2 = j-i;
			if (diff%diff2 == 0) {
				diff /= diff2;
				ans = max(ans, ++amWith[diff]+1);
			}
		}
	}

	printf("%d\n", n-ans);
}