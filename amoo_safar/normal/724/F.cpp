// har ki ro didi goft mikhad beshe meslemon !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const int N = 1e3 + 10;
const int D = 11;

int mod;

ll mul(ll a, ll b){
	return (a * b) % mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}

ll inv(ll x){
	return bin_pow(x, mod - 2);
}

ll nCr(ll n, ll r){
	ll res = 1;
	for(int i = 0; i < r; i++){
		res = mul(res, mul(n - i, inv(i + 1)));
	}
	return res;
}

ll dp[N][N][D];
ll ct[N][D];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, d;
	cin >> n >> d >> mod;

	if(n <= 2)
		return cout << "1\n", 0;
	fill(ct[1], ct[1] + D, 1);
	for(int i = 0; i < N; i++) dp[1][i][0] = 1;
	// dp[1][i][0] = 1;
	// debug(nCr(6, 3));
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 0; k <= d; k++){
				dp[i][j][k] = dp[i][j - 1][k];
				for(int cnt = 1; cnt <= k && cnt * j < i; cnt ++){
					dp[i][j][k] += dp[i - cnt * j][j - 1][k - cnt] * ct[j][cnt];
					dp[i][j][k] %= mod;
				}
				// debug(dp[i][j][k]);
				// cerr << i << ' ' << j << ' ' << k << " -> " << dp[i][j][k] << '\n';
			}
		}
		ct[i][0] = 1;
		ct[i][1] = dp[i][i - 1][d - 1];
		// debug(ct[i][1]);
		for(int j = 2; j <= d; j++){
			ct[i][j] = nCr(ct[i][1] + j - 1, j);
		}
	}
	// debug(ct[3][1]);
	// debug(dp[2][2][1]);
	ll ans = dp[n][(n - 1) / 2][d];
	if(n % 2 == 0){
		ll x = dp[n / 2][(n/2)-1][d - 1];
		ans += x;
		ans += mul(mul(x, x - 1), inv(2));
	}
	cout << ans % mod << '\n'; 
	return 0;
}