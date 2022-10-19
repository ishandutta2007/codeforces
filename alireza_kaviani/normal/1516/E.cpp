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

const ll MAXN = 500 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll poww(ll x , ll y){
	ll ans = 1;
	for( ; y ; y >>= 1 , x = x * x % MOD)	if(y & 1)	ans = ans * x % MOD;
	return ans;
}

int n , k , C[MAXN][MAXN] , dp[MAXN][MAXN] , ans[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 0 ; i < MAXN ; i++){
		C[i][0] = 1;
		for(int j = 1 ; j <= i;  j++){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
	dp[0][0] = 1;
	for(int i = 1 ; i < MAXN ; i++){
		for(int j = i * 2 ; j < MAXN ; j++){
			ll fact = 1;
			for(int k = 2 ; k <= j ; k++){
				fact = fact * (k - 1) % MOD;
				dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j - k] * C[j - 1][k - 1] % MOD * fact) % MOD;
			}
		}
	}
	cin >> n >> k;
	ans[0] = 1;
	/*for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++){
			cout << i << sep << j << sep << dp[j][i] << endl;
		}
	}*/
	for(int i = 1 ; i <= k ; i++){
		ll c = 1;
		for(int j = 1 ; j < MAXN && j <= n ; j++){
			c = c * (n - j + 1) % MOD * poww(j , MOD - 2) % MOD;
			if(j >= i)	ans[i] = (ans[i] + c * dp[j - i][j]) % MOD;
//			cout << j << sep << c << sep << ans[i] << endl;
		}
		if(i >= 2)	ans[i] = (ans[i] + ans[i - 2]) % MOD;
		cout << ans[i] << sep;
	}

    return 0;
}
/*

*/