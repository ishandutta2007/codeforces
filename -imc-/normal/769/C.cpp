#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int xx[4] = {1, 0, 0, -1};
int yy[4] = {0, -1, 1, 0};
string dir = "DLRU";

int main() {
	ios_base::sync_with_stdio(0);
	int n = nxt(), m = nxt(), k = nxt();
	vector<string> a(n);
	for (itn i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (k % 2) {
		puts("IMPOSSIBLE");
		return 0;
	}

	vector<vector<int>> len(n, vector<int>(m, -1));
	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'X') {
				x = i, y = j;
			}
		}
	}

	len[x][y] = 0;
	queue<pair<int, int>> q;
	q.emplace(x, y);
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		x = p.first, y = p.second;
		for (int i = 0; i < 4; ++i) {
			int nx = x + xx[i], ny = y + yy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (len[nx][ny] > -1 || a[nx][ny] == '*') {
				continue;
			}
			len[nx][ny] = len[x][y] + 1;
			q.emplace(nx, ny);
		}
	}

	x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'X') {
				x = i, y = j;
			}
		}
	}

	string res = "";
	while (k) {
		int i = 0;
		while (i < 4) {
			int nx = x + xx[i], ny = y + yy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				++i;
				continue;
			}
			if (a[nx][ny] == '*') {
				++i;
				continue;
			}
			if (len[x][y] == k && len[nx][ny] != k - 1) {
				++i;
				continue;
			}
			break;
		}
		if (i == 4) {
			puts("IMPOSSIBLE");
			return 0;
		}
		res += dir[i];
		x += xx[i];
		y += yy[i];
		--k;
	}

	cout << res << "\n";

	return 0;
}