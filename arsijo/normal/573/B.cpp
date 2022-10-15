#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 2e5 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int dp[n + 2];
	dp[0] = dp[n + 1] = 0;
	for(int i = 1; i <= n; i++)
		cin >> dp[i];

	for(int i = 1; i <= n; i++)
		dp[i] = min(dp[i - 1] + 1, dp[i]);
	for(int i = n; i >= 1; i--)
		dp[i] = min(dp[i + 1] + 1, dp[i]);

	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);

	cout << ans;

}