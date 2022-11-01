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
 
const int xn = 2e3+10;
const int xm = 5e4+10;



int main(){
    //fast_io;
    
    ll n, m;
    cin >> n >> m;
    
    ll ans = 0;
    
    for (int i=1; i<=n; i++){
    	//cout << i << endl;
    	ll s = (i%5);
    	
    	s = 5-s;
    	s = s%5;
    	
    	ll m2 = m;
    	if (m2 < s) continue;
    	while (m2%5 != s) m2--;
    	
    	ll j = s;
    	if (j == 0) j = 5;
    	
    	ans += (m2-j+s)/5+1;
    	
    	//cout << ans << endl;
	}
    cout << ans << endl;
    return 0;
}