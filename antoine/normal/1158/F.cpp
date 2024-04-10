#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;
const ll mod2 = (ll) mod * mod;

ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

ll modInv(const ll x) {
	return modPow(x, mod - 2);
}

const int MxN = 3009;
const int J = 10;
int p2[MxN + 9];
int ans[MxN + 9];

int n, c;
int a[MxN + 9];

void solve1() { // c > J

	static int dp1[MxN + 9][MxN + 9];

	{
		static int aux1[MxN + 9], aux2[MxN + 9];
		for (int i = 0; i <= n; ++i) {
			aux1[i] = p2[i] - 1;
			assert(aux1[i] >= 0);
			aux2[i] = (int) modInv(aux1[i]);
			assert(0 <= aux2[i] && aux2[i] < mod);
		}
		for (int i = n - 1; i >= 0; --i) {
			static int occ[MxN + 9];
			memset(occ, 0, sizeof occ);
			int cnt = 0;
			ll curr = 1;
			for (int j = i; j < n; ++j) {
				int &o = occ[a[j]];
				if (o)
					(curr *= aux2[o]) %= mod;
				else
					cnt++;
				(curr *= aux1[++o]) %= mod;
				assert(cnt <= c);
				dp1[i][j] = cnt < c ? 0 : curr * aux2[o] % mod;
			}
		}
	}

	static int dp2[MxN + 9];
	dp2[n] = 1;
	for (int i = n - 1; i >= 0; --i)
		dp2[i] = dp2[i + 1] * 2 % mod;
	ans[0] = p2[n] - 1;

	for (int k = 1; k <= n / c; ++k) {
		for (int i = 0; i <= n; ++i) {
			ll res = 0;
			for (int j = i; j < n; ++j) {
				res += (ll) dp1[i][j] * dp2[j + 1];
				if (res >= mod2)
					res -= mod2;
			}
			assert(0 <= res && res < mod2);
			dp2[i] = (int) (res % mod);
		}

		assert(!dp2[n]);
		ans[k - 1] -= dp2[0];
		ans[k] = dp2[0];
	}
}

void solve2() { // c <= J
	assert(c <= J);
	static int dp[MxN + 2][1 << J];

	dp[n][0] = 1;
	for (int i = n - 1; i >= 0; --i)
		dp[i][0] = dp[i + 1][0] * 2 % mod;
	ans[0] = p2[n] - 1;

	for (int k = 1; k <= n / c; ++k) {
		for (int i = n; i >= 0; --i) {
			dp[i][(1 << c) - 1] = dp[i][0];
			for (int m = (1 << c) - 2; m >= 0; --m) {
				int &res = dp[i][m] = dp[i + 1][m] + dp[i + 1][m | (1 << a[i])];
				if (res >= mod)
					res -= mod;
			}
		}
		assert(dp[n][0] == 0);
		ans[k - 1] -= dp[0][0];
		ans[k] = dp[0][0];
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	p2[0] = 1;
	for (int i = 1; i <= MxN; ++i)
		p2[i] = p2[i - 1] * 2LL % mod;

	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	c > J ? solve1() : solve2();

	for (int i = 0; i <= n; ++i)
		cout << (ans[i] % mod + mod) % mod << ' ';
	return 0;
}