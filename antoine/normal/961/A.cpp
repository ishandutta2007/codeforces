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
#include <stack>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> dp(n, 0);
	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c;
		++dp[c - 1];
	}

	int ans = 1e9;
	for (auto &&x : dp)
		ans = min(ans, x);
	cout << ans;

	return 0;
}