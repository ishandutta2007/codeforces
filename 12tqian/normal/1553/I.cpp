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
	friend istream& operator >> (istream& in, Mint& a) { 
		long long x; cin >> x; a = Mint(x); return in; }
	friend ostream& operator << (ostream& os, const Mint& a) { return os << a.v; }
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

namespace FFT {

template <class T> void fft(vector<T>& A, bool inv = 0) {
	int n = (int)A.size();
	assert((T::mod - 1) % n == 0);
	vector<T> B(n);
	for (int b = n / 2; b; b /= 2, A.swap(B)) {
		T w = pow(T::rt(), (T::mod - 1) / n * b);
		T m = 1;
		for (int i = 0; i < n; i += b * 2, m *= w)
			for (int j = 0; j < b; j++) {
				T u = A[i + j];
				T v = A[i + j + b] * m;
				B[i / 2 + j] = u + v;
				B[i / 2 + j + n / 2] = u - v;
			}
	}
	if (inv) {
		reverse(1 + A.begin(), A.end());
		T z = T(1) / T(n);
		for (auto & t : A) 
			t *= z;
	}
}

template <class T> vector<T> multiply(vector<T> A, vector<T> B) {
	int sa = (int)A.size();
	int sb = (int)B.size();
	if (!min(sa, sb))
		return {};
	int s = sa + sb - 1;
	int n = 1;
	for (; n < s; n *= 2);
	bool eq = A == B;
	A.resize(n);
	fft(A);
	if (eq) 
		B = A;
	else 
		B.resize(n), fft(B);
	for (int i = 0; i < n; i++)
		A[i] *= B[i];
	fft(A, 1);
	A.resize(s);
	return A;
}

template <class T> vector<T> operator*(const vector<T>& a, const vector<T>& b) {
	auto c = multiply(a, b);
	return c;
}

template <class T> vector<T> operator+(const vector<T>& a, const vector<T>& b) {
	vector<T> c = a;
	c.resize(max(a.size(), b.size()));
	for (int i = 0; i < b.size(); ++i) {
		c[i] += b[i];
	}
	return c;
}

template <class M, class T> vector<M> multiply_mod(vector<T> x, vector<T> y) {
	auto convert = [](const vector<T>& v) {
		vector<M> w((int)v.size());
		for (int i =  0; i < (int)v.size(); i++)
			w[i] = (int) v[i];
		return w;
	};
	return multiply(convert(x), convert(y));
}

template <class T> vector<T> general_multiply(const vector<T>& A, const vector<T>& B) { 
	// arbitrary modulus
	using m0 = Mint<(119 << 23) + 1, 62>; 
	using m1 = Mint<(5 << 25) + 1, 62>;
	using m2 = Mint<(7 << 26) + 1, 62>;
	auto c0 = multiply_mod<m0>(A, B);
	auto c1 = multiply_mod<m1>(A, B);
	auto c2 = multiply_mod<m2>(A, B);
	int n = (int)c0.size();
	vector<T> res(n);
	m1 r01 = 1 / m1(m0::mod);
	m2 r02 = 1 / m2(m0::mod);
	m2 r12 = 1 / m2(m1::mod);
	for (int i = 0; i < n; i++) {
		int a = c0[i].v;
		int b = ((c1[i] - a) * r01).v;
		int c = (((c2[i] - a) * r02 - b) * r12).v;
		res[i] = (T(c) * m1::mod + b) * m0::mod + a;
	}
	return res;
}

} // namespace FFT

using namespace FFT;

using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	auto fail = []() {
		cout << 0 << '\n';
		exit(0);	
	};
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> blocks;
	while (!a.empty()) {
		int x = a.back();
		if (a.size() < x) {
			fail();
		}
		blocks.push_back(x == 1);
		for (int i = 0; i < x; ++i) {
			if (a.back() != x) {
				fail();
			}
			a.pop_back();
		}
	}
	reverse(blocks.begin(), blocks.end());
	int sz = blocks.size();
	function<vector<vector<mi>>(int, int)> solve = [&](int l, int r) {
		vector<vector<mi>> res(4);
		if (r - l + 1 == 1) {
			res[0] = vector<mi>{1};
			res[1] = vector<mi>{0, 2};
			res[2] = vector<mi>{1};
			if (blocks[l]) {
				res[3] = vector<mi>{0, 1};
			} else {
				res[3] = vector<mi>{0, 2};
			}
			return res;
		}
		int m = (l + r) >> 1;
		auto x = solve(l, m);
		auto y = solve(m + 1, r);
		res[0] = x[0] * y[0] + x[1] * y[2];
		res[1] = x[0] * y[1] + x[1] * y[3];
		res[2] = x[2] * y[0] + x[3] * y[2];
		res[3] = x[3] * y[3] + x[2] * y[1];
		return res;
	};
	auto res = solve(0, sz - 1)[3];
	mi ans = 0;
	mi run = 1;
	for (int i = 1; i < res.size(); ++i) {
		run *= i;
		ans += res[i] * run * (i % 2 == res.size() % 2 ? -1 : 1);
	}
	cout << ans << '\n';
	return 0;
}