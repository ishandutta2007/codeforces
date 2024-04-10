#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;
const int MxN = 1009;
const int MxX = (int) 1e5 + 9;
int a[MxN + 9];
int nxt[2 * MxX + 9];
int dp[MxN + 9][MxN + 9];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, K;
	cin >> n >> K;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);

	for (int &x : nxt)
		x = n;
	for (int i = n - 1; i >= 0; --i)
		nxt[a[i]] = i;
	for (int i = int(sizeof nxt / sizeof nxt[0]) - 2; i >= 0; --i)
		nxt[i] = min(nxt[i], nxt[i + 1]);

	cerr << "Test" << endl;
	ll ans = 0;
	for (int m = 1;; ++m) {
		for (int i = n - 1; i >= 0; --i) {
			dp[i][0] = 1;
			for (int k = 1; k <= K; ++k) {
				const int j = max(i + 1, nxt[a[i] + m]);
				dp[i][k] = (dp[i + 1][k] + (j < n ? dp[j][k - 1] : k == 1)) % mod;
			}
		}
		if (!dp[0][K])
			break;
		// DBG(dp[0][K]);
		assert(m * (K - 1) <= MxX);
		(ans += dp[0][K]) %= mod;
	}
	cout << ans;
	return 0;
}