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
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
int dp[maxn], a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	a[n + 1] = k;
	bool p = (n + 1) % 2;
	for (int i = n; i >= 0; i--) {
		dp[i] = dp[i + 1] + p * (a[i + 1] - a[i]);
		p ^= 1;
	}
	int ans = dp[0];
	for (int i = 1; i <= n; i++) {
		if (a[i] + 1 < a[i + 1] or a[i] - 1 > a[i - 1]) {
			int len = k - a[i];
			len -= dp[i];
			if (i % 2 == 1)
				len --;
			else
				len ++;
			ans = max (ans, dp[0] - dp[i] + len);
		}
	}
	cout << ans << endl;
}