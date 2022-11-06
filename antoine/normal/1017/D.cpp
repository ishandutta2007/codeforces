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

int cnt[1 << 12];
int cost[1 << 12];
int dp[1 << 12][1201];

int w[12];

int f(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '1')
			res |= 1 << i;
		else
			assert(s[i] == '0');
	return res;
}

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i)
		cin >> w[i];

	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		const int x = f(s);
		++cnt[x];
	}

	for (int y = (1 << n) - 1; y >= 0; --y) {
		for (int i = n - 1; i >= 0; --i)
			cost[y] += (y & (1 << i)) ? 0 : w[i];
	}

	for (int x = 0; x < (1 << n); ++x) {
		for (int y = (1 << n) - 1; y >= 0; --y)
			dp[x][cost[x^y]] += cnt[y];
		partial_sum(dp[x], dp[x] + 1201, dp[x]);
	}

	for (int i = 0; i < q; ++i) {
		string s;
		int k;
		cin >> s >> k;
		const int x = f(s);
		cout << dp[x][k] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}