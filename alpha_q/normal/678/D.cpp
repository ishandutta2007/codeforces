/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \
      	
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll bigMod (ll a, ll e) {
	if (e == -1) e = MOD - 2;
	ll r = 1LL;
	while (e) {
		if (e & 1) r = (r * a) % MOD;
		a = (a * a) % MOD;
		e >>= 1;
	}
	return r;
}

ll A, B, n, x, Ans;

int main (int argc, char const *argv[]) {
	cin >> A >> B >> n >> x;

	if (A == 1) {
		Ans = (n % MOD) * (B % MOD);
		Ans %= MOD, Ans += x, Ans %= MOD;
	} else {
		ll Pow = bigMod(A, n);
		ll inv = bigMod(A - 1, -1);
		Ans = (x % MOD) * Pow;
		Ans %= MOD;
		ll add = ((Pow - 1) * (B % MOD)) % MOD;
		add = (add * inv) % MOD;
		Ans += add, Ans %= MOD;
		Ans += MOD, Ans %= MOD;
	}

	cout << Ans << endl;
	return 0;
}