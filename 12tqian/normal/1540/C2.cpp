#include <bits/stdc++.h>

using namespace std;

// 5 is a root of both mods
template <int MOD, int RT> struct Mint {
	static const int mod = MOD;
	static constexpr Mint rt() { return RT; } // primitive root for FFT
	int v; 
	explicit operator int() const { return v; } // explicit -> don't silently convert to int
	Mint() { v = 0; }
	Mint(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }
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
		v = (long long) v * m.v % MOD; return *this; }
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

const int N = 105;
const int A = 1e5;

mi dp[N][N * N];
mi res[2 * A];
bool vis[2 * A];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> c(n + 1);
	mi prod = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		prod *= c[i] + 1;
	}
	vector<int> b(n);
	for (int i = 1; i <= n - 1; ++i) {
		cin >> b[i];
	}
	vector<int> p = b;
	for (int t = 0; t < 2; ++t) {
		for (int i = 1; i <= n - 1; ++i) {
			p[i] += p[i - 1];
		}
	}
	auto solve = [&](int x) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N * N; ++j) {
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		vector<mi> prefix(N * N);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < N * N; ++j) {
				prefix[j] = (j ? prefix[j - 1] : 0) + dp[i - 1][j];
			}
			for (int j = 0; j < N * N; ++j) {
				if (j < i * x + p[i - 1]) {
					continue;
				}
				int l = max(j - c[i], 0);
				int r = j;
				dp[i][j] = prefix[r] - (l ? prefix[l - 1] : 0);
			}
		}
		mi ans = 0;
		for (int i = 0; i < N * N; ++i) {
			ans += dp[n][i];
		}
		return ans;
	};
	map<int, mi> res;
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		auto& ans = res[x + A];
		if (vis[x + A]) {
			cout << ans << '\n';
		} else {
			vis[x + A] = true;
			if (N * N < x * n + p[n - 1]) {
				ans = 0;
			} else {
				bool ok = true;
				for (int i = 1; i <= n; ++i) {
					if (i * x + p[i - 1] >= 0) {
						ok = false;
					}
				}
				if (ok) {
					ans = prod;
				} else {
					ans = solve(x);
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}