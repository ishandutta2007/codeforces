#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;

ll qpow(ll b, ll p){
	ll ret = 1LL;
	while(p){
		if(p & 1) ret = ret * b % Mod;
		b = b * b % Mod;
		p >>= 1; 
	}
	return ret;
}
ll stirl[5050][5050];
ll n, k;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	stirl[1][1] = 1;
	for(ll i = 2; i <= k; i++){
		for(ll j = 1; j <= k; j++){
			stirl[i][j] = (stirl[i-1][j-1] + j * stirl[i-1][j]) % Mod;
		}
	}
	ll ans = 0;
	ll now_pow = 1LL;
	for(ll i = 0; i <= k && i <= n; i++){
		ans += stirl[k][i] * now_pow % Mod * qpow(2, n - i) % Mod;
		now_pow = (now_pow * (n - i)) % Mod;
	}
	cout << ans % Mod << endl;
	return 0;
}