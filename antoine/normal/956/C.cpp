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
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), dp(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	dp[0] = 1;
	for (int i = 1; i < n; ++i)
		dp[i] = max(dp[i - 1], a[i] + 1);
	for (int i = n - 2; i >= 0; --i)
		dp[i] = max(dp[i], dp[i + 1] - 1);

	ll ans = 0;

	for (int i = 1; i < n; ++i)
		ans += dp[i] - a[i] - 1;

	cout << ans;
	return 0;
}