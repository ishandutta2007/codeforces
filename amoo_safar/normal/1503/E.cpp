// Black lives matter !
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
const int N = 5e5 + 10;
const int Inf = 2000000100;
const ll Log = 30;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}

ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j *= 2, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}
ll f[N], iv[N];

ll nCr(ll n, ll r){
	return mul(f[n],mul(iv[r], iv[n - r]));
}
ll Sum(ll n, ll al){
	return nCr(n - 1 + al, al);
}

ll A[N], B[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < N; i++) iv[i] = bin_pow(f[i], Mod - 2);
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for(int i = 1; i <= m - 1; i++){
		ll SS = 0;
		for(int j = 2; j <= n - 1; j++){
			SS += mul(Sum(j - 1, m - i), Sum(n - j + 2, m - i - 1));
			SS %= Mod;
			ll U = mul(Sum(j + 1, i - 1), Sum(n - j, i));
			ans += mul(U, SS);
		}
	}
	// debug(ans);
	for(int i = 1; i <= n - 1; i++){
		for(int j = 1; j <= m; j++){
			A[j] = mul(Sum(i + 1, j - 1), Sum(i, m - j));
		}
		ll t = n - i;
		ll SS = 0;
		for(int j = 1; j <= m; j++){
			B[j] = mul(Sum(t, j - 1), Sum(t + 1, m - j));
			SS += B[j];
			SS %= Mod;
		}
		// cerr << "! ";
		// for(int j = 1; j <= m; j ++) cerr << A[j] << ' ';
		// cerr << "\n! ";
		// for(int j = 1; j <= m; j ++) cerr << B[j] << ' ';
		// cerr << '\n';
		for(int j = 1; j <= m; j++){
			SS -= B[j];
			SS %= Mod;
			ans += mul(SS, A[j]);
			ans %= Mod;
		}
	}
	ans %= Mod;
	ans += Mod;
	ans %= Mod;
	ans = mul(ans, 2);
	cout << ans << '\n';
	return 0;
}
/*

*/