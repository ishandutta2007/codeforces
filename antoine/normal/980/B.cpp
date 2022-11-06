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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<string> grid(4, string(n, '.'));
	if (k & 1) {
		vector<pair<int, int>> v;
		for (int i = 1; i < 3; ++i)
			for (int j = 1; j < n - 1; ++j)
				if (!(i == 2 && j == n / 2))
					v.emplace_back(i, j);
		sort(v.begin(), v.end(), [&](const pair<int, int> &lhs, const pair<int, int> &rhs) {
			if (lhs.first != rhs.first) return lhs.first < rhs.first;
			return abs(lhs.second - n / 2) < abs(rhs.second - n / 2);
		});
		for (int i = 0; i < k; ++i)
			grid[v[i].first][v[i].second] = '#';
	}
	else {
		for (int i = 1; i <= k / 2; ++i)
			for (int j = 1; j < 3; ++j)
				grid[j][i] = '#';
	}
	cout << "YES\n";
	for (auto &&x : grid)
		cout << x << '\n';
	return 0;
}