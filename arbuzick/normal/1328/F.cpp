#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(30);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<pair<int, int>> b;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || b.back().first != a[i])
			b.push_back({ a[i], 1 });
		else
			b.back().second += 1;
	}
	vector<pair<int, int>> pr(b.size() + 1);
	pr[0] = { 0, 0 };
	for (int i = 0; i < b.size(); ++i) {
		pr[i + 1].first = pr[i].first + b[i].first * b[i].second;
		pr[i + 1].second = pr[i].second + b[i].second;
	}
	int ans = 1e18;
	for (int i = 0; i < b.size(); ++i) {
		if (b[i].second >= k) {
			ans = 0;
			break;
		}
		if (pr[b.size()].second - pr[i + 1].second < k-b[i].second && pr[i].second < k-b[i].second) {
			int m = (pr[b.size()].first - pr[i + 1].first) - (b[i].first + 1) * (pr[b.size()].second - pr[i + 1].second);
			m = m + ((b[i].first - 1) * pr[i].second - pr[i].first);
			m = m + k - b[i].second;
			ans = min(ans, m);
		}
		if (pr[b.size()].second - pr[i + 1].second >= k - b[i].second) {
			int m = (pr[b.size()].first - pr[i + 1].first) - (b[i].first + 1) * (pr[b.size()].second - pr[i + 1].second);
			m = m + k - b[i].second;
			ans = min(ans, m);
		}
		if (pr[i].second >= k - b[i].second) {
			int m = ((b[i].first - 1) * pr[i].second - pr[i].first);
			m = m + k - b[i].second;
			ans = min(ans, m);
		}
	}
	cout << ans << endl;
	return 0;
}