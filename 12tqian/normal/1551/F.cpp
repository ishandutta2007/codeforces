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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		int n, k;
		cin >> n >> k;
		vector<mi> fact(n + 1);
		vector<mi> ifact(n + 1);
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		ifact[n] = 1 / fact[n];
		for (int i = n - 1; i >= 0; --i) {
			ifact[i] = ifact[i + 1] * (i + 1);
		}
		auto C = [&](int x, int y) {
		};
		vector<vector<int>> g(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (k == 2) {
			cout << n * (n - 1) / 2 << '\n';
			continue;
		}
		mi ans = 0;
		for (int r = 0; r < n; ++r) {
			vector<vector<int>> store(n);
			vector<int> dep(n);
			function<void(int, int, int)> dfs = [&](int u, int p, int s) {
				++store[dep[u]].back();
				for (int v : g[u]) {
					if (v != p) {
						dep[v] = dep[u] + 1;
						dfs(v, u, s);
					}
				}
			};
			for (int u : g[r]) {
				for (int i = 0; i < n; ++i) {
					store[i].push_back(0);
				}
				dep[u] = 1;
				dfs(u, r, u);
			}
			auto comb = [&](vector<mi> a, vector<mi> b) {
				vector<mi> res(a.size() + b.size() - 1);
				for (int i = 0; i < a.size(); ++i) {
					for (int j = 0; j < b.size(); ++j) {
						res[i + j] += a[i] * b[j];
					}
				}
				return res;
			};
			for (int d = 0; d < n; ++d) {
				vector<mi> res = {1};
				for (int x : store[d]) {
					res = comb(res, vector<mi>{1, x});
				}
				if (res.size() > k) {
					ans += res[k];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}