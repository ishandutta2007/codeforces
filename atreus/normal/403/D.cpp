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
const int maxn = 1e3 + 100;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll dp[maxn][100], fac[maxn], c[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n = 1000, k = 50;
	
	dp[0][1] = 1;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int l = k; l >= 1; l--) {
			for (int j = n; j >= 0; j--) {
				dp[j][l] = dp[j][l];
				if (j >= i)
					dp[j][l] += dp[j - i][l - 1];
				dp[j][l] %= mod;
//				cout << i << " " << j << " " << l << " " << dp[i][j][l] << endl;
			}
		}
	}
	
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % mod;

	c[0][0] = 1;
	for (int i = 1; i <= n + k; i++) {
		c[0][i] = 1;
		for (int j = 1; j <= i; j++)
			c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % mod;
	}

	int tc;
	cin >> tc;
	while (tc --) {
		int a, b;
		cin >> a >> b;
		if (b > 50) {
			cout << 0 << '\n';
			continue;
		}
		ll ans = 0;
		for (int i = 0; i <= a; i++) {
			ll tmp = (((dp[i][b] * fac[b]) % mod) * c[b][a - i]) % mod;
//			cout << dp[a][i][b] << " " << fac[b] << " " << c[b][a - i] << " " << tmp << endl;
			ans += tmp;
			ans %= mod;
		}
		cout << ans << endl;
	}
}