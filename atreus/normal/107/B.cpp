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
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef unsigned long long ull;
const int maxn = 1e2 + 5;
const int mod = 1e9 + 7;
const int block = 700;

ll dp[10 * maxn][maxn];
int c[200][200], a[1001];

ll power (ll a, ll b) {
	if (b == 0)
		return 1;
	ll ret = power (a, b / 2);
	ret = ret * ret % mod;
	if (b & 1)
		ret *= a;
	return ret % mod;
}

int main() {	
	ios_base::sync_with_stdio (false);
	int n, m, h;
	cin >> n >> m >> h;
	int tot = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		tot += a[i];
	}
	if (tot < n)
		return cout << -1 << endl, 0;
	swap (a[h], a[1]);
	ld ans = 1;
	for (int i = tot - a[1] + 1; i <= tot - 1; i++)
		ans *= 1.0 / i;
	for (int i = tot - a[1] - n + 2; i <= tot - n; i++)
		ans *= i;
	cout << fixed << setprecision (6) << 1.0 - ans << endl, 0;
}