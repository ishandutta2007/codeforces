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
ll a[N];
ll f[N], iv[N];

ll nCr(ll n, ll r){
	if((r < 0) || (n < r)) return 0;
	return mul(f[n], mul(iv[r], iv[n - r]));
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < N; i++) iv[i] = bin_pow(f[i], Mod - 2);
	ll n, m, g;
	cin >> n >> m >> g;
	if(m == 0){
		return cout << (1 - (n & 1) == g ? 1 : 0), 0;
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++){
		if(n + m == i + 1){
			if(1-(i&1) == g) ans ++;
		}
		else{
		if((i&1) == g) ans += nCr(n + m - i - 1, n - i);
		}
	}
	cout << ans%Mod << '\n';
	return 0;
}