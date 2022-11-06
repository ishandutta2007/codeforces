#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <deque>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int n, m;
string grid[1000];
int maxU[1000][1000];
int maxD[1000][1000];
int maxL[1000][1000];
int maxR[1000][1000];

int rows[1000][1001];
int cols[1001][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> grid[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < m; ++j)
			if (grid[i][j] == '*' && grid[i][j - 1] == '*')
				maxL[i][j] = maxL[i][j - 1] + 1;

		for (int j = m - 2; j >= 0; --j)
			if (grid[i][j] == '*' && grid[i][j + 1] == '*')
				maxR[i][j] = maxR[i][j + 1] + 1;
	}

	for (int j = 0; j < m; ++j) {
		for (int i = 1; i < n; ++i)
			if (grid[i][j] == '*' && grid[i - 1][j] == '*')
				maxU[i][j] = maxU[i - 1][j] + 1;

		for (int i = n - 2; i >= 0; --i)
			if (grid[i][j] == '*' && grid[i + 1][j] == '*')
				maxD[i][j] = maxD[i + 1][j] + 1;
	}

	vector<array<int, 3>> ans;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if (grid[i][j] == '*') {
				const int d = min(min(maxU[i][j], maxD[i][j]), min(maxL[i][j], maxR[i][j]));
				assert(d >= 0);
				if (d == 0) continue;
				ans.push_back({ i, j, d });
				rows[i][j - d]++;
				rows[i][j + d + 1]--;
				cols[j][i - d]++;
				cols[j][i + d + 1]--;
			}

	for (int i = 0; i < n; ++i)
		partial_sum(rows[i], rows[i] + m, rows[i]);
	for (int j = 0; j < m; ++j)
		partial_sum(cols[j], cols[j] + n, cols[j]);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if (grid[i][j] == '*' && !rows[i][j] && !cols[j][i]) {
				cout << -1;
				return 0;
			}
			else if (grid[i][j] == '.')
				assert(!rows[i][j] && !cols[j][i]);

	cout << ans.size() << '\n';
	for (auto &&x : ans)
		cout << x[0] + 1 << ' ' << x[1] + 1 << ' ' << x[2] << '\n';
	return 0;
}