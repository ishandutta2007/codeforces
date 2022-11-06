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

ll dp[20][4];

ll f(const string s) {
	ll res = 0;
	ll nzCnt = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		for (char d = '0'; d < s[i]; ++d) {
			const int _nzCnt = nzCnt + (d != '0');
			if (_nzCnt > 3) continue;
			res += dp[s.size() - (i + 1)][3 - _nzCnt];
		}
		nzCnt += s[i] != '0';
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for(int i = 0; i < 20; ++i)
		for (int j = 0; j <= 3; ++j) {
			ll &res = dp[i][j];
			if (i == 0) res = 1;
			else
				res = dp[i - 1][j] + (j ? 9 * dp[i - 1][j - 1] : 0);
		}
	int T;
	cin >> T;
	while (T--) {
		ll l, r;
		cin >> l >> r;
		cout << f(to_string(r + 1)) - f(to_string(l)) << '\n';
	}
	return 0;
}