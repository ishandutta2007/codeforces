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
 
const ll md = 1e9+7;
const int xn = 1e6 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 
int n, last;
ll a[xn], Sum, dp[xn][2], b[xn], ans = inf, mn;
bool p[xn];
vector <ll> Primes;
vector <pii> vec;
 
 
void Solve(int l, int r, ll k){
	ll s = 0;
	for (int i = l; i <= r; i ++) {
		s += a[i];
		b[i] = s % k;
	}
	for (int i = l + 1; i <= r; i ++){
		dp[i][0] = dp[i - 1][0] + b[i - 1];
		dp[i][0] = min(dp[i][0], dp[i - 1][0] + (k - b[i - 1]) % k);
	}
	s = 0;
	for (int i = r; i >= l; i --){
		s += a[i];
		b[i] = s % k;
	} 
	for (int i = r - 1; i >= l; i --){
		dp[i][1] = dp[i + 1][1] + b[i + 1];
		dp[i][1] = min(dp[i][1], dp[i + 1][1] + (k - b[i + 1]) % k);
	}
	mn = inf;
	for (int i = l; i <= r; i ++)
		mn = min(mn, dp[i][0] + dp[i][1]);
	Sum += mn;
}
 
 
 
int main(){
	fast_io;
	
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i], Sum += a[i];
	
	if (Sum == 1){
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 2; i <= 1e6; i ++){
		if (p[i]) continue;
		if (Sum % i == 0){
			while (Sum % i == 0) Sum /= i;
			Primes.push_back(i);
		}
		for (int j = i + i; j <= 1e6; j += i) p[j] = true;
	}
	
	if (Sum > 1) Primes.push_back(Sum);
 
	
	for (ll k : Primes){
		vec.clear();
		Sum = 0;
		last = 0;
		for (int i = 0; i < n; i ++){
			Sum += a[i];
			if (Sum % k == 0){
				vec.push_back({last, i});
				last = i + 1;
				Sum = 0;
			}
		}
		memset(dp, 0, sizeof dp);
		Sum = 0;
		for (int i = 0; i < vec.size(); i ++) Solve(vec[i].F, vec[i].S, k);
		ans = min(ans, Sum);
	}
	
	
	cout << ans << endl;
	
	
	return 0;
}