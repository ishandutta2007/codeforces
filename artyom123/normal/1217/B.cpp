#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int INF = 1e9 + 1;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first - a.second < b.first - b.second;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector <pair<int, int>> a(n);
		int maxd = -1;
		for (auto &c : a) {
			cin >> c.first >> c.second;
			maxd = max(maxd, c.first);
		}
		sort(a.begin(), a.end(), cmp);
		if (maxd >= x) {
			cout << 1 << "\n";
			continue;
		}
		if (a.back().first - a.back().second <= 0) {
			cout << -1 << "\n";
			continue;
		}
		int ans = 1 + ((x - maxd + a.back().first - a.back().second - 1) / (a.back().first - a.back().second));
		cout << ans << "\n";
	}
	return 0;
}