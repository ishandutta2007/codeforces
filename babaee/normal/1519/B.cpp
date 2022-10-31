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

const ll MAXN = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, dp[MAXN][MAXN], dp2[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++) {
		for (int j = 1; j < MAXN; j++) {
			if (i + j == 2) continue;
			dp2[i][j] = INF;
			if (i > 1) dp[i][j] = dp[i - 1][j] + j, dp2[i][j] = dp2[i - 1][j] + j;
			if (j > 1) dp[i][j] = max(dp[i][j], dp[i][j - 1] + i), dp2[i][j] = min(dp2[i][j], dp2[i][j - 1] + i);
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int x, y, k;
		cin >> x >> y >> k;
		if (k > dp[x][y] || k < dp2[x][y]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}