#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n+1), dp(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	auto f = [&](int x) {
		return make_pair(max(1, x - k), min(n, x + k));
	};
	auto len = [&](const pair<int, int>& p) {
		return p.second - p.first + 1;
	};
	auto uni = [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
		if (lhs.second >= rhs.first) {
			return len({lhs.second + 1, rhs.second});
		} else {
			return len(rhs);
		}
	};
	for (int i = 1; i <= n; ++i) {
		auto segm = f(i);
		if (a[i] > 0) {
			dp[i] = dp[a[i]] + uni(f(a[i]), segm);
		} else {
			dp[i] = len(segm);
		}
		cout << dp[i] << " ";
	}
	cout << "\n";
	
	return 0;
}