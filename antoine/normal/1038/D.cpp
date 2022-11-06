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
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<array<ll, 2>> dp(n), dpR(n);

	dp[0][0] = abs(a[0]);
	dp[0][1] = -a[0];

	dpR[n - 1][0] = abs(a[n - 1]);
	dpR[n - 1][1] = -a[n - 1];

	for(int i = 1; i < n; ++i)
		for (int j = 0; j < 2; ++j)
			dp[i][j] = max(a[i] + dp[i - 1][j], -a[i] + dp[i - 1][max(0, j - 1)]);

	for (int i = n - 2; i >= 0; --i)
		for (int j = 0; j < 2; ++j)
			dpR[i][j] = max(a[i] + dpR[i + 1][j], -a[i] + dpR[i + 1][max(0, j - 1)]);

	ll res = -(1LL << 40); 
	for (int i = 0; i < n; ++i)
		res = max(res, a[i] + (i ? dp[i - 1][1] : 0) + (i == n - 1 ? 0 : dpR[i + 1][1]));

	cout << res;
	return 0;
}