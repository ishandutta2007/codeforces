#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const int MAXN = 3e3 + 10;
const ll INF = 8e18;
const int MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int dp[MAXN][MAXN], dp2[MAXN][MAXN], n, m;
char A[MAXN][MAXN], C[MAXN];

void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}


void mkey(int& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

ll mkey2(ll a) {
	mkey(a);
	return a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", C + 1);
		for (int j = 1; j <= m; j++) A[i][j] = C[j];
	}
	if (A[2][1] == '#' || A[1][2] == '#' || A[n][m - 1] == '#' || A[n - 1][m] == '#') return cout << 0 << endl, 0;
	dp[1][2] = dp2[2][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i + j < 4 || A[i][j] == '#') continue;
			mkey(dp[i][j] = dp[i][j - 1] + dp[i - 1][j]);
			mkey(dp2[i][j] = dp2[i][j - 1] + dp2[i - 1][j]);
		}
	}

	printf("%lld \n", mkey2(ll(dp[n - 1][m]) * ll(dp2[n][m - 1]) % MOD - ll(dp2[n - 1][m]) * ll(dp[n][m - 1]) % MOD));
	return 0;
}