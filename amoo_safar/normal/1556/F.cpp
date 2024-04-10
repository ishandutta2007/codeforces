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
const int N = 2e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <=p ; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}
ll iv[N];
ll dp[(1 << 14)];
ll a[N];

ll sm[N];

int Main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> A, B;
	ll ans = 0;
	for(int mk = 1; mk < (1 << n); mk ++){
		A.clear();
		B.clear();
		for(int i = 0; i < n; i++){
			if(mk >> i & 1)
				A.pb(i);
			else
				B.pb(i);
		}
		dp[mk] ++;
		dp[mk] %= Mod;
		// cerr << "! " << dp[mk] << '\n';
		int sz = B.size();
		fill(sm, sm + (1 << sz), 0);
		sm[0] = 1;
		for(int i = 1; i < (1 << sz); i++){
			for(int j = 0; j < sz; j++){
				if(i >> j & 1){
					sm[i] = sm[i ^ (1 << j)];
					for(auto x : A)
						sm[i] = mul(sm[i], mul(a[x], iv[a[x] + a[ B[j] ]] ));
					break;
				}
			}
			int mk2 = mk;
			for(int j = 0; j < sz; j++)
				if(i >> j & 1)
					mk2 += (1 << B[j]);
			dp[mk2] -= mul(dp[mk], sm[i]);
		}

		// debug(sz);
		// debug(sm[(1 << sz) - 1]);
		ans += mul((ll) A.size(), mul(dp[mk], sm[(1 << sz) - 1]));
		ans %= Mod;
	}
	ans += Mod;
	cout << ans % Mod << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 1; i < N; i++) iv[i] = bin_pow(i, Mod - 2);
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}