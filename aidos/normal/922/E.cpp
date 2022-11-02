#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()


const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, k;
ll dp[10100];
ll d[10100];
int C = 10000;
ll c[10111];
ll cost[10111];
const ll linf = (1ll << 50);
ll W, B, X;
void solve() {
	cin >> n >> W >> B >> X;
	for (int i = 0; i < n; i++) cin >> c[i];

	for (int i = 0; i < n; i++) cin >> cost[i];
	for (int j = 1; j <= C; j++) dp[j] = -linf;
	dp[0] = W;
	for (int it = 0; it < n; it++) {
		for (int j = 0; j <= C; j++) {
			d[j] = dp[j];
		}
		ll D = cost[it];
		for (int t = 1; t <= c[it]; t++) {
			for (int j = t; j <= C; j++) {
				dp[j] = max(d[j - t] - t * D, dp[j]);
			}
		}
		for (int j = 0; j <= C; j++) {
			if(dp[j] >= 0)
				dp[j] = min(dp[j]+X, W + j * B);
		}
		for (int j = 0; j <= C; j++) {
			if (dp[j] < 0) dp[j] = -linf;
		}
	}
	int ans = 0;

	for (int i = 0; i <= C; i++) {
		if (dp[i] >= 0) ans = i;
	}

	cout << ans << "\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int t = 1;
	
	for (int i = 1; i <= t; i++) {
		//printf("Case #%d\n", i);
		solve();
	}
	char c;
	//cin >> c;
	return 0;
}