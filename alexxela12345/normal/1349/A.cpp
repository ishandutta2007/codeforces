#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

map<int, vector<int>> pows;

void proc(int n) {
	vector<pair<int, int>> arr;
	int cur = 2;
	while (cur * cur <= n) {
		if (n % cur == 0) {
			if (!arr.empty() && arr.back().first == cur) {
				arr.back().second++;
			} else {
				arr.push_back({cur, 1});
			}
			n /= cur;
		} else {
			cur++;
		}
	}
	if (n != 1) {
		if (!arr.empty() && arr.back().first == n) {
			arr.back().second++;
		} else {
			arr.push_back({n, 1});
		}
	}
	for (auto &el : arr) {
		pows[el.first].push_back(el.second);
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		proc(a[i]);
	}
	int ans = 1;
	for (auto &el : pows) {
		int x = el.second.size();
		for (int i = 0; i < min(2LL, n - x); i++) {
			el.second.push_back(0);
		}
		sort(el.second.begin(), el.second.end());
		if (el.second.size() > 1) {
			for (int i = 0; i < el.second[1]; i++) {
				ans *= el.first;
			}
		}
	}
	cout << ans << endl;
}