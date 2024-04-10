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
const int xn = 2e6 + 10;
const int xm = 2e5 + 10;
const int SQ = 500;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}
ll zarb(ll a, ll b){
	return (a * b + 10 * md) % md;
}

ll qq, ans, fact[xn], inv[xn];
bool p[xn];
vector <ll> adj[xn];


ll C(ll k, ll n){
	if (k > n || k < 0) return 0;
	return zarb(fact[n], zarb(inv[k], inv[n - k]));
}


void Solve(ll r, ll k){
	ans = jaam(ans, jaam(C(r, r + k), C(r, r + k - 1)));
}



 
 
int main(){
	fast_io;
	
	fact[0] = inv[0] = 1LL;
	for (ll i = 1; i <= 2e6; i ++){
		fact[i] = zarb(fact[i - 1], i);
		inv[i] = power(fact[i], md - 2);
	}
	
	cin >> qq;
	
	for (ll i = 2; i <= 1e6; i ++){
		if (p[i]) continue;
		adj[i].push_back(i);
		for (ll j = i + i; j <= 1e6; j += i) adj[j].push_back(i), p[j] = true;
	}
	                                                                                                                                                                                    
	while (qq --){
		ll n, r;
		cin >> r >> n;
		ll s = 1LL;
		for (ll x : adj[n]){
			ll k = 0, m = n;
			while (m % x == 0) m /= x, k ++;
			ans = 0;
			Solve(r, k);
			s = zarb(ans, s);
 		}
 		cout << s << endl;
	}
	
	return 0;
}