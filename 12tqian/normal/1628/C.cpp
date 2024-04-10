#include <bits/stdc++.h>

using namespace std;

const vector<vector<int>> case0;

const vector<vector<int>> case2 = {
		{1, 1},
		{0, 0}};

const vector<vector<int>> case4 = {
		{1, 1, 1, 1},
		{0, 1, 1, 0},
		{1, 1, 1, 1},
		{0, 0, 0, 0}};

const vector<vector<int>> case6 = {
		{1, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 0},
		{1, 1, 0, 0, 1, 1},
		{0, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0},
};

void gen(int n, int di, int dj, vector<vector<int>>& a) {
	if (n <= 6) {
		vector<vector<int>> base;
		switch (n) {
			case 0:
				base = case0;
				break;
			case 2:
				base = case2;
				break;
			case 4:
				base = case4;
				break;
			case 6:
				base = case6;
				break;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i + di][j + dj] = base[i][j];
			}
		}
	} else {
		for (int j = 0; j < n; ++j) {
			a[di][dj + j] = 1;
			a[di + n - 2][dj + j] = 1;
		}
		for (int j = 1; j < n - 1; ++j) {
			a[di + 1][dj + j] = 1;
			a[di + n - 3][dj + j] = 1;
		}
		for (int i = 2; i < n - 3; i += 2) {
			a[di + i][dj] = 1;
			a[di + i][dj + 1] = 1;
			a[di + i][dj + n - 2] = 1;
			a[di + i][dj + n - 1] = 1;
		}
		for (int i = 3; i < n - 3; i += 2) {
			a[di + i][dj + 1] = 1;
			a[di + i][dj + 2] = 1;
			a[di + i][dj + n - 3] = 1;
			a[di + i][dj + n - 2] = 1;
		}
		gen(n - 8, di + 4, dj + 4, a);
	}
}

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> use(n, vector<int>(n));
	gen(n, 0, 0, use);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans ^= (use[i][j] * a[i][j]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}