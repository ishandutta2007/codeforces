#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
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
const int maxn = 2e5 + 50;
const int Maxn = 5e3 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int a[maxn], c[maxn], f[maxn], h[maxn], dp[Maxn][Maxn], cnt[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n * k; i++) {
		cin >> a[i];
		c[a[i]] ++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		cnt[f[i]] ++;
	}
	for (int i = 1; i <= k; i++)
		cin >> h[i];
	for (int i = 1; i <= n*k; i++) 
		for (int j = 1; j <= n; j++) 
			for (int l = 0; l <= min (k, i); l++) 
				dp[i][j] = max (dp[i][j], dp[i - l][j - 1] + h[l]);	
	ll ans = 0;
	for (int i = 1; i <= 1e5; i++) { 
//		if (c[i] > 0)
//			cout << c[i] << " " << cnt[i] << " " << dp[c[i]][cnt[i]] << endl;
		ans += dp[c[i]][cnt[i]];
	}
	cout << ans << endl;
}