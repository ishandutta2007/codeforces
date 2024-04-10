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

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, d;
	string s;
	cin >> n >> d >> s;
	vector<int> dp(n, n + 1);
	dp[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		for (int j = i + 1; j <= i + d && j < n; ++j)
			if (s[j] == '1')
				dp[i] = min(dp[i], dp[j] + 1);
	}
	cout << (dp[0] > n ? -1 : dp[0]);
	return 0;
}