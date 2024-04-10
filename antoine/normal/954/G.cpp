#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

typedef long long ll;

bool f(const ll mid, const vector<ll> &d, const int r, ll k) {
	vector<ll> dp(d.size(), 0);
	
	for (int i = 0; i < d.size(); ++i) {
		ll diff = mid - (d[i] + dp[i]);
		if (diff > 0) {
			k -= diff;
			if (k < 0)
				return false;
			dp[i] += diff;
			const int j = i + (r << 1) + 1;
			if (j < d.size())
				dp[j] -= diff;
		}
		if (i + 1 < d.size())
			dp[i + 1] += dp[i];
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r;
	ll k;
	cin >> n >> r >> k;

	vector<ll> d(n, 0);

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		d[max(i - r, 0)] += a;
		if (i + r + 1 < n)
			d[i + r + 1] -= a;
	}

	for (int i = 1; i < n; ++i)
		d[i] += d[i - 1];

	ll lo = 0;
	ll hi = 2e18;
	f(1000, d, r, k);
	while (lo < hi) {
		auto mid = (lo + hi + 1) >> 1;
		if (f(mid, d, r, k))
			lo = mid;
		else
			hi = mid - 1;
	}
	cout << lo;
	return 0;
}