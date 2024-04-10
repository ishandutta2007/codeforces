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

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		auto get = [&](char c) {
			int ret =  c == '?' ? -1 : c - '0';
			if (ret != -1 && i & 1) {
				ret ^= 1;
			}
			return ret;
		};
		a[i] = get(s[i]);
		b[i] = get(t[i]);
	}
	vector<int> ra(n, -1), rb(n, -1);
	vector<bool> ga(n, true), gb(n, true);
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < i; ++k) {
			if (a[k] == 1) {
				ra[i] = k;
			}
			if (b[k] == 1) {
				rb[i] = k;
			}
		}
		for (int k = i + 1; k < n; ++k) {
			if (a[k] == 1) {
				ga[i] = false;
			}
			if (b[k] == 1) {
				gb[i] = false;
			}
		}
	}
	vector<vector<array<mi, 2>>> dp(n, vector<array<mi, 2>>(n));
	vector<vector<mi>> sum(n, vector<mi>(n)), way(n, vector<mi>(n));
	auto get = [&](int xl, int xr, int yl, int yr, vector<vector<mi>>& a) {
		xl = max(xl, 0);
		yl = max(yl, 0);
		xr = min(xr, n - 1);
		yr = min(yr, n - 1);
		mi ret = 0;
		if (xl <= xr && yl <= yr) {
			ret = a[xr][yr];
			ret -= (xl ? a[xl - 1][yr] : 0);
			ret -= (yl ? a[xr][yl - 1] : 0);
			ret += (xl && yl ? a[xl - 1][yl - 1] : 0);
		}
		return ret;
	};
	mi ans = 0;
	for (int i = 0; i < n; ++i) {
		mi rsum = 0;
		mi rway = 0;
		for (int j = 0; j < n; ++j) {
			if (a[i] != 0 && b[j] != 0) {
				if (ra[i] == -1 && rb[j] == -1) {
					dp[i][j] = {abs(i - j), 1};
				}
				mi tot = get(ra[i], i - 1, rb[j], j - 1, sum);
				mi num = get(ra[i], i - 1, rb[j], j - 1, way);
				dp[i][j][0] += tot + num * abs(i - j);
				dp[i][j][1] += num;
				if (ga[i] && gb[j]) {
					ans += dp[i][j][0];
				}
			}
			rsum += dp[i][j][0];
			rway += dp[i][j][1];
			sum[i][j] = rsum + (i ? sum[i - 1][j] : 0);
			way[i][j] = rway + (i ? way[i - 1][j] : 0);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}