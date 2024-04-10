#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;

int popCnt(int m) {
	int res = 0;
	while (m) {
		m &= m - 1;
		res++;
	}
	return res;
}

typedef pair<ll, ll> PLL;

int K;
string M;
PLL dp[25][1 << 10][2];
ll p10[50];


PLL f(const int i, const int mask, const bool b) {
	PLL &res = dp[i][mask][b];
	if (res.first != -1)
		return res;
	if (popCnt(mask) > K)
		return res = {0LL, 0LL};
	if (i == (int) M.size())
		return {!b, 0};

	res = {0, 0};
	for (int d = b ? M[i] - '0' : 9; d >= 0; --d) {
		const PLL temp = f(i + 1, mask | (1 << d), b && d == M[i] - '0');
		res.first += temp.first;
		res.second += temp.second
				+ temp.first * d % mod * p10[(int) M.size() - 1 - i] % mod;
		res.first %= mod;
		res.second %= mod;
	}
	return res;
}

PLL g(const int i, const bool b) {
	PLL res = { 0, 0 };
	for (int d = b ? M[i] - '0' : 9; d >= 1; --d) {
		const PLL temp = f(i + 1, 1 << d, b && d == M[i] - '0');
		res.first += temp.first;
		res.second += temp.second
				+ temp.first * d % mod * p10[(int) M.size() - 1 - i] % mod;
		res.first %= mod;
		res.second %= mod;
	}
	return res;
}

ll f(const ll bound) {
	memset(dp, -1, sizeof dp);
	M = to_string(bound);
	ll res = g(0, 1).second;
	for (int i = 1; i < (int) M.size(); ++i) {
		res += g(i, 0).second;
		res %= mod;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p10[0] = 1;
	for (int i = 1; i <= 40; ++i)
		p10[i] = p10[i - 1] * 10LL % mod;

	ll l, r;
	cin >> l >> r >> K;
	ll res = f(r + 1) - f(l);
	res %= mod;
	res += mod;
	res %= mod;
	cout << res << endl;
	return 0;
}