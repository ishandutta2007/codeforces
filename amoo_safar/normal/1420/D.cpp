// That's How much we have in common
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
const int N = 3e5 + 10;
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

ll f[N], iv[N];

ll nCr(ll n, ll r){
	if(r < 0 || n < r) return 0;
	return mul(f[n] , mul(iv[r], iv[n - r]));
}


ll l[N], r[N];
map<ll, ll> op, cl;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < N; i++) iv[i] = bin_pow(f[i], Mod - 2);
	debug(nCr(6, 3));
	ll n, k;
	cin >> n >> k;
	vector<ll> V;
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		op[l[i]] ++;
		cl[r[i] + 1] ++;
		V.pb(l[i]);
		V.pb(r[i] + 1);
	}
	ll ans = 0;
	sort(all(V));
	V.resize(unique(all(V)) - V.begin());
	ll tmp, cnt = 0;
	for(auto x : V){
		//cerr << "! " << x << '\n';
		cnt -= cl[x];
		tmp = op[x];
		ans += nCr(cnt + tmp, k) - nCr(cnt, k);
		ans %= Mod;
		cnt += tmp;
	}
	ans += Mod;
	cout << ans % Mod << '\n';
	return 0;
}