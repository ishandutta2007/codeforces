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

const ld pi = acos(-1);
const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 20;

ll mul(ll a, ll b){ return (a * b) % Mod; }
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

ll f[N];
ll fc[N];
ll E[N], cz[N];
ll poly[N], E2[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fc[0] = 1;
	for(int i = 1; i < N; i++) fc[i] = mul(fc[i - 1], i);

	ll n, k;
	cin >> n >> k;


	ll ik = inv(k);
	ll ia = inv( mul(n, k) );
	ll C = 0;
	for(int i = 0; i < n; i++){
		ll no = mul((i + (n - i) * (k - 1)) % Mod, ia);
		ll dec = mul(mul(i, (k - 1)), ia);
		// ll inc = mul(mul(n - i, 1), ia);
		ll con = 1;
		ll z = no + dec;
		if(i)
			con += mul(dec, f[i - 1]);
		f[i] = mul(con, inv(1 - z));
		(C += f[i]) %= Mod;
	}
	E[n] = 0;
	for(int i = n - 1; i >= 0; i--)
		E[i] = (f[i] + E[i + 1]) % Mod;

	map<int, ll> mp;
	int v;
	cz[0] = k;
	for(int i = 0; i < n; i++){
		cin >> v;
		mp[v] ++;
	}
	ll c = mp[-1];
	ll den = inv(bin_pow(k, c));
	for(int i = 0; i <= c; i++)
		poly[i] = mul(   mul(bin_pow(k - 1, c - i),   mul(fc[c], inv(mul(fc[i], fc[c - i])))) , den) ;
	// for(int i = 0; i <= c; i++) cerr << poly[i] << '\n';

	for(auto [val, cnt] : mp){
		if(val == -1) continue;
		cz[0] --;
		cz[cnt] ++;
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++){
		if(cz[i] == 0) continue;
		for(int j = 0; j <= c; j++)
			(E2[i + j] += mul(cz[i], poly[j])) %= Mod;
	}
	for(int i = 0; i <= n; i++)
		(ans += mul(E[i], E2[i]) ) %= Mod;
	ans -= mul(k - 1, C);
	ans %= Mod;
	ans = mul(ans, ik);
	ans += Mod;
	cout << ans % Mod << '\n';
	return 0;
}