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

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;

	vector<ll> cnt(2, 0);
	for (char c : s)
		++cnt[c - '0'];
	vector<ll> dp(2, 0);
	for (int i = 0; i < s.size(); ++i)
		dp[s[i] - '0'] += t[i] == '0';

	ll res = dp[0] * dp[1] + dp[0] * (cnt[1] - dp[1]) + dp[1] * (cnt[0] - dp[0]);
	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}