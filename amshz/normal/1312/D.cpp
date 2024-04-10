# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 3e5+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll zarb(ll a, ll b){
	return (a * b + 10 * md) % md;
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}

ll n, m, fact[xn], ans, inv[xn];

ll C(ll a, ll b){
	if (b > a || a < 0) return 0;
	
	return zarb(fact[a], zarb(inv[b], inv[a - b]));
}




int main(){
	fast_io;
	
	cin >> n >> m;
	
	fact[0] = 1LL;
	inv[0] = 1LL;
	for (ll i = 1; i <= 2e5; i ++) {
		fact[i] = zarb(i, fact[i - 1]);
		inv[i] = power(fact[i], md - 2);
	}
	
	for (ll i = 2; i < n; i ++){
		ll s = C(m, n - 1);
		s = zarb(s, n - 2);
		
		ll t = C(n - 3, i - 2);
		s = zarb(s, t);
		ans = jaam(ans, s);
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}