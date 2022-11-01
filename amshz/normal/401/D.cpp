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
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e2 + 10;
const int xm = 6e5 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, dp[xm][xn], m, num[xn], fact[xn], cnt[xn], ans;
string a;


int main(){
	//InTheNameOfGod;
	
	cin >> a >> m;
	n = ll(a.size());
	for (int i = 0; i < n; ++ i) num[i] = (a[i] - '0'), ++ cnt[num[i]];
	for (int i = 0; i < n; ++ i)
		if (num[i]) dp[1 << i][num[i] % m] = 1LL;
	for (int mask = 1; mask < 1LL << n; ++ mask)
		for (int i = 0; i < n; ++ i)
			if (!(mask&(1 << i)))
				for (int j = 0; j < m; ++ j)
					dp[mask + (1 << i)][(j * 10LL + num[i]) % m] += dp[mask][j];
	ans = dp[(1LL << n) - 1LL][0LL];
	fact[0] = 1;
	for (int i = 1; i <= 18; ++ i) fact[i] = fact[i - 1] * i;
	for (int i = 0; i < 10; ++ i) ans /= fact[cnt[i]];
	cout << ans << endl;

	return 0;
}