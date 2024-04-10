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

ll n, m, a[xn];

int main(){
    fast_io;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll s = 0, mn = 1e18, mx = -1e18;
    
    for (int i = 0; i < n; i++){
    	s += a[i];
    	mn = min(mn, s);
    	mx = max(mx, s);
	}
	
	ll l = max(ll(0), -mn);
	ll r = min(m, m - mx);
	
	cout << max(ll(0), r-l+1) << endl;
    
    
    return 0;
}