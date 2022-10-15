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
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e6 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, k;
	cin >> n >> k;

	int ar[n];
	for(int i = 0; i < n; i++)
	cin >> ar[i];

	sort(ar, ar + n);

	int a = n / k;
	int b = n % k;

	ll dp[k + 1][b + 1];
	for(int i = 0; i <= k; i++) {
		for(int j = 0; j <= b; j++) {
			dp[i][j] = 1e9;
		}
	}
	dp[0][0] = 0;

	for(int i = 1; i <= k; i++) {
		for(int j = 0; j <= b; j++) {
			dp[i][j] = min(dp[i - 1][j] + ar[i * a - 1 + j] - ar[(i - 1) * a + j],
					(j == 0 ? INT_MAX :
							dp[i - 1][j - 1] + ar[i * a - 1 + j]
							- ar[i * a - 1 + j - a]));
		}
	}

	cout << dp[k][b];

}