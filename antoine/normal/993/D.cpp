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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> tasks(n);
	for (int i = 0; i < n; ++i)
		cin >> tasks[i].first;
	for (int i = 0; i < n; ++i)
		cin >> tasks[i].second;

	map<int, vector<int>> taskMp;
	for (int i = 0; i < n; ++i)
		taskMp[tasks[i].first].push_back(tasks[i].second);

	for (auto &&x : taskMp) {
		sort(x.second.begin(), x.second.end());
		for (int c = 1; c < x.second.size(); ++c)
			x.second[c] += x.second[c - 1];
		x.second.insert(x.second.begin(), 0);
	}

	const int maxK = 50 * 50;
	static ll dp[51][51][maxK + 1];

	memset(dp, 64, sizeof dp);
	dp[taskMp.size()][0][0] = 0;

	/*

	dp[i][j][k]: min total power on 1st level

	i: submap [i...)
	j: number of tasks on second level to cover
	k: number of processors on second level in [i...)

	*/

	for (int i = taskMp.size() - 1; i >= 0; --i) {
		const auto it = next(taskMp.begin(), i);
		const ll a = it->first;
		const vector<int> &bArr = it->second;
		const int C = (int)bArr.size() - 1;
		assert(C > 0 && C <= n && bArr[0] == 0);

		for (int j = n; j >= 0; --j) {
			for (int k = maxK; k >= 0; --k) {
				ll &res = dp[i][j][k];
				for (int c = C; c >= 0; --c) {
					if (bArr[c] > k) continue;
					const int newJ = max(0, j - (C - c)) + c;
					if (newJ > n) continue;
					res = min(res, a * (C - c) + dp[i + 1][newJ][k - bArr[c]]);
				}
			}
		}
	}

	const int sumB = accumulate(taskMp.begin(), taskMp.end(), 0, [](const int &acc, const pair<int, vector<int>> &p) {
		return acc + p.second.back();
	});

	double ans = 4e18;
	for (int k = min(maxK, sumB - 1); k >= 0; --k) {
		ans = min(ans, (double)dp[0][0][k] / (sumB - k));
	}
	cout << (ll)ceil(ans * 1000.0);
	return 0;
}