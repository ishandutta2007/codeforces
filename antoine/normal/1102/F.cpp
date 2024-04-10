#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Inf = (int) 2e9 + 9;

int getC(const vector<int> v1, const vector<int> v2) {
	int res = Inf;
	for (int i = 0; i < (int) v1.size(); ++i)
		res = min(res, abs(v1[i] - v2[i]));
	return res;
}

int getC2(const vector<int> v1, const vector<int> v2) { // 1 bottim 2 top
	int res = Inf;
	for (int i = 0; i + 1 < (int) v1.size(); ++i)
		res = min(res, abs(v1[i] - v2[i + 1]));
	return res;
}

int C[20][20];
int C2[20][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(C, 120, sizeof C);
	memset(C2, 120, sizeof C2);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			C[i][j] = getC(grid[i], grid[j]);
			C2[i][j] = getC2(grid[i], grid[j]);
			// cerr << C[i][j] << ' ' << C2[i][j] << endl;
		}

	int ans = 0;
	for (int start = 0; start < n; ++start) {
		static int dp[20][1 << 16];
		for (int mask = 0; mask < (1 << n); ++mask)
			for (int u = 0; u < n; ++u) {
				if (mask & (1 << u))
					continue;
				int &res = dp[u][mask];
				if (!mask)
					res = C2[u][start];
				else {
					res = 0;
					for (int v = 0; v < n; ++v)
						if (mask & (1 << v)) {
							assert(v != u);
							res = max(res, min(C[u][v], dp[v][mask ^ (1 << v)]));
						}
				}
			}

		ans = max(ans, dp[start][((1 << n) - 1) ^ (1 << start)]);
	}
	cout << ans;
	return 0;
}