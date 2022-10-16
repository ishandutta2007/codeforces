#include <bits/stdc++.h>

using namespace std;

// 5 is a root of both mods
const int MOD = 998244353;

typedef std::decay<decltype(MOD)>::type mod_t; 
struct mi {
	mod_t val;
	explicit operator mod_t() const { return val; }
	explicit operator bool() const { return val != 0; }
	mi() { val = 0; }
	mi(const long long& v) {
		val = (-MOD <= v && v < MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
	friend std::istream& operator>>(std::istream& in, mi& a) { 
		long long x; std::cin >> x; a = mi(x); return in; }
	friend std::ostream& operator<<(std::ostream& os, const mi& a) { return os << a.val; }
	friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }    
	friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
	friend bool operator>(const mi& a, const mi& b) { return a.val > b.val; }
	friend bool operator<=(const mi& a, const mi& b) { return a.val <= b.val; }
	friend bool operator>=(const mi& a, const mi& b) { return a.val >= b.val; }
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) { val = (long long)val * m.val % MOD;
		return *this; }
	friend mi pow(mi a, long long p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; }
	friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

template <class T> struct Affine {
	T a, b;
	
	constexpr Affine() : a(1), b(0) {}
	constexpr Affine(T _a, T _b) : a(_a), b(_b) {}
	constexpr Affine(T _b) : a(0), b(_b) {}

	T operator()(T x) { return a * x + b; }
	
	Affine operator-() { return Affine(-a, -b); }
	
	friend Affine operator*(const Affine& l, const Affine& r) {
		return Affine(l.a * r.a, l.b * r.a + r.b); }
	friend Affine operator-(const Affine& l, const Affine& r) { return Affine(l.a - r.a, l.b - r.b); }
	friend Affine operator+(const Affine& l, const Affine& r) { return Affine(l.a + r.a, l.b + r.b); }
	
	friend Affine operator+(const Affine& l, const T& r) { return Affine(l.a, l.b + r); }
	friend Affine operator-(const Affine& l, const T& r) { return Affine(l.a, l.b - r); }
	friend Affine operator*(const Affine& l, const T& r) { return Affine(l.a * r, l.b * r); }
	friend Affine operator/(const Affine& l, const T& r) { return Affine(l.a / r, l.b / r); }

	friend Affine operator+(const T& l, Affine& r) { return r + l; }
	friend Affine operator-(const T& l, Affine& r) { return -r + l; }
	friend Affine operator*(const T& l, Affine& r) { return r * l; }
	
	friend Affine& operator+=(Affine& l, const Affine& r) { return l = l + r; }
	friend Affine& operator-=(Affine& l, const Affine& r) { return l = l - r; }
	friend Affine& operator*=(Affine& l, const Affine& r) { return l = l * r; }

	friend Affine& operator+=(Affine& l, const T& r) { return l = l + r; }
	friend Affine& operator-=(Affine& l, const T& r) { return l = l - r; }
	friend Affine& operator*=(Affine& l, const T& r) { return l = l * r; }

	bool operator==(const Affine& r) const { return a == r.a && b == r.b; }
	bool operator!=(const Affine& r) const { return a != r.a || b != r.b; }

	friend ostream& operator<<(ostream& os, const Affine& r) {
		os << "( " << r.a << ", " << r.b << " )";
		return os;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int s = accumulate(a.begin(), a.end(), 0);
	vector<Affine<mi>> dp(s + 1);
	dp[0] = {1, 0};
	dp[1] = dp[0] - (n - 1);
	for (int i = 1; i < s; ++i) {
		dp[i + 1] = (s * dp[i] - s - i * dp[i - 1] - mi(s - i) * (n - 2) / (n - 1) * dp[i]) * (n - 1) / (s - i);
	}
	vector<mi> e(s + 1);
	e[0] = -dp[s].b / dp[s].a;
	for (int i = 1; i <= s; ++i) {
		e[i] = dp[i](e[0]);
	}
	mi sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += e[a[i]];
	}
	mi ans = (n * sum - mi(n) * (n - 1) * e[0]) / n / n;
	cout << ans << '\n';
	return 0;
}