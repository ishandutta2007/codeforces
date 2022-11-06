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

using namespace std;
typedef long long ll;

bool f(vector<string> &grid, vector<vector<int>> &dp, int i, int j, int k) {
	for (int c = 0; c < k; ++c)
		if (i + c >= grid.size() || grid[i + c][j] == '#')
			return false;
	for (int c = 0; c < k; ++c)
		++dp[i + c][j];
	return true;
}

bool g(vector<string> &grid, vector<vector<int>> &dp, int i, int j, int k) {
	for (int c = 0; c < k; ++c)
		if (j + c >= grid.size() || grid[i][j + c] == '#')
			return false;
	for (int c = 0; c < k; ++c)
		++dp[i][j + c];
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<string> grid(n);
	for (int i = 0; i < n; ++i)
		cin >> grid[i];
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			f(grid, dp, i, j, k);
			g(grid, dp, i, j, k);
		}
	int aI = 0, aJ= 0;
	ll ans = -1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j< n; ++j)
			if (dp[i][j] > ans) {
				ans = dp[i][j];
				aI = i;
				aJ = j;
			}
	cout << aI + 1 << ' ' << aJ + 1;
	return 0;
}