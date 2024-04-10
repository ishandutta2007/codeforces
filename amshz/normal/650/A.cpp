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
const ll jam = 2e9+1;

int n;
pii a[xn];
ll ans;
map <ll, ll> tab, cnt;
map <pii, ll> mp;

int main(){
    fast_io;
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i].F >> a[i].S;
    
    vector <ll> vec;
    for (int i=0; i<n; i++) vec.pb(a[i].F), vec.pb(a[i].S+jam), mp[{a[i].F, a[i].S}]++;
    
    sort(vec.begin(), vec.end());
    
    ll s = 0;
    for (int i=0; i<2*n; i++){
    	if (i == 0 || vec[i] != vec[i-1]) tab[vec[i]] = s++;
    	//cout << vec[i] << sep;
	}
	//cout << endl;
	
	for (int i=0; i<n; i++){
		if (mp[a[i]] > 1){
			//cout << mp[{a[i].F, a[i].S}] << endl;
			ans -= mp[{a[i].F, a[i].S}]*(mp[{a[i].F, a[i].S}]-1)/2;
			mp[{a[i].F, a[i].S}] = 0;
		}
		//cout << tab[a[i].F] << sep << tab[a[i].S+jam] << endl;
		cnt[tab[a[i].F]]++, cnt[tab[a[i].S+jam]]++;
	}
	for (int i=0; i<=5e5; i++){
		if (cnt[i] == 0) continue;
		ans += cnt[i]*(cnt[i]-1)/2;
	}
	
	cout << ans << endl;
    
    return 0;
}