#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = 59;
int n;
string grid[MxN + 9];
int color[MxN + 9][MxN + 9];

void dfs(const int x, const int y, const int num) {
	if (grid[x][y] != '0')
		return;

	if (color[x][y]) {
		if (color[x][y] == num)
			return;
		cout << 0;
		exit(0);
	}
	color[x][y] = num;
	for (int i = max(0, x - 1); i <= min(n - 1, x + 1); ++i)
		for (int j = max(0, y - 1); j <= min(n - 1, y + 1); ++j)
			if (abs(x - i) + abs(y - j) == 1)
				dfs(i, j, num);
}

int sq(int x) {
	return x * x;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	--r1, --c1, --r2, --c2;

	for (int i = 0; i < n; ++i)
		cin >> grid[i];

	dfs(r1, c1, 11);
	dfs(r2, c2, 22);

	const int Inf = 1 << 30;
	int ans = Inf;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int x = 0; x < n; ++x)
				for (int y = 0; y < n; ++y) {
					if (!grid[i][j] || !grid[x][y] || !color[i][j] || !color[x][y] || color[i][j] == color[x][y])
						continue;
					ans = min(ans, sq(i - x) + sq(j - y));
				}

	cout << ans;
	return 0;
}