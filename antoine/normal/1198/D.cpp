#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int cs[52][52];
int dp[52][52][52][52];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<string> grid(n);
	for (string &s : grid)
		cin >> s;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cs[i][j] = (grid[i][j] == '#') + (i ? cs[i - 1][j] : 0) + (j ? cs[i][j - 1] : 0) - (i && j ? cs[i - 1][j - 1] : 0);

	for (int x1 = n - 1; x1 >= 0; --x1)
		for (int y1 = n - 1; y1 >= 0; --y1)
			for (int x2 = x1; x2 < n; ++x2)
				for (int y2 = y1; y2 < n; ++y2) {
					int &res = dp[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
					{
						const int sum = cs[x2][y2] - (x1 ? cs[x1 - 1][y2] : 0) - (y1 ? cs[x2][y1 - 1] : 0)
								+ (x1 && y1 ? cs[x1 - 1][y1 - 1] : 0);
						if (!sum) {
							res = 0;
							continue;
						}
					}

					for (int x = x1; x < x2; ++x)
						res = min(res, dp[x1][y1][x][y2] + dp[x + 1][y1][x2][y2]);
					for (int y = y1; y < y2; ++y)
						res = min(res, dp[x1][y1][x2][y] + dp[x1][y + 1][x2][y2]);
				}

	cout << dp[0][0][n - 1][n - 1];

	return 0;
}