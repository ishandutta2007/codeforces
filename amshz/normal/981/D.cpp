# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e18;
const int xn = 5e1 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
//ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
//ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, k, a[xn], sum = 0;
bool dp[xn][xn];

bool check(ll x){
	if (!x) return true;
	memset(dp, false, sizeof dp);
	dp[0][0] = true;
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= k; j ++){
			sum = 0;
			for (int p = i; p >= 1; p --){
				sum += a[p];
				if ((sum&x) == x && dp[p - 1][j - 1]) dp[i][j] = true;
			}
		}
	}
	return dp[n][k];
}

int main(){
	fast_io;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	ll L = 0, R = (1LL << 60LL), Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (check(Mid)) L = Mid;
		else R = Mid;
	}
	cout << L << endl;
	
	return 0;
}