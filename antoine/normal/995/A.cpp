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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

// C

int n, k;
int grid[4][50];
vector<array<int, 3>> ans;

bool circulate(int i, int j, int x, int y) {
	if (!grid[i][j]) return false;
	if (grid[x][y] && grid[x][y] != grid[i][j])
		return false;
	grid[x][y] = grid[i][j];
	ans.push_back({ grid[x][y], x, y });
	grid[i][j] = 0;
	return true;
}

bool park() {
	bool res = false;
	for (int j = 0; j < n; ++j) {
		for (auto x : vector<pair<int, int>>{ {1, 0}, {2, 3} }) {
			if (grid[x.second][j] && circulate(x.first, j, x.second, j)) {
				assert(--k >= 0);
				res = true;
			}
		}
	}
	return res;
}

void cycle() {
	assert(k > 0);
	static int cycleCount = 0;
	if (++cycleCount >= 2 * n) {
		cout << -1;
		exit(0);
	}
	if (n == 1) {
		if (grid[1][0]) {
			circulate(1, 0, 2, 0);
		}
		else if (grid[2][0]) {
			circulate(2, 0, 1, 0);
		}
		return;
	}
	int freeX = -1, freeY = -1;
	for (int i = 1; i <= 2; ++i)
		for (int j = 0; j < n; ++j)
			if (!grid[i][j]) {
				freeX = i;
				freeY = j;
			}

	assert(freeX != -1 && freeY != -1);
	for (int iter = 2 * n - 2; iter >= 0; --iter) {
		assert(freeX == 1 || freeX == 2);
		assert(0 <= freeY && freeY < n);
		if (freeX == 1) {
			if (freeY != n - 1) {
				circulate(freeX, freeY + 1, freeX, freeY);
				freeY++;
			} else {
				circulate(freeX + 1, freeY, freeX, freeY);
				freeX++;
			}
		} else {
			if (freeY) {
				circulate(freeX, freeY - 1, freeX, freeY);
				freeY--;
			} else {
				circulate(freeX - 1, freeY, freeX, freeY);
				freeX--;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < n; ++j)
			cin >> grid[i][j];

	park();
	if (k == 2 * n) {
		cout << -1;
		return 0;
	}
	while (k) {
		cycle();
		park();
	}
	
	cout << ans.size() << '\n';
	for (auto &&x : ans)
		cout << x[0] << ' ' << x[1] + 1 << ' ' << x[2] + 1 << '\n';
	return 0;
}