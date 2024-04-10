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
    fast_io;
    
    int qq;
    cin >> qq;
    while (qq--){
    	ll a, b, c;
    	cin >> a >> b >> c;
    	
    	ll mn = 1e9+10;
    	if (a < mn) mn = a;
    	if (b < mn) mn = b;
    	if (c < mn) mn = c;
    	
    	ll mx = -1;
    	if (a > mx) mx = a;
    	if (b > mx) mx = b;
    	if (c > mx) mx = c;
    	
    	ll m = a+b+c-mn-mx;
    	
    	if (mn + m < mx -1 ){
    		cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
	}
    
    return 0;
}