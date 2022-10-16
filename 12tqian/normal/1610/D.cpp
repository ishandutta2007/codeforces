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
	friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
	friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
	friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
	friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
	friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
	friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
	friend std::istream& operator >> (std::istream& in, Mint& a) { 
		long long x; std::cin >> x; a = Mint(x); return in; }
	friend std::ostream& operator << (std::ostream& os, const Mint& a) { return os << a.v; }
	Mint& operator+=(const Mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	Mint& operator-=(const Mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	Mint& operator*=(const Mint& m) { 
		v = (long long)v * m.v % MOD; return *this; }
	Mint& operator/=(const Mint& m) { return (*this) *= inv(m); }
	friend Mint pow(Mint a, long long p) {
		Mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; 
	}
	friend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }
	Mint operator-() const { return Mint(-v); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	friend Mint operator+(Mint a, const Mint& b) { return a += b; }
	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
};

using mi = Mint<1000000007, 5>;

int main() {
	const int L = 31;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> cnt(L);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		int v2 = 0;
		while (x % 2 == 0) {
			x >>= 1;
			++v2;
		}
		++cnt[v2];
	}
	vector<mi> po(n + 1);
	po[0] = 1;
	for (int i = 1; i <= n; ++i) {
		po[i] = po[i - 1] * 2;
	}
	mi ans = 0;
	int top = 0;
	for (int i = L - 1; i >= 1; --i) {
		if (cnt[i]) {
			ans += (po[cnt[i] - 1] - 1) * po[top];
		}
		top += cnt[i];
	}
	if (cnt[0]) {
		ans += (po[cnt[0]] - 1) * po[top];
	}
	cout << ans << '\n';
	return 0;
}

/**
 * (n choose 2) mod n
 * if n is even
 * then we have n / 2 mod n
 * else 0 mod n
 * 3 mod 6
 * 4 mod 8
 * 3 mod 6
 * 5 mod 10
 * gcd(everything) | sum of the things
 * minimum v2(everything) <= v2(sum of everything)
 * let's say the minimum v2 thing
 * you must pick an even number of the minimum v2 thing
 */