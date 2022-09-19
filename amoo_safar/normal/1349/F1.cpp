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

const ll Mod = 998244353;
const int N = 5e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll mul(ll a, ll b){
	return (a*b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j) res = mul(res, pw);
	return res;
}
ll dp[N][N], f[N], iv[N];


ll nCr(ll n, ll r){
	if(n < 0 || n < r) return 0;
	return mul(f[n], mul(iv[r], iv[n - r]));
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < N; i++) iv[i] = bin_pow(f[i], Mod - 2);
	
	dp[1][1] = 1;
	for(int i = 1; i + 1 < N; i++){
		for(int j = 1; j <= i; j++){
			dp[i][j] %= Mod;
			dp[i + 1][j] += mul(dp[i][j], j);
			dp[i + 1][j + 1] += mul(dp[i][j], i + 1 - j);
		}
	}
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		ll ans = 0;
		for(int j = 1; j <= n; j++){
			dp[j][i] %= Mod;
			ans += mul(dp[j][i], mul(nCr(n, j), f[n-j]));
			ans %= Mod;
		}
		cout << ans << ' ';
	}
	return 0;
}