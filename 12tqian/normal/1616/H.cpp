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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const int L = 30;
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<mi> po(n + 1);
	po[0] = 1;
	for (int i = 1; i <= n; ++i) {
		po[i] = po[i - 1] * 2;
	}
	auto msb = [](int x) {
		if (x == 0) {
			return -1;
		}
		return 31 - __builtin_clz(x);
	};
	auto split = [](vector<int> v, int t) {
		vector<int> v0, v1;
		for (int x : v) {
			if (x & (1 << t)) {
				v1.push_back(x);
			} else {
				v0.push_back(x);
			}
		}
		return make_pair(v0, v1);
	};
	auto divide = [](vector<int> v, int mod) {
		map<int, vector<int>> ret;
		for (int x : v) {
			ret[x / mod].push_back(x);
		}
		return ret;
	};
	auto solve2 = [&](auto& self, vector<int> f, vector<int> g, int t, int x) -> mi {
		mi ret = 0;
		int n = (int)f.size();
		int m = (int)g.size();
		for (int i = 0; i < n; ++i) {
			f[i] %= 1 << (t + 1);
		}
		for (int i = 0; i < m; ++i) {
			g[i] %= 1 << (t + 1);
		}
		x %= 1 << (t + 1);
		int top = msb(x);
		auto fclasses = divide(f, 1 << (top + 1)), gclasses = divide(g, 1 << (top + 1));
		for (auto z : fclasses) {
			int leading = z.first;
			if (gclasses.find(leading) != gclasses.end()) {
				auto u = z.second;
				auto v = gclasses[leading];
				if (top == -1) {
					ret += (po[(int)u.size()] - 1) * (po[(int)v.size()] - 1);
				} else {
					vector<int> u0, u1, v0, v1;
					tie(u0, u1) = split(u, top);
					tie(v0, v1) = split(v, top);
					ret += (po[(int)u0.size()] - 1) * (po[(int)v0.size()] - 1);
					ret += (po[(int)u1.size()] - 1) * (po[(int)v1.size()] - 1);
					mi r1, r2;
					if (top <= 0) {
						r1 = (po[(int)u0.size()] - 1) * (po[(int)v1.size()] - 1);
						r2 = (po[(int)u1.size()] - 1) * (po[(int)v0.size()] - 1);
					} else {
						r1 = self(self, u0, v1, top - 1, x);
						r2 = self(self, u1, v0, top - 1, x);
					}
					ret += r1 * r2;
					ret += r1 * (po[(int)u1.size()] + po[(int)v0.size()] - 1);
					ret += (po[(int)u0.size()] + po[(int)v1.size()] - 1) * r2;
				}
			}
		}
		return ret;
	};
	auto solve1 = [&](vector<int> f, int t, int x) { 
		mi ret = 0;
		int n = (int)f.size();
		for (int i = 0; i < n; ++i) {
			f[i] %= 1 << (t + 1);
		}
		x %= 1 << (t + 1);
		int top = msb(x);
		auto classes = divide(f, 1 << (top + 1));
		for (auto [leading, v] : classes) {
			vector<int> v0, v1;
			tie(v0, v1) = split(v, top);
			ret += po[(int)v0.size()] - 1;
			ret += po[(int)v1.size()] - 1;
			if (top >= 1) {
				ret += solve2(solve2, v0, v1, top - 1, x);
			}
		}
		return ret;
	};
	mi ans = solve1(a, L - 1, x);
	cout << ans << '\n';
	return 0;
}