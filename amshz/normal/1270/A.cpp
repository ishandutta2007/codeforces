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

int a[xn], b[xn], k, n, m;


int main(){
    fast_io;
    
    int qq;
    cin >> qq;
    while (qq--){
    	cin >> k >> n >> m;
    	for (int i=0; i<n; i++) cin >> a[i];
    	for (int i=0; i<m; i++) cin >> b[i];
    	
    	int mx = 0;
    	for (int i=0; i<n; i++) mx = max(mx, a[i]);
    	for (int i=0; i<m; i++) mx = max(mx, b[i]);
    	
    	bool fl1 = true;
    	for (int i=0; i<m; i++) if (b[i] == mx) fl1 = false;
    	
    	if (fl1) cout << "YES" << endl;
    	else cout << "NO" << endl;
	}
    
    return 0;
}