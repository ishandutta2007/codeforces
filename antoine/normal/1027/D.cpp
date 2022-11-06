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
	vector<int> a(n), c(n);
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	int ans = 0;
	vector<int> dp(n, 0);
	for (int i = 0; i < n; ++i) {
		int curr = i;
		while (dp[curr] == 0) {
			dp[curr] = 1;
			curr = a[curr];
		}
		if (dp[curr] == 1) {
			int cost = 1 << 30;
			while (dp[curr] == 1) {
				dp[curr] = 2;
				cost = min(cost, c[curr]);
				curr = a[curr];
			}
			ans += cost;
		}
		for (curr = i; dp[curr] == 1; curr = a[curr])
			dp[curr] = 2;
	}
	cout << ans;
	return 0;
}