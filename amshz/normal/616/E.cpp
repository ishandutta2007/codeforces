# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e7 + 10;
const int xm = 1e6 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll zarb(ll a, ll b){
	return ((a % md) * (b % md) + 10 * md) % md;
}

ll n, m, ans, inv = power(2, md - 2), Kafs[xn];
int cnt;

ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}

ll PS(ll a){
	return zarb(zarb(a, a + 1), inv);
}
ll x_y(ll a, ll b){
	if (b < a) return 0;
	return jaam(PS(b), - PS(a - 1));
}
 
 
 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	
	ans = zarb(n, m);
	m = min(n, m);
	
	for (ll i = 1; i <= sqrt(n); i ++){
		ll x = n / i;
		if (n / x != i) continue;
		Kafs[cnt ++] = i;
		if (x != i) Kafs[cnt ++] = x;
	}
	
	sort(Kafs, Kafs + cnt);
	
	ll last = 0;
	for (int i = cnt - 1; i > -1; i --){
		ll x = Kafs[i];
		ll y = n / x;
		ans = jaam(ans, - zarb(x_y(last + 1, min(y, m)), x));
		last = y;
	}
	
	cout << ans << endl;
	
	
	return 0;
}