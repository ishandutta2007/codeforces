#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int			    ll

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN], n, k, q, A[MAXN], tot[MAXN];

inline void mkey(ll& x) {
	if (x < 0) x += MOD * MOD;
	x %= MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) dp[i][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j > 1) mkey(dp[j][i] += dp[j - 1][i - 1]);
			if (j < n) mkey(dp[j][i] += dp[j + 1][i - 1]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			mkey(tot[i] += dp[i][j] * dp[i][k - j]);
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		mkey(ans += A[i] * tot[i] % MOD);
	while (q--) {
		int i, x;
		cin >> i >> x;
		mkey(ans -= tot[i] * A[i] % MOD);
		A[i] = x;
		mkey(ans += tot[i] * A[i] % MOD);
		cout << ans % MOD << endl;
	}
	return 0;
}