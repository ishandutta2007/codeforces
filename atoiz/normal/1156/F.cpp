/*input
5
4 5 1 3 2

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

const int MOD = 998244353;

#define div divv
int add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += MOD; return a; }
int mul(int a, int b) { return (long long) a * b % MOD; }
int qpow(int a, int p)
{
	int ans = 1;
	while (p) {
		if (p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}
int inv(int a) { return qpow(a, MOD - 2); }
int div(int a, int b) { return mul(a, inv(b)); }

const int MAXN = 10007;
int cnt[MAXN], n;
int fact[MAXN], invFact[MAXN], dp[MAXN];
int nCk(int n, int k) { return mul(fact[n], mul(invFact[k], invFact[n-k])); }

// start of code

signed main()
{
	// freopen("test.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	FOR(i, 1, n) { int x; cin >> x; ++cnt[x]; }

	fact[0] = 1; FOR(i, 1, MAXN - 1) fact[i] = mul(fact[i-1], i);
	invFact[MAXN - 1] = inv(fact[MAXN - 1]); FORB(i, MAXN - 1, 1) invFact[i-1] = mul(invFact[i], i);

	int total = 0, ans = 0;
	dp[0] = 1;
	FOR(x, 1, n) {
		if (cnt[x] >= 2) FOR(c, 0, total) {
			int tmp = mul(invFact[n], fact[n - c - 2]);
			tmp = mul(tmp, dp[c]);
			tmp = mul(tmp, cnt[x]);
			tmp = mul(tmp, cnt[x] - 1);
			ans = add(ans, tmp);
		}

		if (cnt[x] >= 1) {
			++total;
			FORB(i, total, 1) {
				dp[i] = add(dp[i], mul(dp[i-1], cnt[x]));
			}
		}
	}

	cout << ans << endl;

	return 0;
}