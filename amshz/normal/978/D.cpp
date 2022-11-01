# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
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

ll n, a[xn];

ll fn1(ll d, ll st){
	ll ans = 0;
	for (int i = 2; i < n; i++){
		if (a[i] != (i)*d+st && abs(a[i]-(i*d+st)) <= 1) ans++;
		if (abs(a[i]-(i*d+st)) > 1) return 1e18;
	}
	return ans;
}

int main(){
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (n <= 2){
    	cout << 0 << endl;
    	return 0;
	}
    
    ll ans = 1e18;
    
    for (ll i = -1; i < 2; i++){
    	for (ll j = -1; j < 2; j++){
    		ll s = 0;
    		if (i != 0) s++;
    		if (j != 0) s++;
    		
    		ans = min(ans, s + fn1(a[1]+j-a[0]-i, a[0]+i));
    		
    		//cout << i << sep << j << sep << fn1(a[1]+j-a[0]-i, a[0]+i) << endl;
		}
	}
	if (ans >= 1e18){
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
    
    
    return 0;
}