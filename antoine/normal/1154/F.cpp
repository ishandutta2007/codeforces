#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.begin(), a.end());
	a.resize(k);
	n = k;

	map<int, int> mp;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (!mp.count(x))
			mp[x] = y;
		else
			mp[x] = max(mp[x], y);
	}

	vector<ll> dp(k + 1, 0);
	vector<ll> cs(k + 1, 0);
	partial_sum(a.begin(), a.end(), cs.begin() + 1);

	for (int i = k - 1; i >= 0; --i) {
		ll &res = dp[i] = a[i] + dp[i + 1];
		for (auto &&p : mp) {
			if (i + p.first > k)
				break;
			res = min(res, cs[i + p.first] - cs[i + p.second] + dp[i + p.first]);
		}
	}
	// 1 2 2 3 4
	cout << dp[0];
	return 0;
}