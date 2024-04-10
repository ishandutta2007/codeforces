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
 
const ll md = 998244353;
const int xn = 5e3 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, m, k, dp[xn][xn], ans, inv, C[xn], invi[xn];
 
int main(){
	fast_io;
	
	cin >> n >> m >> k;
	inv = power(power(m, n), md - 2);
	dp[1][1] = 1LL;
	for (ll i = 2; i <= k; i ++)
		for (ll j = 1; j <= k; j ++)
			dp[i][j] = zarb(j, jaam(dp[i - 1][j - 1], dp[i - 1][j]));
	C[0] = 1LL;
	for (ll i = 1; i <= k; i ++) C[i] = zarb(C[i - 1], zarb(n - i + 1, power(i, md - 2)));
	for (ll i = 1; i <= k; i ++)
		if (i <= n) ans = jaam(ans, zarb(C[i], zarb(power(m, n - i), dp[k][i])));
	ans = zarb(ans, inv);
	cout << ans << endl;
	return 0;
}