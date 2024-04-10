# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 50 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int qq;
ll d, m, dp[xn], ans;

int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		cin >> d >> m;
		memset(dp, 0, sizeof dp);
		dp[0] = 1LL;
		ans = 0;
		for (ll i = 1; i <= 30; i ++){
			if (d < (1LL << i)) break;
			ll s = (1LL << (i));
			if (d < (1LL << (i + 1))) s = d - (1LL << i) + 1;
			for (ll j = 0; j < i; j ++){
				dp[i] += (dp[j] * s) % m;
				dp[i] %= m;
			}
			dp[i] = (dp[i] + s) % m;
		}
		for (ll i = 0; i <= 30; i ++) ans = (ans + dp[i]) % m; 
		cout << ans << endl;
	}
	
	return 0;
}