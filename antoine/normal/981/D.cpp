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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

ll N, K;
ll a[55];
ll dp[55][55];

int f(ll i, ll k, const ll beauty) {
	if (i == N) return k == 0;
	if (k <= 0) return 0;
	if (dp[i][k] != -1)
		return dp[i][k];
	ll sum = 0;
	ll &ans = dp[i][k];
	for (ll j = i; j < N; ++j) {
		sum += a[j];
		if ((sum & beauty) != beauty) continue;
		if (f(j + 1, k - 1, beauty)) return ans = 1;
	}
	return ans = 0;
}

bool f(ll beauty) {
	memset(dp, -1, sizeof dp);
	return f(0, K, beauty);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll k;
	cin >> N >> K;
	for (ll i = 0; i < N; ++i)
		cin >> a[i];
	ll beauty = 0;
	for (ll mask = 1ll << 60; mask; mask >>= 1) {
		if (f(beauty | mask)) {
			beauty |= mask;
		}
	}
	cout << beauty;
	return 0;
}