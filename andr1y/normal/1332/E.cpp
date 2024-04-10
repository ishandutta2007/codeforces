//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll M = 998244353;
ll bpm(ll a, ll b){
	if(b == 0) return 1;
	if(b == 1) return a%M;
	if(b&1) return (a*bpm((a*a)%M, b>>1))%M;
	else return bpm((a*a)%M, b>>1);
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll l, r, n, m;
	cin >> n >> m >> l >> r;
	ll k = (r-l+1);
	if(n&m&1){
		cout << bpm(k%M, m*n) << '\n';
	}else{
		ll e = r/2-(l-1)/2, o = k-e;
		ll 	k1 = bpm(e+o, n*m),
			k2 = bpm(e-o, n*m);
		ll ks = (k1+k2)*(M+1);
		ks>>=1, ks%=M;
		cout << ks << '\n';
	}
}