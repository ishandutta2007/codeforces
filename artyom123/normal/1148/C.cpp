#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> pos(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	vector <pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		if (pos[i + 1] == i) {
			continue;
		}
		int pos1 = i;
		int pos2 = pos[i + 1];
		swap(pos[i + 1], pos[a[i]]);
		if (abs(pos1 - pos2) >= n / 2) {
			swap(a[i], a[pos2]);
			ans.push_back({i, pos2});
			continue;
		}
		else {
			if (pos1 > pos2) {
				swap(pos1, pos2);
			}
			if (pos1 >= n / 2) {
				swap(a[pos2], a[0]);
				ans.push_back({0, pos2});
				swap(a[0], a[pos1]);
				ans.push_back({0, pos1});
				swap(a[0], a[pos2]);
				ans.push_back({0, pos2});
				continue;
			}
			if (n - 1 - pos2 >= n / 2) {
				swap(a[pos2], a[n - 1]);
				ans.push_back({n - 1, pos2});
				swap(a[n - 1], a[pos1]);
				ans.push_back({n - 1, pos1});
				swap(a[n - 1], a[pos2]);
				ans.push_back({n - 1, pos2});
				continue;
			}
			else {
				swap(a[pos2], a[0]);
				ans.push_back({pos2, 0});
				swap(a[0], a[n - 1]);
				ans.push_back({n - 1, 0});
				swap(a[n - 1], a[pos1]);
				ans.push_back({n - 1, pos1});
				swap(a[0], a[n - 1]);
				ans.push_back({0, n - 1});
				swap(a[pos2], a[0]);
				ans.push_back({pos2, 0});
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto &c : ans) {
		cout << c.first + 1 << " " << c.second + 1 << "\n";
	}
	return 0;
}