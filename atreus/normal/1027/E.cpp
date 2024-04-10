#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 500 + 5;
const int inf = 1e9;
const int mod = 998244353;

int ex[maxn * maxn], dp[maxn * maxn];

int main () {
	ios_base::sync_with_stdio (false);
	ll n, k;
	cin >> n >> k;
	for (int j = 1; j <= n; j++) {
		dp[0] = 1;
		int par = 1;
		for (int i = 1; i <= n; i++) {
			dp[i] = par;
			par += dp[i];
			par %= mod;
			if (i >= j)
				par = (par - dp[i - j] + mod) % mod;
		}
		ex[j] = dp[n];
	}
	for (int i = n + 1; i <= k; i++)
		ex[i] = ex[i - 1];
	ll ans = 0;
	for (int i = 1; i <= min (n, k); i++) {
		ll x = k / i;
		
		if (k % i == 0)
			x --;
		ll m = (ex[i] - ex[i - 1] + mod) % mod;
		ll mn = ex[x];
		ans += ((1ll * m * 2) % mod * mn) % mod;
		ans %= mod;
	}
	cout << ans << endl;

} // really ?