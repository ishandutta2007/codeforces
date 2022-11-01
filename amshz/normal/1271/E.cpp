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
 
const ll md = 1e18+7;

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
 
const int xn = 5e5+10;
const int xm = 3e1+10;

ll n, k;

ll tab(string a){
	ll s = 0;
	for (int i = 0; i < a.size(); i++){
		s *= 2;
		if (a[i] == '1') s++;
	}
	return s;
}
string bin(ll inp){
	string a = "";
	while (inp){
		if (inp%2) a = '1' + a;
		else a = '0' + a;
		inp /= 2;
	}
	return a;
}
ll path(ll g){
	if (g > n) return 0;
	
	ll ans = 0;
	
	str a = bin(n);
	str b = bin(g);
	
	ll t = a.size() - b.size();
	
	//if (g == 5) cout << a << endl << b << endl;
	
	ans += power(ll(2), t, md) - 1;
	
	str c = "";
	for (int i = 0; i < b.size(); i++) c += a[i];
	
	ll x = tab(c);
	
	if (g > x) return ans;
	
	if (g < x){
		ans += power(ll(2), t, md);
		return ans;
	}
	
	c = "";
	for (int i = b.size(); i < a.size(); i++) c += a[i];
	
	ans += tab(c) + 1;
	
	return ans;
}

bool check(ll x){
	ll ans = 0;
	ans += path(x);
	if (x%2 == 0) ans += path(x+1);
	return ans >= k;
}


int main(){
    fast_io;
    
    cin >> n >> k;
    
    //cout << path(5) << endl;
    
    
    ll l = 0, r = (n+1)/2+1, mid;
    
    while (r - l > 1){
    	mid = (l + r) / 2;
    	if (check(2*mid)) l = mid;
    	else r = mid;
	}
	
	ll mx = l*2;
	
	l = 0, r = (n+2)/2; mid;
	
	while (r - l > 1){
		mid = (l + r) / 2;
		if (check(2*mid+1)) l = mid;
		else r = mid;
	}
	
	mx = max(mx, l*2+1);
	
	cout << mx << endl;
    
    return 0;
}