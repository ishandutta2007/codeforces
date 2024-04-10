#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 3;
const ll mod = 1e9 + 7;

ll t[maxn], fac[maxn], rev[maxn], pw[maxn];

ll power(ll a, ll b){
	if (b == 0)
		return 1;
	ll ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

ll Choose(ll n, ll r){
	return 1ll * fac[n] * rev[r] % mod * rev[n - r] % mod;
}

ll get(ll a, ll b){
	return 1ll * a * power(b, mod - 2) % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	ll T;
	cin >> n >> T;
	pw[0] = 1;
	for (ll i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * 2 % mod;
	fac[0] = 1;
	for (ll i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	rev[n] = power(fac[n], mod - 2);
	for (ll i = n - 1; i >= 0; i--)
		rev[i] = 1ll * rev[i + 1] * (i + 1) % mod;

	for (ll i = 1; i <= n; i++)
		cin >> t[i];

	ll idx = 0;
	for (ll i = 1; i <= n; i++){
		T -= t[i];
		if (T < i){
			T += t[i];
			idx = i;
			break;
		}
		idx = i;
		if (i == n)
			return cout << n << endl, 0;
	}
	ll answer = idx - 1;
	T -= t[idx];
	ll bin = 0;
	for (ll i = 0; i <= T; i++)
		bin = (bin + Choose(idx, i)) % mod;

//	cout << idx << " -> " << bin << endl;
	answer = (answer + get(bin, pw[idx])) % mod;

	for (ll i = idx + 1; i <= n; i++){
		if (T - t[i] < 0)
			break;
		bin = (2ll * bin - Choose(i - 1, T) + mod) % mod;
		for (ll j = T; j > T - t[i]; j--)
			bin = (bin - Choose(i, j) + mod) % mod;
//		cout << i << " -> " << bin << endl;
		answer = (answer + get(bin, pw[i])) % mod;
		T -= t[i];
	}
	cout << answer << endl;
}