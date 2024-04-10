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

using mi = Mint<998244353, 5>;

template <int SZ> struct Sieve {
	int spf[SZ];
	
	Sieve() {
		spf[1] = 1;
		for (int i = 2; i < SZ; i++) 
			spf[i] = i;
		for (int i = 4; i < SZ; i += 2) 
			spf[i] = 2;
		for (int i = 3; i * i < SZ; i++) 
			if (spf[i] == i) 
				for (int j = i * i; j < SZ; j += i) 
					if (spf[j] == j) 
						spf[j] = i;
	}

	std::vector<std::pair<int, int>> factor(int x) {
		std::vector<std::pair<int, int>> ret;
		while (x != 1) {
			if ((int)ret.size() == 0) 
				ret.emplace_back(spf[x], 1);
			else {
				if (ret.back().first == spf[x]) 
					ret.back().second++;
				else 
					ret.emplace_back(spf[x], 1);
			}
			x /= spf[x];
		}
		return ret;
	}
};

struct Frac {
	long long n, d;
	Frac(long long _n, long long _d) {
		n = _n, d = _d;
		long long g = std::__gcd(n, d); n /= g, d /= g;
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
	template <class T> friend Frac& operator*=(Frac& l, const T& r) { return l = l * r; }
	template <class T> friend Frac& operator/=(Frac& l, const T& r) { return l = l / r; }
	friend std::ostream& operator<<(std::ostream& os, const Frac& a) { return os << a.n << "/" << a.d; }
};

const int N = 2e5 + 5;

Sieve<N> sieve;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<vector<array<int, 3>>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		--u, --v;
		if (u > v) {
			swap(u, v);
			swap(x, y);
		}
		g[u].push_back({v, x, y});
		g[v].push_back({u, y, x});
	}
	map<int, int> facts;
	map<int, int> high;
	mi sum = 0;
	mi cur = 1;
	function<void(int, int)> dfs = [&](int u, int p) {
		sum += cur;
		for (auto [v, x, y] : g[u]) {
			if (v == p) {
				continue;
			}
			auto add = [&](int z, int mult = 1) {
				auto f = sieve.factor(z);
				for (auto [p, e] : f) {
					facts[p] += e * mult;
					int use = facts[p];
					if (use < 0) {
						if (high.find(p) == high.end()) {
							high[p] = -use;
						} else {
							high[p] = max(high[p], -use);
						}
					}
				}
			};
			add(y);
			cur *= y;
			add(x, -1);
			cur /= x;
			dfs(v, u);
			add(x);
			cur *= x;
			add(y, -1);
			cur /= y;
		}
	};
	dfs(0, -1);
	mi ans = 1;
	for (auto [p, e] : high) {
		ans *= pow(mi(p), e);
	}	
	ans *= sum;	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}