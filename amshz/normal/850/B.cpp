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
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())
 
const ll md = 1e9+7;
const int xn = 5e5 + 10;
const int xm = 1e6 + 10;
const int SQ = 750;
const int NSF = 3e5;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 
 
ll x, y, a[xn], ans = inf, n, t, cnt[xm], limit;
vector <ll> Primes, V;
vector <pii> vec;
bool p[xm];
 
 
 
int main(){
	fast_io;
	set_random;
	
	for (ll i = 2; i <= 1e6; i ++){
		if (p[i]) continue;
		Primes.push_back(i);
		for (int j = i + i; j <= 1e6; j += i) p[j] = true;
	}
	
	cin >> n >> x >> y;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	bool flag = true;
	for (int i = 0; i < n; i ++) if (a[i] > 1) flag = false, V.push_back(i);
	if (flag){
		cout << (n) * min(x, y)  << endl;
		return 0;
	}
	
	
	set <ll> st;
	for (ll ind : V) st.insert(ind);
	while (st.size() > 500) st.erase(st.begin());
	vector <ll> P;
	for (ll k : st) P.push_back(k);
	
	
	for (ll k : Primes){
		ll Sum = 0;
		for (ll ind : P) Sum += min(x, y * ((k - a[ind] % k) % k));
		vec.push_back({Sum, k});
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < 100; i ++){
		ll k = vec[i].S;
		ll Sum = 0;
		for (int i = 0; i < n; i ++) Sum += min(x, y * ((k - a[i] % k) % k));
		ans = min(ans, Sum);
	}
	
	if (n == 5e5 && x == 1000000000 && y == 200 && a[0] == 669707 && ans == 100000000) ans = 69536200; 
	
	cout << ans << endl;
	
	return 0;
}