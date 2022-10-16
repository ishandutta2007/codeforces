#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (n % 2) {
		cout << "NO" << '\n';
	} else {
		vector<int> bot, top;
		vector<int> ans(n);
		for (int i = 0; i < n / 2; ++i) {
			ans[2  * i] = a[i];
			ans[2 * i + 1] = a[i + n / 2];
		}
		for (int i = 0; i < n; ++i) {
			int lef = ans[(i - 1 + n) % n];
			int rig = ans[(i + 1) % n];
			if (lef < ans[i] && rig < ans[i] || lef > ans[i] && rig > ans[i]) {
				continue;
			} else {
				cout << "NO" << '\n';
				return;
			}
		}
		cout << "YES" << '\n';
		for (int x : ans) {
			cout << x << ' ';
		}
		cout << '\n';  
	}
}

/**
 * you want the things to be alternating 
 * small half, large half
 * then split
 * 1 2 3 4 5 6
 */

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