// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}
ll inv(ll x){ return bin_pow(x, Mod - 2); }
ll f[N], iv[N];

ll nCr(ll n, ll r){
	if(n < 0 || r < 0 || n < r) return 0;
	return mul(f[n], mul(iv[r], iv[n - r]));
}
ll Grp(ll k, ll n){
	if(n < 0) return 0;
	return nCr(n + k - 1, n);
}


int Main(){
	ll n, k;
	cin >> n >> k;
	ll ans = f[n];
	for(int c = 1; c <= n; c++){
		 
		ll ad = mul( Grp(c + 1, n - c - (c - 1ll) * (k - 1)) , mul(f[c], f[n - c]));
		// debug(ad);
		ans = (ans + ad) % Mod;
	}
	// debug(ans);
	cout << mul(ans, iv[n]) << '\n';
	return 0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < N; i++) iv[i] = inv(f[i]);
	int T;
	cin >> T;
	while(T --) Main();

	return 0;
}
/*
1
3 2

*/