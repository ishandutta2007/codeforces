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
 
const int xn = 3e5+10;
const int xm = 5e4+10;

ll n, md, ans, fact[xn];


int main(){
    fast_io;
    
    cin >> n >> md;
    
    fact[1] = 1, fact[0] = 1;
    for (ll i = 2; i <= n; i++) fact[i] = fact[i-1]*i, fact[i] %= md;
    
    for (ll x = 0; x <= n-1; x++){
    	ll s = 1;
    	s *= n-x, s %= md;
    	s *= n-x, s %= md;
    	s *= fact[x+1], s %= md;
    	s *= fact[n-x-1], s %= md;
    	
    	ans += s;
    	ans %= md;
	}
	
	cout << ans << endl;
    
    return 0;
}