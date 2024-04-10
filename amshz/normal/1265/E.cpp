# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
# define endl         '\n'
# define sep         ' '
# define F              first
# define S              second
# define pb             push_back
# define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll md = 998244353;

ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}
ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
 
const int xn = 2e5+10;
const int xm = 3e1+10;

ll n, p[xn], dp[xn][2], inv;


int main(){
    fast_io;
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    inv = power(ll(100), md - 2, md);
    
    dp[0][0] = 1, dp[0][1] = 0;
    
    for (int i = 1; i <= n; i++){
    	dp[i][0] = (dp[i-1][0] * p[i] + md) % md;
    	dp[i][0] = (dp[i][0] * inv + md) % md;
    	dp[i][1] = (dp[i-1][0] * (100-p[i]) + md) % md;
    	dp[i][1] = (dp[i][1] * inv + md) % md;
    	
    	//cout << dp[i][0] << sep << dp[i][1] << endl;
	}
	
	inv = power(dp[n][0], md - 2, md);
	
	
	ll ans = 0;
	for (ll i = 1; i <= n; i++){
		ans += (inv * ((i*dp[i][1]) % md)) % md + md, ans %= md;
		if (i == n) ans += (i + md) % md, ans %= md;
	}
	ans = (ans + md) % md;
	
	cout << ans << endl;

    return 0;
}