#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , ans , H[MAXN] , dp[MAXN][3];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> H[i]; H[i]--;
	}
	for(int i = 1 ; i <= n ; i++){
		dp[i][0] = min(H[i] , H[i + 1]);
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) * min({H[i - 1], H[i], H[i + 1]}) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) * min(H[i - 1] , H[i]) % MOD;
		ans += dp[i][2] + H[i];
	}
	cout << ans % MOD << endl;

    return 0;
}
/*

*/