#include <bits/stdc++.h>
using namespace std;
inline void Process(vector<pair<int, int> > &vec) {
	sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.first != b.first ? a.first < b.first : a.second > b.second;
	});
	vector<pair<int, int> > ret;
	for (auto &p : vec) {
		while (!ret.empty() && ret.back().second >= p.second) ret.pop_back();
		ret.push_back(p);
	}
	vec.swap(ret);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		vector<vector<pair<int, int> > > bi(n + 1), ci(n + 1);
		while (m--) {
			int l, r;
			scanf("%d%d", &l, &r);
			int pp = lower_bound(a.begin(), a.end(), l) - a.begin();
			if (pp < n && a[pp] <= r) continue;
			bi[pp].emplace_back(l, r);
		}
		for (int i = 0; i <= n; i++) {
			Process(bi[i]);
			reverse(bi[i].begin(), bi[i].end());
			if (i > 0) bi[i].emplace_back(a[i - 1], a[i - 1]);
			reverse(bi[i].begin(), bi[i].end());
			if (i < n) bi[i].emplace_back(a[i], a[i]);
			if (i == 0) {
				ci[i].emplace_back(0, bi[i][0].second);
			} else if (i == n) {
				ci[i].emplace_back(bi[i].back().first, 0);
			} else {
				for (int j = 0; j < (int)bi[i].size() - 1; j++) {
					ci[i].emplace_back(bi[i][j].first, bi[i][j + 1].second);
				}
			}
		}
		vector<vector<long long> > dp(n + 1);
		for (int i = 0; i <= n; i++) dp[i].resize(ci[i].size(), 1e18);
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			long long mn0 = 1e18, mn1 = 1e18;
			for (int j = 0; j < (int)ci[i].size(); j++) {
				mn0 = min(mn0, dp[i][j] - 2ll * ci[i][j].second + a[i]);
				mn1 = min(mn1, dp[i][j] - 1ll * ci[i][j].second - a[i]);
			}
			for (int j = 0; j < (int)ci[i + 1].size(); j++) {
				dp[i + 1][j] = min(mn0 + 1ll * ci[i + 1][j].first, mn1 + 2ll * ci[i + 1][j].first);
			}
		}
		printf("%lld\n", dp[n][0]);
	}
	return 0;
}