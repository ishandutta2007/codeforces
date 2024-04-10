#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll p;

ll mexp(ll a, ll e){
	ll res = 1;
	for(; e; e >>= 1, a = a * a % p)
		if(e & 1) res = res * a % p;
	return res;
}

ll inv(ll a){
	return mexp(a, p-2);
}

ll fs[401], ifs[401], dp[401][401] = {};

int main(){
	int n;
	cin >> n >> p;

	ifs[0] = fs[0] = 1;
	rep(i,1,n+1){
		ifs[i] = ifs[i-1] * inv(i) % p;
		fs[i] = fs[i-1] * i % p;
	}

	rep(l,1,n+1){
		dp[l][l] += mexp(2, l-1) * ifs[l] % p;
		rep(i,1,l-1) rep(k,1,l-i){
			dp[l][k + i] = (dp[l][k+i] + mexp(2, i-1) * ifs[i] % p * dp[l-i-1][k]) % p;
		}
	}
	ll ans = 0;
	rep(k,1,n+1) ans += dp[n][k] * fs[k] % p;
	ans %= p;
	if(ans < 0) ans += p;
	cout << ans << endl;
}