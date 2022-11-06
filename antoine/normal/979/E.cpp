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
const ll mod = (ll)1e9 + 7;

int n;
int c[50];
ll dp[50][51][51][2];

/*
50 1
-1 -1 1 0 1 1 0 -1 1 0 -1 -1 0 0 -1 -1 0 1 1 -1 1 0 -1 1 1 -1 -1 -1 1 -1 -1 0 -1 0 -1 0 0 -1 -1 0 1 -1 0 1 -1 1 0 -1 -1 1
*/
ll f(int i, int w, int b, int p) {
	if (w < 0 || b < 0 || w + b > n - i) return 0;
	if (i == n) return !(w | b | p);

	assert(n <= 50 && n >= 0 && i >= 0 && i < n && p >= 0 && p < 2);
	assert(c[i] >= -1 && c[i] <= 1);

	ll &res = dp[i][w][b][p];
	if (res != -1) return res;
	res = 0;
	if (c[i] != 1) {
		res += f(i + 1, w - 0, b, +p) * (n - (i + 1) - b < 0 ? 0 : (1ll << (n - (i + 1) - b)) % mod) % mod * (b ? (1ll << (b - 1)) % mod : 0) % mod;
		res += f(i + 1, w - 1, b, !p) * (n - (i + 1) - b < 0 ? 0 : (1ll << (n - (i + 1) - b)) % mod) % mod * (b ? (1ll << (b - 1)) % mod : 1) % mod;
	}
	if (c[i] != 0) {
		res += f(i + 1, w, b - 0, +p) * (n - (i + 1) - w < 0 ? 0 : (1ll << (n - (i + 1) - w)) % mod) % mod * (w ? (1ll << (w - 1)) % mod : 0) % mod;
		res += f(i + 1, w, b - 1, !p) * (n - (i + 1) - w < 0 ? 0 : (1ll << (n - (i + 1) - w)) % mod) % mod * (w ? (1ll << (w - 1)) % mod : 1) % mod;
	}
	assert(res <= 4ll * mod);
	return res %= mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
		cin >> c[i];

	memset(dp, -1, sizeof dp);

	ll res = 0;

	for (int w = 0; w <= n; ++w)
		for (int b = 0; b <= n; ++b)
			res = (res + f(0, w, b, p)) % mod;
	cout << res;
	return 0;
}