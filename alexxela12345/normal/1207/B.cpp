#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] == 4) {
				ans.push_back({i, j});
			}
		}
	}
	vector<vector<int>> b(n, vector<int> (m));
	for (auto el : ans) {
		int i = el.first;
		int j = el.second;
		b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
	}
	if (arr != b) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for (auto el : ans) {
		cout << el.first + 1 << " " << el.second + 1 << endl;
	}
}