#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int k, n, m;
	cin >> k >> n >> m;
	deque<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	vector<int> ans;
	while (!a.empty() || !b.empty()) {
		if (!a.empty()) {
			if (a.front() <= k) {
				k += (a.front() == 0);
				ans.push_back(a.front());
				a.pop_front();
				continue;
			}
		}
		if (!b.empty()) {
			if (b.front() <= k) {
				k += (b.front() == 0);
				ans.push_back(b.front());
				b.pop_front();
				continue;
			}
		}
		cout << -1 << '\n';
		return;
	}
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}