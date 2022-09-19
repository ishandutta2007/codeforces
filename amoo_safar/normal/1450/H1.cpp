// har ki ro didi goft mikhad beshe meslemon !
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
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}


ll cnt[N], A[N], B[N];

ll f[N], iv[N];
ll nCr(ll n, ll r){
	return mul(f[n], mul(iv[r], iv[n-r]));
}

ll Solve(ll fix, ll nf){
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i <= nf; i++){
		cnt[i + fix] = nCr(nf, i);
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = iv[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(i, f[ i - 1]);
	for(int i = 1; i < N; i++) iv[i] = inv(f[i]);
	
	int n, m;
	cin >> n >> m;
	assert(m == 0);
	str s;
	cin >> s;

	int cntQ = 0;
	for(auto c : s) cntQ += (c == '?');
	int q = 0, b = 0;
	for(int i = 0; i < n; i += 2) b += (s[i] == 'b');
	for(int i = 0; i < n; i += 2) q += (s[i] == '?');
	Solve(b, q);
	swap(cnt, A);
	
	q = 0, b = 0;
	for(int i = 1; i < n; i += 2) b += (s[i] == 'b');
	for(int i = 1; i < n; i += 2) q += (s[i] == '?');
	Solve(b, q);
	swap(cnt, B);


	ll ans = 0;
	ll S = 0, S2 = 0;
	for(int i = 0; i <= n; i += 2){
		S += A[i]; S %= Mod;
		ans += mul(B[i], S2); ans %= Mod;
		S2 += S; S2 %= Mod;
	}
	S = 0, S2 = 0;
	for(int i = 1; i <= n; i += 2){
		S += A[i]; S %= Mod;
		ans += mul(B[i], S2); ans %= Mod;
		S2 += S; S2 %= Mod;
	}
	swap(A, B);
	S = 0, S2 = 0;
	for(int i = 0; i <= n; i += 2){
		S += A[i]; S %= Mod;
		ans += mul(B[i], S2); ans %= Mod;
		S2 += S; S2 %= Mod;
	}
	S = 0, S2 = 0;
	for(int i = 1; i <= n; i += 2){
		S += A[i]; S %= Mod;
		ans += mul(B[i], S2); ans %= Mod;
		S2 += S; S2 %= Mod;
	}
	// debug(ans);
	cout << mul(ans, inv(bin_pow(2, cntQ - 1))) << '\n';
	return 0;
}