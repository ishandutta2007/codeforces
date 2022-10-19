#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
ll qpow(ll b, ll p){
	ll ret = 1;
	while(p){
		if(p & 1)
			ret = ret * b % Mod;
		b = b * b % Mod;
		p >>= 1;
	}
	return ret;
}

ll fact[400400], invfact[400400];
ll C(int n, int m){
	return fact[n] * invfact[m] % Mod * invfact[n - m] % Mod;
}

int n;
int a[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	fact[0] = 1;
	for(int i = 1; i <= 400000; i++)
		fact[i] = fact[i - 1] * i % Mod;
	invfact[400000] = qpow(fact[400000], Mod - 2);
	for(int i = 399999; i >= 0; i--)
		invfact[i] = invfact[i + 1] * (i + 1) % Mod;
	rep(i, n + 1)
		cin >> a[i];
	ll ans = 0;
	rep(i, n + 1)
		if(a[i])
			ans = (ans + C(a[i] + i, i + 1)) % Mod;
	cout << ans << endl;
	return 0;
}