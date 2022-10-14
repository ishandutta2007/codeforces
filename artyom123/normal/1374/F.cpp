#include <bits/stdc++.h>

using namespace std;

int main() {
	auto make = [](vector<int> &a, int pos) {
		swap(a[pos + 1], a[pos + 2]);
		swap(a[pos], a[pos + 1]);
	};

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<pair<int, int>> res(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			res[i] = {a[i], i};
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < n; ++i) {
			a[res[i].second] = i;
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				cnt += a[j] < a[i];
			}
		}
		if (cnt & 1) {
			for (int i = 0; i < n - 1; ++i) {
				if (res[i].first == res[i + 1].first) {
					swap(a[res[i].second], a[res[i + 1].second]);
					break;
				}
			}
		}
		vector<int> ans;
		for (int i = 0; i < n - 2; ++i) {
			int pos = min_element(a.begin() + i, a.end()) - a.begin();
			while (pos > i + 1) {
				make(a, pos - 2);
				ans.push_back(pos - 2);
				pos -= 2;
			}
			if (pos != i) {
				make(a, i);
				make(a, i);
				ans.push_back(i);
				ans.push_back(i);
				pos = i;
			}
		}
		/*
		for (int i = 0; i < 3; ++i) {
			if (is_sorted(a.begin(), a.end())) {
				break;
			}
			make(a, n - 3);
			ans.push_back(n - 3);
		}
		*/
		if (!is_sorted(a.begin(), a.end())) {
			cout << -1 << endl;
		} else {
			cout << ans.size() << endl;
			for (auto it : ans) cout << it + 1 << " ";
			cout << endl;
		}
	}

	return 0;
}