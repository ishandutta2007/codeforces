#include <bits/stdc++.h>

using namespace std;

// 5 is a root of both mods
template <int MOD, int RT>
struct Mint {
	static const int mod = MOD;
	static constexpr Mint rt() { return RT; }	 // primitive root for FFT
	static constexpr int md() { return MOD; }	 // primitive root for FFT
	int v;
	explicit operator int() const { return v; }	 // explicit -> don't silently convert to int
	explicit operator bool() const { return v != 0; }
	Mint() { v = 0; }
	Mint(long long _v) {
		v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD;
	}
	friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
	friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
	friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
	friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
	friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
	friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
	friend std::istream& operator>>(std::istream& in, Mint& a) {
		long long x;
		std::cin >> x;
		a = Mint(x);
		return in;
	}
	friend std::ostream& operator<<(std::ostream& os, const Mint& a) { return os << a.v; }
	Mint& operator+=(const Mint& m) {
		if ((v += m.v) >= MOD) v -= MOD;
		return *this;
	}
	Mint& operator-=(const Mint& m) {
		if ((v -= m.v) < 0) v += MOD;
		return *this;
	}
	Mint& operator*=(const Mint& m) {
		v = (long long)v * m.v % MOD;
		return *this;
	}
	Mint& operator/=(const Mint& m) { return (*this) *= inv(m); }
	friend Mint pow(Mint a, long long p) {
		Mint ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1) ans *= a;
		return ans;
	}
	friend Mint inv(const Mint& a) {
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}
	Mint operator-() const { return Mint(-v); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	friend Mint operator+(Mint a, const Mint& b) { return a += b; }
	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
};

using mi = Mint<1000000007, 5>;

struct Frac {
	long long n, d;
	Frac(long long _n, long long _d) {
		n = _n, d = _d;
		long long g = std::__gcd(n, d);
		n /= g, d /= g;
		if (d < 0) n *= -1, d *= -1;
	}
	long double eval() { return (long double)n / d; }
	Frac(long long _n) : Frac(_n, 1) {}
	Frac() : Frac(0) {}
	friend Frac abs(Frac F) { return Frac(abs(F.n), F.d); }
	friend bool operator<(const Frac& l, const Frac& r) { return l.n * r.d < r.n * l.d; }
	friend bool operator<=(const Frac& l, const Frac& r) { return l.n * r.d <= r.n * l.d; }
	friend bool operator>(const Frac& l, const Frac& r) { return l.n * r.d > r.n * l.d; }
	friend bool operator>=(const Frac& l, const Frac& r) { return l.n * r.d >= r.n * l.d; }
	friend bool operator==(const Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d; }
	friend bool operator!=(const Frac& l, const Frac& r) { return !(l == r); }
	Frac operator-() const { return Frac(-n, d); }
	friend Frac operator+(const Frac& l, const Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }
	friend Frac operator-(const Frac& l, const Frac& r) { return Frac(l.n * r.d - r.n * l.d, l.d * r.d); }
	friend Frac operator*(const Frac& l, const Frac& r) { return Frac(l.n * r.n, l.d * r.d); }
	friend Frac operator*(const Frac& l, long long r) { return l * Frac(r, 1); }
	friend Frac operator*(long long r, const Frac& l) { return l * r; }
	friend Frac operator/(const Frac& l, const Frac& r) { return l * Frac(r.d, r.n); }
	friend Frac operator/(const Frac& l, const long long& r) { return l / Frac(r, 1); }
	friend Frac operator/(const long long& l, const Frac& r) { return Frac(l, 1) / r; }
	friend Frac& operator+=(Frac& l, const Frac& r) { return l = l + r; }
	friend Frac& operator-=(Frac& l, const Frac& r) { return l = l - r; }
	template <class T>
	friend Frac& operator*=(Frac& l, const T& r) { return l = l * r; }
	template <class T>
	friend Frac& operator/=(Frac& l, const T& r) { return l = l / r; }
	friend std::ostream& operator<<(std::ostream& os, const Frac& a) { return os << a.n << "/" << a.d; }
};

const int N = 1e6 + 5;
const mi i2 = mi(1) / 2;

mi fact[N], ifact[N], po[N];

void pcp() {
	fact[0] = 1;
	po[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i;
		po[i] = po[i - 1] * 2;
	}
	ifact[N - 1] = 1 / fact[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		ifact[i] = ifact[i + 1] * (i + 1);
	}
}

mi C(int x, int y) {
	if (x < y || y < 0) {
		return 0;
	} else {
		return fact[x] * ifact[y] * ifact[x - y];
	}
}

mi solve(int n, int k) {
	mi res = C(n, k);
	for (int i = 1; i <= n; ++i) {
		mi mult;
		if (i == 1) {
			mult = i2;
		} else {
			mult = po[i - 2];
		}
		res += (i + 3) * C(n - i, k - i) * mult;
	}
	return res;
}

void solve_case(int tc = 0) {
	int n, m, k;
	cin >> n >> m >> k;
	mi ans = k * solve(n, m - 1);
	ans /= po[n - 1];
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	pcp();
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}