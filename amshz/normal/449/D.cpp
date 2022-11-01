# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <pii, pii> pip;
 
# define A 					first
# define B 					second
# define endl 				'\n'
# define sep 				' '
# define all(x) 			x.begin(), x.end()
# define kill(x)         	return cout << x << endl, 0
# define InTheNameOfGod 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = (1 << 20) + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;

ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, num[xn], dp[xn], ans, cnt[xn];


int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n; ++ i) cin >> num[i], ++ dp[num[i]];
	for (int j = 0; j < 20; ++ j)
		for (int mask = 0; mask < (1 << 20); ++ mask)
			if (!(mask&(1 << j)))	dp[mask] += dp[mask + (1 << j)];
	ans = power(2, n);
	for (int mask = 1; mask < (1 << 20); ++ mask){
		int ted = __builtin_popcount(mask);
		if (ted % 2) ans = (ans - power(2, dp[mask]) + md) % md;
		else ans = (ans + power(2, dp[mask]) + md) % md;
	}
	cout << ans << endl;
	return 0;
}