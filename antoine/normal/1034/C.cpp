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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int p[(int)1e6];
ll s[(int)1e6];
ll dp[(int)1e6 + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	for (int i = 1; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	
	for (int i = n - 1; i > 0; --i)
		s[p[i]] += s[i];

	for (int i = 0; i < n; ++i) {
		const ll  j = s[0] / gcd(s[0], s[i]);
		if (j <= n) dp[j]++;
	}

	for (int i = n; i >= 1; --i)
		for (int j = i + i; j <= n; j += i)
			dp[j] += dp[i];

	for (int i = n; i >= 1; --i)
		if (dp[i] = dp[i] >= i && s[0] % i == 0) {
			for (int j = i + i; j <= n; j += i)
				dp[i] += dp[j];
		}

	cout << dp[1] << '\n';

	return 0;
}