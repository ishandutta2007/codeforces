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

const ll MAXN = 14;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll poww(ll x , ll y){
	ll ans = 1;
	for( ; y ; y >>= 1 , x = x * x % MOD)	if(y & 1)	ans = ans * x % MOD;
	return ans;
}

ll n , ans , A[MAXN] , win[MAXN][MAXN] , inv[MAXN][MAXN] , dp[1 << MAXN] , dp2[1 << MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			win[i][j] = A[i] * poww(A[i] + A[j] , MOD - 2) % MOD;
			inv[i][j] = poww(win[i][j] , MOD - 2);
//			cout << i << sep << j << sep << win[i][j] << sep << inv[i][j] << endl;
		}
	}
	dp[0] = dp2[0] = 1;
	vector<int> vec;
	for(int i = 1 ; i < (1 << n) ; i++){
		dp[i] = 1; vec.clear();
		for(int j = i ; j > 0 ; j = (j - 1) & i){
			vec.push_back(j);
		}
		reverse(all(vec));
		for(int j : vec){
			dp2[j] = dp2[j - (j & -j)];
			int x = __builtin_ctz(j);
			for(int k = 0 ; k < n ; k++){
				if(x == k)	continue;
				if(i & (1 << k)){
					if(j & (1 << k)){
//						cout << 1 << sep << i << sep << j << sep << x << endl;
						dp2[j] = dp2[j] * inv[k][x] % MOD;
					}
					else{
//						cout << 2 << sep << i << sep << j << sep << x << endl;
						dp2[j] = dp2[j] * win[x][k] % MOD;
					}
				}
			}
			if(i == j)	continue;
			dp[i] = (dp[i] + MOD - dp[j] * dp2[j] % MOD) % MOD;
//			cout << i << sep << j << sep << x << sep << dp2[j] << endl;
		}
		if(i != (1 << n) - 1)	continue;
		for(int j = 1 ; j < (1 << n) ; j++){
			ans = (ans + dp[j] * dp2[j] % MOD * __builtin_popcount(j)) % MOD;
		}
//		cout << i << sep << dp[i] << endl;
	}
	cout << ans << endl;

    return 0;
}
/*

*/