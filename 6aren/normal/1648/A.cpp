#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	map<int, vector<pair<int, int>>> mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			mp[x].push_back(make_pair(i, j));
		}
	}

	long long res = 0;

	for (auto it : mp) {
		int color = it.first;
		auto tmp = it.second;
		{
			sort(tmp.begin(), tmp.end(), [&](pair<int, int> lhs, pair<int, int> rhs) {
				return lhs.first < rhs.first;
			});
			long long sum = 0;
			for (int i = 0; i < tmp.size(); i++) {
				res += tmp[i].first * i - sum;
				sum += tmp[i].first;
			}
		}
		{
			sort(tmp.begin(), tmp.end(), [&](pair<int, int> lhs, pair<int, int> rhs) {
				return lhs.second < rhs.second;
			});
			long long sum = 0;
			for (int i = 0; i < tmp.size(); i++) {
				res += tmp[i].second * i - sum;
				sum += tmp[i].second;
			}
		}
	}
	cout << res << '\n';
}