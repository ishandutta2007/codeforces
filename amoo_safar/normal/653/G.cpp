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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

map<int, vector<int>> mp;

int C[Log];
ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j += j, pw = mul(pw, pw))
		if(j & p)
			res = mul(res, pw);
	return res;
}
 
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}
ll f[N], iv[N];
ll nCr(ll n, ll r){
	if(r < 0 || n < 0 || n < r) return 0;
	return mul(f[n], mul(iv[r], iv[n - r]));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < N; i++) iv[i] = inv(f[i]);

	int n;
	cin >> n;
	int v;
	for(int i = 1; i <= n; i++){
		cin >> v;
		int d = 2;
		int cnt = 0;
		while(d * d <= v){
			cnt = 0;
			while(v % d == 0){
				v /= d;
				cnt ++;
			}
			if(cnt)
				mp[d].pb(cnt);
			d ++;
		}
		if(v > 1)
			mp[v].pb(1);
	}
	ll ans = 0;
	for(auto [prime, vec] : mp){
		memset(C, 0, sizeof C);
		for(auto x : vec) C[x] ++;
		C[0] = n - ((int)vec.size());
		int sum = n;
		int nw = 0;
		
		for(int i = 0; i < Log; i++){
			nw += C[i];
			sum -= C[i];
			// if(min(nw, sum) > 0)
			// 	cerr << "!! " << nw << ' ' << sum << '\n';
			ll ps = 0;
			for(int j = sum; j >= 0; j--){
				ans += mul(mul(j, nCr(nw, j)), ps);
				ps += nCr(sum, j);
				ps %= Mod;
			}
			// if(min(nw, sum) > 0)
			// 	cerr << "!! " << ans << '\n';
			
			ps = bin_pow(2, nw);
			for(int j = 0; j <= sum; j++){
				ans += mul(mul(j, nCr(sum, j)), ps);
				ps -= nCr(nw, j);
				ps %= Mod;
			}
			// cerr << "### " << ans << '\n';	
			// break;
		}
		// debug(ans);
	}
	ans %= Mod;
	ans += Mod;
	cout << ans % Mod << '\n';
	return 0;
}