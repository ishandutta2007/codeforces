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

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

const int MaxDP = (int)1e5;
ll cntDiv[MaxDP + 1];

ll f(int n, int k) {
	switch (k) {
	case 1:
		return n;
	case 2:
		return (n + 1) * n / 2;
	case 3:
		return (n + 2) * (n + 1) * n / 6;
	default:
		assert(false);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= MaxDP; ++i)
		for (int j = i; j <= MaxDP; j += i)
			++cntDiv[j];

	set<map<int, int>> s;
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			for(int k = 0; k < 8; ++k)
				if ((i & 1) && (j & 2) && (k & 4)) {
					map<int, int> mp;
					++mp[i];
					++mp[j];
					++mp[k];
					s.insert(mp);
				}

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		const int iA = cntDiv[a];
		const int iB = cntDiv[b];
		const int iC = cntDiv[c];
		const int iAB = cntDiv[gcd(a, b)];
		const int iBC = cntDiv[gcd(b, c)];
		const int iAC = cntDiv[gcd(a, c)];
		const int iABC = cntDiv[gcd(a, gcd(b, c))];

		static int dp[8];
		dp[0] = 0;
		dp[1] = iA - iAB - iAC + iABC;
		dp[2] = iB - iAB - iBC + iABC;
		dp[4] = iC - iAC - iBC + iABC;
		dp[3] = iAB - iABC;
		dp[5] = iAC - iABC;
		dp[6] = iBC - iABC;
		dp[7] = iABC;

		ll ans = 0;
		for (auto &&mp : s) {
			ll c = 1;
			if (mp.size() == 1) {
				cout << "";
			}
			for (auto &&x : mp)
				c *= f(dp[x.first], x.second);
			ans += c;
		}
		cout << ans << '\n';
	}

	return 0;
}