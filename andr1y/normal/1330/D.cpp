//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll mlog2(ll n){
	ll c = 0;
	while(n){
		n>>=1, c++;
	}
	return c-1;
}
ll uk[50];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
		ll n, m;
		cin >> n >> m;
		ll ln = mlog2(n);
		for(ll i =0;i<ln;i++) uk[i] = (1ll<<i)%m;
		uk[ln] = (n-(1ll<<ln)+1)%m;
		ll res = uk[0]+1;
		for(ll i = 1;i<=ln;i++){
			ll r2 = (res*uk[i])%m;
			res += r2;
			res %= m;
		}
		res = (res-1+m)%m;
		cout << res << '\n';
	}
}