#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	map<int, vector<int>> occ;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		occ[x].push_back(i);
	}

	vector<int> dp(n, 0);
	for (auto &e : occ) {
		++dp[e.second.front()];
		--dp[e.second.back()];
	}
	partial_sum(dp.begin(), dp.end(), dp.begin());

	const int mod = 998244353;
	ll ans = 1;

	for (int i = 0; i < n - 1; ++i)
		if (!dp[i])
			(ans *= 2) %= mod;
	cout << ans;
	return 0;
}