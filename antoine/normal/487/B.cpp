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
#include <deque>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

ll a[(int)1e5];
ll minE[(int)1e5][18];
ll maxE[(int)1e5][18];
ll maxP2LE[(int)1e5 + 1];
ll dp[(int)1e5 + 1];

ll query(int i, int j) {
	int k = maxP2LE[j - i];
	assert(k >= 0 && k <= 20);
	assert((1 << (k + 1)) > j - i && (1 << k) <= j - i);
	ll qMin = min(minE[i][k], minE[j - (1 << k)][k]);
	ll qMax = max(maxE[i][k], maxE[j - (1 << k)][k]);
	assert(qMin <= qMax);
	return qMax - qMin;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, s, l;
	cin >> n >> s >> l;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		minE[i][0] = a[i];
		maxE[i][0] = a[i];
	}

	for (int k = 1; (1 << k) <= n; ++k) {
		for (int i = 0; i + (1 << k) <= n; ++i) {
			minE[i][k] = min(minE[i][k - 1], minE[i + (1 << (k - 1))][k - 1]);
			maxE[i][k] = max(maxE[i][k - 1], maxE[i + (1 << (k - 1))][k - 1]);
		}
		for (int i = 1 << k; i <= min((int)n, (1 << (k + 1)) - 1); ++i)
			maxP2LE[i] = k;
	}

	fill(dp, dp + n, (int)1e9);

	deque<int> window;

	for (int i = n - l; i >= 0; --i) {
		while (!window.empty() && dp[window.front()] >= dp[i + l])
			window.pop_front();
		window.push_front(i + l);

		while (!window.empty() && query(i, window.back()) > s)
			window.pop_back();

		if (!window.empty())
			dp[i] = 1 + dp[window.back()];
	}
	cout << (dp[0] > n ? -1 : dp[0]);
	return 0;
}