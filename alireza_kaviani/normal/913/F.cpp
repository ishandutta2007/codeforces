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

const ll MAXN = 2010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll poww(ll a , ll b){
	ll ans = 1;
	for( ; b ; a = a * a % MOD , b >>= 1)	if(b & 1)	ans = ans * a % MOD;
	return ans;
}

ll n , A , B , p , pw[MAXN] , wp[MAXN] , dp[MAXN][MAXN] , E[MAXN];

ll C2(ll n){
	return n * (n - 1) / 2 % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> A >> B;
	p = A * poww(B , MOD - 2) % MOD;
	pw[0] = wp[0] = 1;
	for(int i = 1 ; i < MAXN ; i++){
		pw[i] = pw[i - 1] * p % MOD;
		wp[i] = wp[i - 1] * (MOD + 1 - p) % MOD;
//		cout << pw[i] << sep << wp[i] << endl;
	}
	dp[0][0] = 1;
	for(int i = 1 ; i < MAXN ; i++){
		dp[i][0] = dp[i][i] = 1;
		for(int j = 1 ; j < i ; j++){
			dp[i][j] = (dp[i - 1][j - 1] * pw[i - j] + dp[i - 1][j] * wp[j]) % MOD;
		}
	}
	for(int i = 1 ; i < MAXN ; i++){
		for(int j = 1 ; j < i ; j++){
			dp[i][i] -= dp[i][j];
		}
		dp[i][i] = (dp[i][i] % MOD + MOD) % MOD;
//		cout << i << sep << dp[i][i] << endl;
		for(int j = i + 1 ; j < MAXN ; j++){
			dp[j][i] = (dp[j][i] * dp[i][i]) % MOD;
		}
	}
	E[1] = 0;
	for(int i = 2 ; i < MAXN ; i++){
		for(int j = 1 ; j < i ; j++){
//			cout << i << sep << j << sep << dp[i][j] << endl;
			E[i] = (E[i] + dp[i][j] * (C2(i) - C2(i - j) + E[i - j] + E[j] + MOD)) % MOD;
		}
//		cout << i << sep << E[i] << endl;
//		cout << dp[i][i] << endl;
//		cout << poww(MOD + 1 - dp[i][i] , MOD - 2) << endl;
//		cout << (E[i] + dp[i][i] * C2(i)) << endl;
		E[i] = (E[i] + dp[i][i] * C2(i)) % MOD * poww(MOD + 1 - dp[i][i] , MOD - 2) % MOD;
//		cout << i << sep << E[i] << endl;
	}
	cout << E[n] << endl;

    return 0;
}
/*

*/