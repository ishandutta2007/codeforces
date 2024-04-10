#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, C[MAXN], A[MAXN], B[MAXN], U[MAXN], dp[MAXN];

inline int solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> C[i];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	for (int i = 1; i < n; i++) U[i] = abs(A[i] - B[i]);
	dp[0] = 0;
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = U[i] + C[i] + 1;	
		if (U[i] > 0) dp[i] = max(dp[i], dp[i - 1] - U[i] + C[i] + 1);
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}