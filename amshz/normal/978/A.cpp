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

int n, a[xn];
map <int, int> mp;

int main(){
    fast_io;
    
    vector <int> b;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = n-1; i >= 0; i--){
    	if (mp[a[i]]) continue;
    	mp[a[i]] = 1;
    	b.pb(a[i]);
	}
	
	cout << b.size() << endl;
	for (int i = b.size()-1; i >= 0; i--) cout << b[i] << sep;
	cout << endl;
    
    
    return 0;
}