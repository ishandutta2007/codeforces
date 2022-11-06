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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];

	int ans1 = 0;
	int ans2 = 0;

	for (int j = 0; j < m; ++j) {
		int sum = 0;
		int rem = 0;
		for (int i = 0; i < min(n, k); ++i)
			sum += v[i][j];

		int bestSum = sum;
		int bestRem = 0;

		for (int i = 1; i < n; ++i) {
			rem += v[i - 1][j];
			sum -= v[i - 1][j];
			sum += i + k - 1 < n && v[i + k - 1][j];
			if (v[i][j] && sum > bestSum) {
				bestSum = sum;
				bestRem = rem;
			}
		}

		ans1 += bestSum;
		ans2 += bestRem;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}