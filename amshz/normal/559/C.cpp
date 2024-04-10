# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 2e3+10;

ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

pii G[xn];
ll dp[xm], fac[xn], inv[xn];

ll ent(ll n, ll k){
	if (n < k || n < 0 || k < 0) return 0;
	ll a = fac[n], b = inv[k], c = inv[n-k];
	a *= b, a = (a + md) % md;
	a *= c, a = (a + md) % md;
	return a;
}


bool cmp(pii i, pii j){
	return i.F + i.S < j.F + j.S;
}

 
int main(){
	fast_io;
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 2e5; i++){
		fac[i] = i * fac[i-1];
		fac[i] = (fac[i] + 100 * md) % md;
		inv[i] = power(fac[i], md - 2);
	}
	
	ll h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++) cin >> G[i].F >> G[i].S;
	G[n].F = h, G[n].S = w;
	sort(G, G+n+1, cmp);
	
	for (int i = 0; i <= n; i++){
		ll x = G[i].F, y = G[i].S;
		dp[i] = ent(x+y-2, x-1);
		for (int j = 0; j < i; j++){
			ll x2 = G[j].F, y2 = G[j].S;
			if (x2 + y2 == x + y) continue;
			ll bad = dp[j];
			bad *= ent(x + y - x2 - y2, x - x2);
			bad = (bad + md * 100) % md;
			dp[i] -= bad;
			dp[i] = (dp[i] + md * 100) % md;
		}
	}
	
	cout << dp[n] << endl;
	
	
	return 0;
}