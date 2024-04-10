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
	string a, b;
	cin >> n >> a >> b;
	vector<int> dp(n + 1, 0);
	dp[n - 1] = a[n - 1] != b[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] == b[i])
			dp[i] = dp[i + 1];
		else {
			dp[i] = 1 + dp[i + 1];
			if (a[i] == b[i + 1] && a[i + 1] == b[i])
				dp[i] = min(dp[i], 1 + dp[i + 2]);
		}
	}

	cout << dp[0] << endl;
	return 0;
}