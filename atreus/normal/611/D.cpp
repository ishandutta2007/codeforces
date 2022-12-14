#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll maxn = 5000 + 10;
const ll mod = 1e9 + 7;
const ll base = 13;

ll dp[maxn][maxn];
string s;
ll hsh[maxn], pw[maxn];

ll get_hsh(ll f, ll l){
	return (hsh[f + l - 1] - 1ll * hsh[f - 1] * pw[l] % mod + mod) % mod;
}

bool smaller(ll f, ll t, ll l){
	ll lo = 0, hi = l + 1;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		if (get_hsh(f, mid) != get_hsh(t, mid))
			hi = mid;
		else
			lo = mid;
	}
	if (lo == l)
		return 0;
	return s[f + lo] < s[t + lo];
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n >> s;
	s = " " + s;
	pw[0] = 1;
	for (ll i = 1; i <= n; i++){
		pw[i] = 1ll * pw[i - 1] * base % mod;
		hsh[i] = (1ll * hsh[i - 1] * base + (ll)(s[i] - '0') + 1) % mod;
	}
	for (ll i = 1; i <= n; i++){
		for (ll j = 1; j <= i; j++){
			if (s[i - j + 1] == '0'){
				dp[i][j] = 0;
				continue;
			}
			ll pre = i - j;
			if (pre == 0){
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[pre][j - 1];
			if (pre >= j and s[pre - j + 1] != '0' and smaller(pre - j + 1, i - j + 1, j))
				dp[i][j] = dp[pre][j];
		}
		for (ll j = 1; j <= n; j++)
			dp[i][j] = (dp[i][j - 1] + dp[i][j]) % mod;
	}
	cout << dp[n][n] << endl;
}