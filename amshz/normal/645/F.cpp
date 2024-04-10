# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e6 + 10;
const int xm = 1e6 + 10;
const int SQ = 500;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b){return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
 

int n, m;
ll ans, s[xn], cnt[xn], fact[xn], zarib[xn], inv[xn], k, a[xn];
vector <int> adj[xn];


ll C(ll n, ll r){
	if (r > n || r < 0) return 0;
	return zarb(fact[n], zarb(inv[r], inv[n - r]));
}

 
int main(){
	fast_io;
	
	cin >> n >> k >> m;
	for (int i = 0; i < n + m; i ++) cin >> a[i];
	
	fact[0] = inv[0] = 1LL;
	for (ll i = 1; i <= 1e6; i ++){
		fact[i] = zarb(fact[i - 1], i);
		inv[i] = power(fact[i], md - 2);
	}
	
	
	for (int i = 1; i <= 1e6; i ++) zarib[i] = i;
	for (int i = 1; i <= 1e6; i ++){
		adj[i].push_back(i);
		for (int j = i + i; j <= 1e6; j += i){
			zarib[j] -= zarib[i];
			adj[j].push_back(i);
		}
	}
	
	for (int i = 0; i < n + m; i ++){
		for (int x : adj[a[i]]) {
			ans = jaam(ans, - zarb(C(cnt[x], k), zarib[x]));
			cnt[x] ++;
			ans = jaam(ans, zarb(C(cnt[x], k), zarib[x]));
		}
		if (i >= n) cout << ans << endl;
	}
	
	
	return 0;
}