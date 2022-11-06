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
const ll mod = 998244353;
const ll modInv2 = 499122177;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	assert(modInv2 * 2 % mod == 1);
	
	// O(n^2)

	int N, K;
	cin >> N >> K;

	static ll dp[501];

	for (int w = 1; w <= N; ++w) {
		static ll c[501];
		c[0] = c[1] = 1;
		for (int n = 2; n <= N; ++n)
			c[n] = (2 * c[n - 1] - (w >= n ? 0 : c[n - 1 - w])) % mod;
		dp[w] = (2 * c[N]) % mod;
	}

	ll ans = 0;
	for (int w = 1; w <= N; ++w) {
		const ll cnt = dp[w] - dp[w - 1];
		const ll m = min(N, (K - 1) / w);
		const ll dans = cnt * dp[m] % mod * modInv2 % mod;
		ans = (ans + dans % mod) % mod;
	}

	cout << (ans % mod + mod) % mod << '\n';
	return 0;
}