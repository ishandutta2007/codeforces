#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	auto check = [&](int i, int j) {
		int val = 0;
		for (int u = 0; u < 2; u++) {
			for (int v = 0; v < 2; v++) {
				int x = i + u, y = j + v;
				// if (x < 0 || x >= n || y < 0 || y >= m) continue;
				if (a[x][y] > 0) val = a[x][y];
			}
		}
		for (int u = 0; u < 2; u++) {
			for (int v = 0; v < 2; v++) {
				int x = i + u, y = j + v;
				// if (x < 0 || x >= n || y < 0 || y >= m) continue;
				if (a[x][y] > 0 && a[x][y] != val) 
					return 0;
			}
		}
		return val;
	};

	auto aa = a;

	vector<vector<int>> pushed(n, vector<int>(m));
	vector<tuple<int, int, int>> res;
	queue<pair<int, int>> q;
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			int baz = check(i, j);
			if (baz) {
				q.push({i, j});
				pushed[i][j] = true;
				res.emplace_back(i, j, baz);
			}
		}
	}
	while (!q.empty()) {
		auto foo = q.front();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				a[foo.first + i][foo.second + j] = 0;
			}
		}
		q.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int x = foo.first + i;
				int y = foo.second + j;
				if (x < 0 || x >= n - 1 || y < 0 || y >= m - 1 || pushed[x][y])
					continue;
				int baz = check(x, y);
				if (baz == 0) 
					continue;
				pushed[x][y] = true;
				q.push({x, y});
				res.emplace_back(x, y, baz);
			}
		}
	}
	reverse(res.begin(), res.end());
	vector<vector<int>> b(n, vector<int>(m));
	for (auto [u, v, col] : res) {
		b[u][v] = b[u + 1][v] = b[u][v + 1] = b[u + 1][v + 1] = col;
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cerr << b[i][j] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] != aa[i][j]) return cout << -1 << '\n', 0;
		}
	}
	cout << res.size() << '\n';
	for (auto [u, v, col] : res) {
		cout << u + 1 << ' ' << v + 1 << ' ' << col << '\n';
	}
}