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

namespace NTT {

int bsf(unsigned int x) { return __builtin_ctz(x); }
int bsf(unsigned long long x) { return __builtin_ctzll(x); }

template <class Mint> void nft(bool type, std::vector<Mint>& a) {
	int n = int(a.size()), s = 0;
	while ((1 << s) < n) s++;
	assert(1 << s == n);
	static std::vector<Mint> ep, iep;
	while (int(ep.size()) <= s) {
		ep.push_back(pow(Mint::rt(), Mint(-1).v / (1 << ep.size())));
		iep.push_back(1 / ep.back());
	}
	std::vector<Mint> b(n);
	for (int i = 1; i <= s; i++) {
		int w = 1 << (s - i);
		Mint base = type ? iep[i] : ep[i], now = 1;
		for (int y = 0; y < n / 2; y += w) {
			for (int x = 0; x < w; x++) {
				auto l = a[y << 1 | x];
				auto r = now * a[y << 1 | x | w];
				b[y | x] = l + r;
				b[y | x | n >> 1] = l - r;
			}
			now *= base;
		}
		swap(a, b);
	}
}

template <class Mint> std::vector<Mint> multiply_nft(const std::vector<Mint>& a, const std::vector<Mint>& b) {
	int n = int(a.size()), m = int(b.size());
	if (!n || !m) return {};
	if (std::min(n, m) <= 8) {
		std::vector<Mint> ans(n + m - 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];
		return ans;
	}
	int lg = 0;
	while ((1 << lg) < n + m - 1) lg++;
	int z = 1 << lg;
	auto a2 = a, b2 = b;
	a2.resize(z);
	b2.resize(z);
	nft(false, a2);
	nft(false, b2);
	for (int i = 0; i < z; i++) a2[i] *= b2[i];
	nft(true, a2);
	a2.resize(n + m - 1);
	Mint iz = 1 / Mint(z);
	for (int i = 0; i < n + m - 1; i++) a2[i] *= iz;
	return a2;
}

// Cooley-Tukey: input -> butterfly -> bit reversing -> output 
// bit reversing
template <class Mint> void butterfly(bool type, std::vector<Mint>& a) {
	int n = int(a.size()), h = 0;
	while ((1 << h) < n) h++;
	assert(1 << h == n);
	if (n == 1) return;
	static std::vector<Mint> snow, sinow;
	if (snow.empty()) {
		Mint sep = Mint(1), siep = Mint(1);
		unsigned int mod = Mint(-1).v;
		unsigned int di = 4;
		while (mod % di == 0) {
			Mint ep = pow(Mint::rt(), mod / di);
			Mint iep = 1 / ep;
			snow.push_back(siep * ep);
			sinow.push_back(sep * iep);
			sep *= ep;
			siep *= iep;
			di *= 2;
		}
	}
	if (!type) {
		// fft
		for (int ph = 1; ph <= h; ph++) {
			int w = 1 << (ph - 1), p = 1 << (h - ph);
			Mint now = Mint(1);
			for (int s = 0; s < w; s++) {
				int offset = s << (h - ph + 1);
				for (int i = 0; i < p; i++) {
					auto l = a[i + offset];
					auto r = a[i + offset + p] * now;
					a[i + offset] = l + r;
					a[i + offset + p] = l - r;
				}
				int u = bsf(~(unsigned int)(s));
				now *= snow[u];
			}
		}
	} else {
		// ifft
		for (int ph = h; ph >= 1; ph--) {
			int w = 1 << (ph - 1), p = 1 << (h - ph);
			Mint inow = Mint(1);
			for (int s = 0; s < w; s++) {
				int offset = s << (h - ph + 1);
				for (int i = 0; i < p; i++) {
					auto l = a[i + offset];
					auto r = a[i + offset + p];
					a[i + offset] = l + r;
					a[i + offset + p] = (l - r) * inow;
				}
				int u = bsf(~(unsigned int)(s));
				inow *= sinow[u];
			}
		}
	}
}

template <class Mint> std::vector<Mint> multiply(const std::vector<Mint>& a, const std::vector<Mint>& b) {
	int n = int(a.size()), m = int(b.size());
	if (!n || !m) return {};
	if (std::min(n, m) < 8) {
		std::vector<Mint> ans(n + m - 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];
		return ans;
	}
	int lg = 0;
	while ((1 << lg) < n + m - 1) lg++;
	int z = 1 << lg;
	auto a2 = a;
	a2.resize(z);
	butterfly(false, a2);
	if (a == b) {
		for (int i = 0; i < z; i++) a2[i] *= a2[i];
	} else {
		auto b2 = b;
		b2.resize(z);
		butterfly(false, b2);
		for (int i = 0; i < z; i++) a2[i] *= b2[i];
	}
	butterfly(true, a2);
	a2.resize(n + m - 1);
	Mint iz = 1 / Mint(z);
	for (int i = 0; i < n + m - 1; i++) a2[i] *= iz;
	return a2;
}

}

template <class D> struct Poly : std::vector<D> {
	using std::vector<D>::vector;

	static const int SMALL_DEGREE = 60;

	Poly(const std::vector<D>& _v = {}) { 
		for (int i = 0; i < (int)_v.size(); ++i) {
			this->push_back(_v[i]);
		}
		shrink(); 
	}

	void shrink() {
		while (this->size() && !this->back()) this->pop_back();
	}

	D freq(int p) const { return (p < (int)this->size()) ? (*this)[p] : D(0); }
	
	Poly operator+(const Poly& r) const {
		int n = std::max(this->size(), r.size());
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = freq(i) + r.freq(i);
		return res;
	}

	Poly operator-(const Poly& r) const {
		int n = std::max(this->size(), r.size());
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = freq(i) - r.freq(i);
		return res;
	}

	bool small(const Poly& r) const { return std::min((int)this->size(), (int)r.size()) <= SMALL_DEGREE; }

	Poly operator*(const Poly& r) const { 
		if (!std::min((int)this->size(), (int)r.size())) return {};
		if (small(r)){
			Poly res((int)this->size() + (int)r.size() - 1);
			for (int i = 0; i < (int)this->size(); ++i) {
				for (int j = 0; j < (int)r.size(); ++j) {
					res[i + j] += (*this)[i] * r[j];
				}
			}
			return res;
		} else {
			return {NTT::multiply((*this), r)}; 
		}
	}
	
	Poly operator*(const D& r) const {
		int n = this->size();
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = (*this)[i] * r;
		return res;
	}

	Poly operator/(const D &r) const{ return *this * (1 / r); }


	Poly& operator+=(const D& r) { 
		if (this->empty()) this->resize(1);
		(*this)[0] += r;
		return *this;
	}

	Poly& operator-=(const D& r) {
		(*this)[0] -= r;
		return *this;
	}
	
	Poly operator/(const Poly& r) const {
		if (this->size() < r.size()) return {};
		if (small(r)) {
			Poly a = (*this);
			Poly b = r;
			a.shrink(), b.shrink();
			D lst = b.back();
			D ilst = 1 / lst;
			for (auto& t : a) t *= ilst;
			for (auto& t : b) t *= ilst;
			Poly q(std::max((int)a.size() - (int)b.size() + 1, 0));
			for (int diff; (diff = (int)a.size() - (int)b.size()) >= 0; a.shrink()) {
				q[diff] = a.back();
				for (int i = 0; i < (int)b.size(); ++i) {
					a[i + diff] -= q[diff] * b[i];
				}
			}
			return q;
		} else {
			int n = (int)this->size() - r.size() + 1;
			return (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
		}
	}
	
	Poly operator%(const Poly& r) const { return *this - *this / r * r; }
	
	Poly operator<<(int s) const {
		std::vector<D> res(this->size() + s);
		for (int i = 0; i < (int)this->size(); i++) res[i + s] = (*this)[i];
		return res;
	}

	Poly operator>>(int s) const {
		if ((int)this->size() <= s) return Poly();
		std::vector<D> res(this->size() - s);
		for (int i = 0; i < (int)this->size() - s; i++) res[i] = (*this)[i + s];
		return res;
	}
	
	Poly operator+(const D& r) { return Poly(*this) += r; }
	Poly operator-(const D& r) { return Poly(*this) -= r; }
	Poly operator-() const { return (*this) * -1; } 
	Poly& operator+=(const Poly& r) { return *this = *this + r; }
	Poly& operator-=(const Poly& r) { return *this = *this - r; }
	Poly& operator*=(const Poly& r) { return *this = *this * r; }
	Poly& operator*=(const D& r) { return *this = *this * r; }
	Poly& operator/=(const Poly& r) { return *this = *this / r; }
	Poly& operator/=(const D &r) { return *this = *this / r; }
	Poly& operator%=(const Poly& r) { return *this = *this % r; }
	Poly& operator<<=(const size_t& n) { return *this = *this << n; }
	Poly& operator>>=(const size_t& n) { return *this = *this >> n; }
	friend Poly operator*(D const& l, Poly r) { return r *= l; }
	friend Poly operator/(D const& l, Poly r) { return l * r.inv(); }
	friend Poly operator+(D const& l, Poly r) { return r += l; }
	friend Poly operator-(D const& l, Poly r) { return -r + l; }

	Poly pre(int le) const { return Poly(this->begin(), this->begin() + std::min((int)this->size(), le)); }
	
	Poly rev(int n = -1) const {
		Poly res = *this;
		if (n != -1) res.resize(n);
		reverse(res.begin(), res.end());
		return res;
	}
	
	Poly diff() const {
		std::vector<D> res(std::max(0, (int)this->size() - 1));
		for (int i = 1; i < (int)this->size(); i++) res[i - 1] = freq(i) * i;
		return res;
	}
	
	Poly inte() const {
		std::vector<D> res(this->size() + 1);
		for (int i = 0; i < (int)this->size(); i++) res[i + 1] = freq(i) / (i + 1);
		return res;
	}

	// f * f.inv() = 1 + g(x)x^m
	Poly inv(int m = -1) const {
		if (m == -1) m = (int)this->size();
		Poly res = Poly({D(1) / freq(0)});
		for (int i = 1; i < m; i *= 2) {
			res = (res * D(2) - res * res * pre(2 * i)).pre(2 * i);
		}
		return res.pre(m);
	}
	
	Poly exp(int n = -1) const {
		assert(freq(0) == 0);
		if (n == -1) n = (int)this->size();
		Poly f({1}), g({1});
		for (int i = 1; i < n; i *= 2) {
			g = (g * 2 - f * g * g).pre(i);
			Poly q = diff().pre(i - 1);
			Poly w = (q + g * (f.diff() - f * q)).pre(2 * i - 1);
			f = (f + f * (*this - w.inte()).pre(2 * i)).pre(2 * i);
		}
		return f.pre(n);
	}
	
	Poly log(int n = -1) const {
		if (n == -1) n = (int)this->size();
		assert(freq(0) == 1);
		auto f = pre(n);
		return (f.diff() * f.inv(n - 1)).pre(n - 1).inte();
	}

	Poly pow_mod(const Poly& mod, long long n = -1) {
		if (n == -1) n = this->size();
		Poly x = *this, r = {{1}};
		while (n) {
			if (n & 1) r = r * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return r;
	}

	D _pow(D x, long long k) { 
		D r = 1;
		while (k) {
			if (k & 1) {
				r *= x;
			}
			x *= x;
			k >>= 1;
		}
		return r;
	}

	Poly pow(long long k, int n = -1) {
		if (n == -1) n = this->size();
		int sz = (int)this->size();
		for (int i = 0; i < sz; ++i) {
			if (freq(i) != 0) {
				if (i * k > n) return Poly(n);
				D rev = 1 / (*this)[i];
				Poly ret = (((*this * rev) >> i).log(n) * k).exp(n) * _pow((*this)[i], k);
				ret = (ret << (i * k)).pre(n);
				ret.resize(n);
				return ret;
			}
		}
		return Poly(n);
	}

	friend std::ostream& operator<<(std::ostream& os, const Poly& p) {
		if (p.empty()) return os << "0";
		for (auto i = 0; i < (int)p.size(); i++) {
			if (p[i]) {
				os << p[i] << "x^" << i;
				if (i != (int)p.size() - 1) os << "+";
			}
		}
		return os;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<array<int, 2>> v(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		auto val = [](char c) {
			if (c == '?') {
				return -1;
			} else if (c == 'B') {
				return 0;
			} else {
				return 1;
			}
		};
		for (int j = 0; j < 2; ++j) {
			v[i][j] = val(s[j]);
		}
	}
	int c1 = 0, c2 = 0, c3 = 0;
	for (int i = 0; i < n; ++i) {
		bool x = v[i][0] != 1 && v[i][1] != 0;
		bool y = v[i][0] != 0 && v[i][1] != 1;
		if (x && y) {
			++c3;
		} else if (x) {
			++c1;
		} else if (y) {
			++c2;
		}
	}
	vector<Poly<mi>> polys;
	for (int i = 0; i < n; ++i) {
		auto gen = [](int x) {
			vector<int> ret;
			if (x == -1) {
				ret = {0, 1};
			} else {
				ret = {x};
			}
			return ret;
		};
		vector<int> v1 = gen(v[i][0]), v2 = gen(v[i][1]);
		Poly<mi> p(3); 
		for (int x : v1) {
			for (int y : v2) {
				if (x == 0 && y == 0) {
					p[0] += 1;
				} else if (x == 1 && y == 1) {
					p[2] += 1;
				} else {
					p[1] += 1;
				}
			}
		}
		polys.push_back(p);
	}
	set<array<int, 2>> que;
	for (int i = 0; i < (int)polys.size(); ++i) {
		que.insert({(int)polys[i].size(), i});
	}
	while ((int)que.size() > 1) {
		int x = (*que.begin())[1];
		que.erase(que.begin());
		int y = (*que.begin())[1];
		que.erase(que.begin());
		auto z = polys[x] * polys[y];
		polys[x].clear(), polys[y].clear();
		polys[x] = z;
		que.insert({(int)z.size(), x});
	}
	auto res = polys[(*que.begin())[1]];
	res.resize(n + 1);
	mi ans = res[n];
	if (c1 + c2 + c3 == n) {
		if (c3 == n) {
			ans += 2;
		} else {
			if (c1 + c3 == n || c2 + c3 == n) {
				ans += 1;
			}
		}
		ans -= pow(mi(2), c3);
	}
	cout << ans << '\n';
	return 0;
}

/**
 * If there is an a, there must be a b
 * Null cases, all a, all b
 * If there are an equal number of a's and b's, then anything can happen 
 */