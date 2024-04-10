#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 10;
const int mod = 998244353;

ll getLine(ll n, ll k) {
	if (k <= n)
		return k * (k + 1) / 2;
	k = 2LL * n - 1 - k;
	return n * n - k * (k + 1) / 2;
}

void solve() {
	int n;
	ll x;
	cin >> n >> x;
	ll lo = 0, hi = 2 * n - 1;
	while (hi - lo > 1) {
		ll mid = (lo + hi) >> 1;
		if (getLine(n, mid) < x)
			lo = mid;
		else
			hi = mid;
	}
	cout << hi << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}