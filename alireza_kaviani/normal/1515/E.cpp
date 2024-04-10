#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 400 + 10;
const ll LOG = 22;
const ll INF = 8e18;
//const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , MOD , C[MAXN][MAXN] , dp[MAXN][2][2] , dp2[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> MOD;
	for(int i = 0 ; i < MAXN ; i++){
		C[i][0] = 1;
		for(int j = 1 ; j <= i ; j++){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
	dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = 1;
	dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 1;
	for(int i = 2 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			for(int k = 0 ; k < 2 ; k++){
				for(int l = 0 ; l < 2 ; l++){
					dp[i][k][l] = (dp[i][k][l] + dp[j - 1][k][1] * dp[i - j][1][l] % MOD * C[i - 1][j - 1]) % MOD;
				}
			}
		}
	}
	//dp2[0][0] = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			for(int k = 0 ; k < i - j ; k++){
				dp2[i][j + k] = (dp2[i][j + k] + dp2[i - j - 1][k] * dp[j][0][0] % MOD * C[j + k][j]) % MOD;
			}
			if(i == j)	dp2[i][j] = dp[i][0][0];
			//cout << i << sep << j << sep << dp2[i][j] << endl;
		}
	}
	ll ans = 0;
	for(int i = 0 ; i < MAXN ; i++)	ans = (ans + dp2[n][i]) % MOD;
	cout << ans << endl;

    return 0;
}
/*

*/