#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

#define ii pair<int, int>
#define x first
#define y second

int n, a[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<ii> a2;
	vector<ii> a3;

	int cur = 1;

	vector<pair<int, int>> ans;

	for (int i = 1; i <= n; i++) {

		// cout << a2.size() << ' ' << a3.size()

		if (a[i] == 0)
			continue;
		if (a[i] == 3) {
			if (a3.size() > 0) {
				auto uu = a3.back();
				int u = uu.x;
				a3.pop_back();
				if (uu.y == 0) {
					ans.push_back({cur, u});
					ans.push_back({cur, i});
					ans.push_back({cur + 1, i});
					a3.push_back({i, cur + 1});
					cur += 2;
				} else {
					ans.push_back({uu.y, i});
					ans.push_back({cur, i});
					a3.push_back({i, cur});
					cur++;
				}
			} else {
				a3.push_back({i, 0});
			}
			continue;
		} 

		if (a[i] == 2) {
			if (a3.size() > 0) {
				auto uu = a3.back();
				int u = uu.x;
				a3.pop_back();
				if (uu.y == 0) {
					ans.push_back({cur, u});
					ans.push_back({cur, i});
					ans.push_back({cur + 1, i});
					a2.push_back({i, cur + 1});
					cur += 2;
				} else {
					ans.push_back({uu.y, i});
					ans.push_back({cur, i});
					a2.push_back({i, cur});
					cur++;
				}
			} else {
				a2.push_back({i, 0});
			}
			continue;
		}

		if (a[i] == 1) {
			if (a2.size()) {
				auto uu = a2.back();
				a2.pop_back();
				int u = uu.x;
				if (uu.y == 0) {
					ans.push_back({cur, u});
					ans.push_back({cur, i});
					cur++;
				} else {
					ans.push_back({uu.y, i});
				}
			} else if (a3.size()) {
				auto uu = a3.back();
				a3.pop_back();
				int u = uu.x;
				if (uu.y == 0) {
					ans.push_back({cur, u});
					ans.push_back({cur, i});
					ans.push_back({cur + 1, i});
					cur += 2;
				} else {
					ans.push_back({uu.y, i});
					ans.push_back({cur, i});
					cur++;
				}
			} else {
				ans.push_back({cur, i});
				cur++;
			}
		}
	}

	if (a2.size() > 0 || a3.size() > 0) {
		cout << -1 << '\n';
	} else {
		cout << ans.size() << '\n';
		for (auto e : ans) {
			cout << e.first << ' ' << e.second << '\n';
		}
	}

	return 0;
}