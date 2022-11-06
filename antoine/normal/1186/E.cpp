#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

int n, m, Q;
int grid[2009][2009];

ll f(const int x, const int y) {
	int xx = x % n;
	int yy = y % m;

	// if (xx == n - 1 || yy == m - 1)		return (x + 1LL) * (y + 1LL) / 2;
	ll ans = ((x + 1LL) * (y + 1LL) - (xx + 1LL) * (yy + 1LL)) / 2;

	ll temp = grid[xx][yy];

	if ((__builtin_popcount(x / n) + __builtin_popcount(y / m)) & 1)
		temp = (xx + 1LL) * (yy + 1LL) - temp;
	assert(temp >= 0);
	ans += temp;
/*
	if (ans != grid[x][y]) {
		DBG(ans)
		DBG(grid[x][y])
		DBG(ans - temp + (xx + 1LL) * (yy + 1LL) - temp)
	}*/
	return ans;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m >> Q;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			grid[i][j] = s[j] == '1';
			assert(s[j] == '0' || s[j] == '1');

		}
	}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				grid[i + n][j + m] = grid[i][j];
				grid[n + i][j] = !grid[i][j];
				grid[i][m + j] = !grid[i][j];
			}
		n *= 2, m *= 2;


	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (i)
				grid[i][j] += grid[i - 1][j];
			if (j)
				grid[i][j] += grid[i][j - 1];
			if (i && j)
				grid[i][j] -= grid[i - 1][j - 1];
			if (i == n - 1 || j == m - 1)
				assert(grid[i][j] == (i + 1LL) * (j + 1LL) / 2);
		}

	while (Q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1, --y1, --x2, --y2;

		ll ans = f(x2, y2);
		if (x1)
			ans -= f(x1 - 1, y2);
		if (y1)
			ans -= f(x2, y1 - 1);
		if (x1 && y1)
			ans += f(x1 - 1, y1 - 1);
		cout << ans << '\n';
	}
	return 0;
}