#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	deque<pair<long long, long long>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	long long bought = 0;
	while (!v.empty()) {
		while (!v.empty() && bought >= v.front().first) {
			bought += v.front().second;
			ans += v.front().second;
			v.pop_front();
		}
		if (v.empty()) {
			break;
		}
		if (v.size() == 1) {
			auto [b, a] = v.front();
			if (bought + a > b) {
				long long amt = b - bought;
				ans += amt * 2;
				ans += (a - amt);
			} else {
				ans += 2 * a;
			}
			bought += a;
			v.pop_front();
		} else {
			if (v.front().first < v.back().second + bought) {
				long long amt = v.front().first - bought;
				v.back().second -= amt;
				ans += 2 * amt;
				bought += amt;
			} else {
				ans += 2 * v.back().second;
				bought += v.back().second;
				v.pop_back();
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}