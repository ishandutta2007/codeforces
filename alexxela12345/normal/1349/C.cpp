#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int INF = 1e18 + 228;

bool check(int i, int n) {
	return (0 <= i && i < n);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int t;
	cin >> t;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<vector<int>> dist(n, vector<int> (m, INF));
	vector<int> dx = {-1, 0, 0, 1};
	vector<int> dy = {0, -1, 1, 0};
	deque<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int  j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int ii = i + dx[k];
				int jj = j + dy[k];
				if (check(ii, n) && check(jj, m) && arr[i][j] == arr[ii][jj]) {
					q.push_back({i, j});
					dist[i][j] = 0;
				}
			}
		}
	}
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop_front();
		for (int k = 0; k < 4; k++) {
				int ii = i + dx[k];
				int jj = j + dy[k];
				if (check(ii, n) && check(jj, m) && dist[ii][jj] == INF) {
					q.push_back({ii, jj});
					dist[ii][jj] = dist[i][j] + 1;
				}
		}
	}
	while (t--) {
		int i, j, p;
		cin >> i >> j >> p;
		i--;
		j--;
		if (dist[i][j] > p) {
			cout << arr[i][j] << endl;
		} else {
			int cnt = p - dist[i][j];
			if (cnt % 2 == 0) {
				cout << arr[i][j] << endl;
			} else {
				int x = arr[i][j] - '0';
				x ^= 1;

				cout << (char) ('0' + x) << endl;
			}
		}
	}

			
}