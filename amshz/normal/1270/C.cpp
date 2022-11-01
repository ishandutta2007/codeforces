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

ll n, k, a[xn];

ll fn1(ll g){
	ll f = 0;
	while (g > 0) f++, g /= 2;
	
	return f;
}

int main(){
    fast_io;
    
    int qq;
    cin >> qq;
    while (qq--){
    	
    	cin >> n;
    	for (int i=0; i<n; i++) cin >> a[i];
    	
    	ll x = 0, s = 0;
    	for (int i=0; i<n; i++) s += a[i], x = x^a[i];
    	
    	ll g = fn1(s);
    	
    	ll f = 1;
    	for (int i=0; i<g; i++) f *= 2;
    	
    	f *= 4;
    	
    	
    	if (s%2) f++;
    	cout << 3 << endl;
    	cout << f << sep;
    	
    	x = x^f;
    	s += f;
    	
    	ll d = x*2-s;
    	d /= 2;
    	
    	cout << d << sep << d << endl;
    	
    	x = x^d;
    	x = x^d;
    	s += d+d;
    	
    	//cout << "wxg : " << x << sep << s << endl;
	}
    
    return 0;
}