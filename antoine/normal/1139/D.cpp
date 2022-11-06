#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = (int) 1e9 + 7;

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

vector<pair<ll, int>> getFact(ll x) {
	vector<pair<ll, int>> v;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x % i == 0; x /= i)
				v.back().second++;
		}
	if (x != 1)
		v.emplace_back(x, 1);

	return v;
}

void getDivisorsHelper(int i, ll curr, const vector<pair<ll, int>> &v, vector<ll> &res) {
	if (i == (int) v.size())
		res.push_back(curr);
	else {
		for (int j = 0; j <= v[i].second; ++j) {
			getDivisorsHelper(i + 1, curr, v, res);
			curr *= v[i].first;
		}
	}
}

vector<ll> getDivisors(const ll x) {
	const vector<pair<ll, int>> v = getFact(x);
	vector<ll> res;
	getDivisorsHelper(0, 1, v, res);
	return res;
}

pair<ll, bool> f(ll x) {
	vector<pair<ll, int>> fact = getFact(x);
	bool ok = true;
	ll p = 1;
	for (auto &&x : fact) {
		if (x.second != 1)
			ok = false;
		p *= x.first;
	}
	return {p, ok};
}

const int MxM = (int) 1e5 + 9;
ll dp[MxM + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int M;
	cin >> M;

	for (int i = 2; i <= M; ++i) {
		ll &res = dp[i];
		{
			pair<ll, bool> f__ = f(i);
			if (!f__.second) {
				res = dp[f__.first];
				continue;
			}
		}

		const vector<pair<ll, int>> fact = getFact(i);
		for (int mask = (1 << (int) fact.size()) - 2; mask >= 0; --mask) {
			ll p = 1;
			vector<ll> nums;
			for (int j = 0; j < (int) fact.size(); ++j)
				if (mask & (1 << j))
					p *= fact[j].first;
				else
					nums.push_back(fact[j].first);

			assert(i % p == 0 && i > p);

			ll cnt = 0;
			for (int mask2 = (1 << (int) nums.size()) - 1; mask2 >= 0; --mask2) {
				ll p2 = 1;
				int popCnt = 0;
				for (int j = 0; j < (int) nums.size(); ++j)
					if (mask2 & (1 << j)) {
						p2 *= nums[j];
						++popCnt;
					}
				cnt += (popCnt & 1 ? -1 : 1) * (M / (p * p2));
			}
			res += cnt * dp[p];
			res %= mod;
		}
		res = (res + M) * modInv(M - M / i);
		res %= mod;
	}

	ll ans = 0;
	for (int i = 0; i <= M; ++i) {
		ans += dp[i];
		ans %= mod;
	}
	ans *= modInv(M);
	cout << (((ans + 1) % mod) + mod) % mod;
	return 0;
}