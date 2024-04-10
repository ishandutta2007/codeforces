#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;

ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

ll modInv(ll x) {
	return modPow(x, mod - 2);
}

ll C2(ll x) {
	return x * (x - 1) / 2 % mod;
}
;

struct FT {
	int n;
	vector<int> vals;
	FT(int n) :
			n(n), vals(vector<int>(n + 1, 0)) {
	}

	void update(int i, const int a) {
		for (++i; i <= n; i += i & -i)
			vals[i] += a;
	}
	int query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += vals[i];
		return sum;
	}
	int query(int i, int j) const {
		return query(j) - query(i - 1);
	}
};

ll countInv(vector<int> v) {
	const int n = (int) v.size() + 5;

	FT ft(n);
	ll ans = 0;
	for (const int &x : v) {
		if (x == -1)
			continue;
		ans += ft.query(x, n - 1);
		ft.update(x, 1);
	}
	return ans % mod;
}

const int MaxN = (int) 2e5 + 9;

int n;
int a[MaxN + 9];

ll dp1[MaxN + 9];
ll dp2[MaxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);

	const int cntM1 = count(a, a + n, -1);

	{
		int cnt = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] == -1)
				cnt++;
			else {
				dp1[a[i]] = cnt;
			}
		}
	}

	{
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (a[i] == -1)
				cnt++;
			else
				dp2[a[i]] = cnt;
	}

	ll sum = 0;
	ll ans = 0;

	for(int i = n; i >= 1; --i)
		if(dp2[i] != -1)
			sum += dp2[i];

	// cerr << "sum:" << sum << endl;
	for (int i = n; i >= 1; --i) {
		if (dp1[i] == -1) {
			// cerr << "sum:" << sum << endl;
			ans += sum * modInv(cntM1) % mod;
			ans %= mod;
		} else {
			sum += dp1[i] - dp2[i];
			sum %= mod;
		}
	}

	// cerr << ans << endl;
	ans += C2(cntM1) % mod * modInv(2) % mod;
	// cerr << ans << endl;
	ans += countInv(vector<int>(a, a + n)) % mod;
	cout << (ans % mod + mod) % mod;
	return 0;
}