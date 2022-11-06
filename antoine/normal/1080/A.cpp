#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll c(ll x, ll y) {
	return (x+y-1)/y;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	ll n, k;
	cin >> n >> k;

	ll ans = 0;
	ans += c(2*n, k);
	ans += c(5*n, k);
	ans += c(8*n, k);
	cout << ans;
	return 0;
}