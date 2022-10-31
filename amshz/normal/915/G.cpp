# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e6 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}
ll menha(ll a, ll b){
	return (a - b + 10 * md) % md;
}


ll n, k, dp[xn], ans;
 
 
int main(){
	fast_io;
	
	cin >> n >> k;
	
	for (ll i = 1; i <= k; i ++)
		dp[i] = menha(power(i, n), power(i - 1, n));
	
	for (int i = 1; i <= k; i ++)
		for (int j = i + i; j <= k; j += i)
			dp[j] = menha(dp[j], dp[i]);
		
	for (int i = 1; i <= k; i ++) dp[i] = jaam(dp[i], dp[i - 1]);
	for (int i = 1; i <= k; i ++) ans = jaam(ans, dp[i] ^ i);
	
	cout << ans << endl;
	
	
	return 0;
}