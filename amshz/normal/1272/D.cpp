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
 
const ll md = 1e9+7;

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
const int xm = 5e4+10;

int n, a[xn], dp[xn][3];

int main(){
    fast_io;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    dp[0][0] = 1;
    
    for (int i = 1; i < n; i++){
    	dp[i][0] = 1;
    	if (a[i] > a[i-1]) dp[i][0] += dp[i-1][0];
		
		dp[i][1] = dp[i-1][0];
		
		dp[i][2] = 1;
		if (i > 1 && a[i] > a[i-2]) dp[i][2] += dp[i-2][0];
		if (a[i] > a[i-1]) dp[i][2] = max(dp[i][2], 1 + dp[i-1][2]); 
	}
	
	int mx = 0;
	for (int i = 0; i < n; i++) mx = max(mx, max(dp[i][0], max(dp[i][1], dp[i][2])));
    
    cout << mx << endl;
    
    return 0;
}