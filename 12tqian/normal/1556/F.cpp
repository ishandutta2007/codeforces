#include <bits/stdc++.h>

using namespace std;

// 5 is a root of both mods
template <int MOD, int RT> struct Mint {
	static const int mod = MOD;
	static constexpr Mint rt() { return RT; } // primitive root for FFT
	static constexpr int md() { return MOD; } // primitive root for FFT
	int v; 
	explicit operator int() const { return v; } // explicit -> don't silently convert to int
	explicit operator bool() const { return v != 0; }
	Mint() { v = 0; }
	Mint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }
	friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }
	friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }
	friend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }
	friend bool operator>(const Mint &a, const Mint &b) { return a.v > b.v; }
	friend bool operator<=(const Mint &a, const Mint &b) { return a.v <= b.v; }
	friend bool operator>=(const Mint &a, const Mint &b) { return a.v >= b.v; }
	friend std::istream& operator >> (std::istream &in, Mint &a) { 
		long long x; std::cin >> x; a = Mint(x); return in; }
	friend std::ostream& operator << (std::ostream &os, const Mint &a) { return os << a.v; }
	Mint& operator+=(const Mint &m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	Mint& operator-=(const Mint &m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	Mint& operator*=(const Mint &m) { 
		v = (long long)v * m.v % MOD; return *this; }
	Mint& operator/=(const Mint &m) { return (*this) *= inv(m); }
	friend Mint pow(Mint a, long long p) {
		Mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; 
	}
	friend Mint inv(const Mint &a) { assert(a.v != 0); return pow(a, MOD - 2); }
	Mint operator-() const { return Mint(-v); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	friend Mint operator+(Mint a, const Mint &b) { return a += b; }
	friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint &b) { return a /= b; }
};

using mi = Mint<1000000007, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	mi ans = 0;
	for (int r = 0; r < n; ++r) {
		swap(a[0], a[r]);
		vector<mi> cnt(1 << n, 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				for (int msk = 0; msk < 1 << n; ++msk) {
					if (((1 << i) & msk) && ((1 << j) & msk)) {
						cnt[msk] *= a[i] + a[j];
					}
				}
			}
		}
		vector<mi> prod(1 << n, 1);
		for (int msk = 0; msk < 1 << n; ++msk) {
			for (int i = 0; i < n; ++i) {
				if ((1 << i) & msk) {
					prod[msk] *= a[i];
				}
			}
		}
		vector<mi> dp(1 << n);
		dp[0] = dp[1] = 1;
		for (int msk = 2; msk < 1 << n; ++msk) {
			if (!(msk & 1)) {
				continue;
			}
			auto process = [&](int sub) { 
				int nmsk = msk ^ sub;
				dp[msk] -= dp[sub] * cnt[nmsk] * pow(prod[nmsk], __builtin_popcount(sub));
			};
			process(0);
			dp[msk] *= -1;
			for (int sub = msk; sub; sub = (sub - 1) & msk) {
				if (sub != msk) {
					process(sub);
				}
			}
		}
		ans += dp.back();
		swap(a[0], a[r]);
	}
	mi den = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			den *= a[i] + a[j];
		}
	}
	ans /= den;
	cout << ans << '\n';
	return 0;
}