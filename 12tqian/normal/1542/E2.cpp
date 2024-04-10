#include <bits/stdc++.h> 

using namespace std;

template <class T> class range_vector : public std::vector<T> {
public:
	int min_index;

	range_vector() : std::vector<T>(), min_index(0) {}

	range_vector(int _min_index, int _max_index, T&& values = T())
		: std::vector<T>(_max_index - _min_index + 1, values), min_index(_min_index) {
		assert(_min_index <= _max_index + 1);
	}
	
	range_vector(int _max_index, T&& values = T())
		: std::vector<T>(_max_index + 1, values), min_index(0) {
		assert(0 <= _max_index + 1);
	}
	
	T& operator[](int i) { std::vector<T>& self = *this; return self[i - min_index]; }
};

struct FastMod {
	unsigned long long b, m;
	FastMod(unsigned long long b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}
	unsigned long long reduce(unsigned long long a) {
		unsigned long long q = (unsigned long long)((__uint128_t(m) * a) >> 64);
		unsigned long long r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};

FastMod F(2);

int MOD = 2;

typedef decay<decltype(MOD)>::type mod_t;

struct mi {
	mod_t val;
	explicit operator mod_t() const { return val; }
	mi() { val = 0; }
	mi(const long long& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
	friend istream& operator>>(istream& in, mi& a) { 
		long long x; cin >> x; a = mi(x); return in; }
	friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
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
	mi& operator*=(const mi& m) { 
		val = (long long)val * m.val % MOD;
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

const int N = 505;
const int I = N * (N - 1) / 2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; 
	cin >> n >> MOD;
	F = FastMod(MOD);
	int c2 = n * (n - 1) / 2;
	vector<vector<mi>> C(n + 1, vector<mi>(n + 1));
	vector<mi> fact(n + 1);
	vector<vector<mi>> dp(n, vector<mi>(c2 + 1));
	range_vector<mi> diff, pdiff, p1, p2, use;
	C[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			C[i][j] = C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);
		}
	}
	mi ans = 0;
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	p1 = p2 = diff = pdiff = range_vector<mi>(-c2 - 1, c2 + 1, 0);
	use.resize(c2 + 1);
	for (int i = 4; i <= n; ++i) {
		int m = i - 1;
		int inv = m * (m - 1) / 2;
		if (m == 3) {
			function<mi(int, int)> solve = [&](int n, int k) {
				vector<int> a(n);
				iota(a.begin(), a.end(), 0);
				mi res = 0;
				do {
					int cnt = 0;
					for (int i = 0; i < n; ++i) {
						for (int j = i + 1; j < n; ++j) {
							if (a[i] > a[j]) {
								++cnt;
							}
						}
					}
					if (cnt == k) {
						res += 1;
					}
				} while (next_permutation(a.begin(), a.end()));
				return res;
			};
			for (int jj = 0; jj <= inv; ++jj) {
				for (int kk = 0; kk <= inv; ++kk) {
					diff[kk - jj] += solve(m, jj) * solve(m, kk);
				}
			}
		} else {
			for (int j = -inv - 1; j <= inv; ++j) {
				p1[j] = p2[j] = 0;
			}
			for (int ii = -inv; ii <= inv; ++ii) {
				p1[ii] = p1[ii - 1] + pdiff[ii];
				p2[ii] = p2[ii - 1] + ii * pdiff[ii];		
			}
			for (int ii = -inv; ii <= inv; ++ii) {
				int st = max(ii - m, -inv);
				int coeff = m - (ii - st);
				diff[ii] = p2[ii] - p2[st - 1] + (coeff - st) * (p1[ii] - p1[st - 1]);
				int ed = min(ii + m, inv);
				coeff = m - 1;
				diff[ii] += p2[ii] - p2[ed] + (coeff + (ii + 1)) * (p1[ed] - p1[ii]);
			}
		}
		for (int j = -inv; j <= inv; ++j) {
			pdiff[j] = diff[j];
		}
		for (int j = 0; j <= inv; ++j) {
			use[j] = diff[j];
		}
		for (int j = max(inv, i); j >= 1; --j) {
			use[j - 1] += use[j];
		}
		for (int j = 1; j <= i; ++j) {
			for (int k = j + 1; k <= i; ++k) {
				mi ways = C[n][n - i] * fact[n - i];
				mi res = ways * use[k - j + 1];
				ans += res;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}