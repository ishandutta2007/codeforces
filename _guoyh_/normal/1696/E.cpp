# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 400051;
const int P = 1000000007;
ll pwr(ll x, ll y){
	x %= P;
	y = (y % (P - 1) + (P - 1)) % (P - 1);
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int n;
int a[MAXN];
ll fac[MAXN], ifac[MAXN];
ll C(int u, int v){
	if (v < 0 || v > u) return 0;
	else return fac[u] * ifac[v] % P * ifac[u - v] % P;
}
int main(){
	ios::sync_with_stdio(false);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < MAXN; i++){
		fac[i] = fac[i - 1] * i % P;
		ifac[i] = pwr(fac[i], -1);
	}
	cin >> n;
	for (int i = 0; i <= n; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 0; i <= n; i++){
		ans = (ans + C(i + a[i], i + 1)) % P;
	}
	cout << ans << '\n';
	return 0;
}