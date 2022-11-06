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

int n;
int a[5002];
int dp[5002][2505][2][2];

// careful overflow!

int f(int i, int j, bool canInc, bool prevInc) {
	assert(!canInc || !prevInc);

	int &res = dp[i][j][canInc][prevInc];
	if (res != -1) return res;
	if (i == n) return res = j ? 1 << 30 : 0;

	int height = prevInc ? min(a[i], a[i - 1] - 1) : a[i];
	const int cost = abs(a[i] - height); // !!

	res = cost + dp[i + 1][j][false][false];
	res = min(res, cost + max(0, height - a[i + 1] + 1) + dp[i + 1][j][true][false]);
	if (canInc && j) res = min(res, dp[i + 1][j - 1][false][true]);

	assert(res >= 0);
	res = min(res, 1 << 30);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = n; i >= 0; --i) {
		for (int j = (n + 1) / 2; j >= 0; --j) {
			for (int canInc = 0; canInc < 2; ++canInc)
				for (int prevInc = 0; canInc + prevInc < 2; ++prevInc) {
					f(i, j, canInc, prevInc);
				}
		}
	}
	for (int j = 1; j <= (n + 1) / 2; ++j)
		cout << f(0, j, true, false) << ' ';
	return 0;
}