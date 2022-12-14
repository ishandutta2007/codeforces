#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 500;;
const int mod = 998244353;
const ll inf = (1ll << 62);
ll c[maxn][maxn], dp[maxn], a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	c[0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		c[0][i] = 1;
		for (int j = 1; j <= i; j++) {
			c[j][i] = c[j - 1][i - 1] + c[j][i - 1];
			c[j][i] %= mod;
		}
	}
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	dp[n + 1] = 1;
	for (int i = n; i >= 1; i --) {
		if (a[i] <= 0 or a[i] >= n)
			continue;
		for (int j = i + 1; j <= n + 1; j++) {
			int len = j - i - 1;
			dp[i] += c[a[i]][len] * dp[j];
			dp[i] %= mod;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[i];
		ans %= mod;
	}
	cout << ans << endl;
}