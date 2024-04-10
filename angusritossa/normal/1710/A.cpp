#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
bool solve(ll n, ll m, vector<ll> vals) {
	ll num = 0;
	bool hasGreater2 = false;
	for (auto a : vals) {
		if (a/m >= 2) {
			num += a/m;
			if (a/m > 2) hasGreater2 = true;
		}
	}
	if (n%2 && !hasGreater2) return false;
	return num >= n;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		ll n, m, k;
		scanf("%lld%lld%lld", &n, &m, &k);
		vector<ll> vals;
		for (int j = 0; j < k; j++) {
			ll a;
			scanf("%lld", &a);
			vals.push_back(a);
		}
		if (solve(n, m, vals) || solve(m, n, vals)) printf("Yes\n");
		else printf("No\n");
	}
}