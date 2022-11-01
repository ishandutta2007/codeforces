# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 5e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll zarb(ll a, ll b){
	return (a * b + 10 * md) % md;
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}

ll n, s, a[xn], c[xn], b[xn];


bool check(ll t){
	for (ll i = 0; i  < n; i++) b[i] = (i + 1) * t + a[i];
	sort(b, b + n);
	for (int i = 0; i < t; i ++) c[t] += b[i];
	return c[t] <= s;
}

 
int main(){
	fast_io;
	
	cin >> n >> s;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	ll l = 0, r = n + 1, mid;
	while (r - l > 1){
		mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	
	cout << l << sep << c[l] << endl;
	
	return 0;
}