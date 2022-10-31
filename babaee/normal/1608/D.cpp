#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 5e5 + 10;
const ll MOD = 998244353;

int n;
ll fact[MAXN], inv[MAXN], x, w, b, fw, fb;
bool flag1 = true, flag2 = true;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	fact[0] = inv[0] = 1;

	for (int i = 1; i < MAXN; i++)
		fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);

	int fuckb = 0;
	for (int i = 1; i <= n; i++) {
		char a, b;
		cin >> a >> b;
		if (a == 'W' || b == 'B') flag1 = false;
		if (a == 'B' || b == 'W') flag2 = false;

		if (a == '?' && b == '?') x++;
		if (a == 'W' && b == 'W') fw++;
		if (a == 'B' && b == 'B') fb++;
		if (a == 'W' && b == '?') w++;
		if (a == '?' && b == 'W') w++;
		if (a == 'B' && b == '?') fuckb++;
		if (a == '?' && b == 'B') fuckb++;
	}

	b = fuckb;

	ll ans = 0;
	for (int i = 0; i <= x; i++) {
		ll tw = w + i, tb = b + x - i;
		ll delta = fb - fw;
		// C(k, tb) * C(k + delta -> tw - k - delta, tw) -> tw - delta, 
		ll tans = C(tw - delta, tw + tb);
		ans = (ans + tans * C(i, x)) % MOD;
	}

	//
	if (fw == fb && fw == 0) ans = (ans - poww(2, x) + MOD) % MOD;
	cout << (ans + flag1 + flag2) % MOD << endl;
	return 0;
}