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
const int sq = 1000;

ll n, a[xn];
vector <ll> b[xn];

ll fn2(ll dx, ll x){
	int l = -1, r = b[dx].size(), mid;
	
	while (r-l > 1){
		mid = (l+r)/2;
		if (mid == -1 || b[dx][mid] < x) l = mid;
		else r = mid;
	}
	
	return sq-r;
}

ll fn1(int l, int r, int x){
	ll ans = 0;
	
	for (int i = l; i <= r;){
		if (i >= n) break;
		
		if (i%sq == 0 && i+sq <= r+1){
			ans += fn2(i/sq, x);
			i += sq;
		}
		else{
			if (a[i] >= x) ans++;
			i++;
		}
	}
	
	return ans;
}

int main(){
    fast_io;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) b[i/sq].pb(a[i]);
    
	for (ll i = 0; i < xn; i++) sort(b[i].begin(), b[i].end());
	
	ll ans = 0;
	
	for (int i = 0; i < n; i++){
		ans += fn1(i+1, a[i]-1, i+1);
	}
	
	cout << ans << endl;
    
    
    return 0;
}