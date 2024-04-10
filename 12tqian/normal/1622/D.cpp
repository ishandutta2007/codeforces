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

void solve_case(int tc = 0) {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
	}
	vector<mi> fact(n + 1), ifact(n + 1);
	fact[0] = 1; 
	for (int i = 1; i <= n; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	ifact[n] = 1 / fact[n];
	for (int i = n - 1; i >= 0; --i) {
		ifact[i] = ifact[i + 1] * (i + 1);
	}
	auto C = [&](int x, int y) {
		if (x < y) {
			return mi(0);
		} else {
			return fact[x] * ifact[y] * ifact[x - y];	
		}
	};
	mi ans = 0;
	if (k == 0 || accumulate(a.begin(), a.end(), 0) < k) {
		ans = 1;
	} else {
		vector<int> left(n);
		vector<int> right(n);
		for (int i = 0; i < n; ++i) {
			int j = i;
			while (j && a[j - 1] == 0) {
				--j;
			}
			left[i] = j;
			j = i;
			while (j != n - 1 && a[j + 1] == 0) {
				++j;
			}
			right[i] = j;
		}
		vector<int> ones;
		for (int i = 0; i < n; ++i) {
			if (a[i]) {
				ones.push_back(i);
			}
		}
		int sz = (int)ones.size();
		for (int l = 0; l < sz; ++l) {
			for (int r = l + 1; r < sz; ++r){ 
				if (r - l + 1 <= k) {
					int gap = right[ones[r]] - left[ones[l]] + 1;
					int x = ones[l] - left[ones[l]];
					int y = right[ones[r]] - ones[r];
					int bet = r - l + 1;
					ans += C(gap, bet) - C(gap - x - 1, bet - 1) - C(gap - y - 1, bet - 1) + C(gap - x - y - 2, bet - 2);
				}
			}
			int gap = right[ones[l]] - left[ones[l]] + 1;
			ans += gap - 1;
		}
		ans += 1;
	} 
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}