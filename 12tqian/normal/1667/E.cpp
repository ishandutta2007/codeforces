#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define f1r(i, a, b) for (int i = (a); i < (b); ++i)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define each(a, x) for (auto &a : x)

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<V<V<T>>>;
template <class T> using VVVV = V<V<V<V<T>>>>;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template <typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template <typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template <typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	template <class T, class = void> struct is_iterable : false_type {};
	template <class T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
									  decltype(end(declval<T>()))
									 >
						   > : true_type {};
	template <class T> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	template <class T, class = void> struct is_readable : false_type {};
	template <class T> struct is_readable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cin >> declval<T&>()), istream&>
			>
		> : true_type {};
	template <class T> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	template <class T, class = void> struct is_printable : false_type {};
	template <class T> struct is_printable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cout << declval<T>()), ostream&>
			>
		> : true_type {};
	template <class T> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	template <class T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	template <class T, class ...U> void re(T &t, U &...u);
	template <class T, class U> void re(pair<T, U> &p); // pairs

	// re: read
	template <class T> typename enable_if<is_readable_v<T>, void>::type re(T &x) { cin >> x; } // default
	template <class T> void re(complex<T> &c) { T a, b; re(a, b); c = {a, b}; } // complex
	template <class T> typename enable_if<needs_input_v<T>, void>::type re(T &i); // ex. vectors, arrays
	template <class T, class U> void re(pair<T, U> &p) { re(p.first, p.second); }
	template <class T> typename enable_if<needs_input_v<T>, void>::type re(T &i) {
		for (auto &x : i) re(x); }
	template <class T, class ...U> void re(T &t, U &...u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(std::size_t) {}
	template <class T, class ...U> void rv(std::size_t N, vector<T> &t, U &...u);
	template <class...U> void rv(std::size_t, std::size_t N2, U &...u);
	template <class T, class ...U> void rv(std::size_t N, vector<T> &t, U &...u) {
		t.resize(N); re(t);
		rv(N, u...); }
	template <class...U> void rv(std::size_t, std::size_t N2, U &...u) {
		rv(N2, u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	template <class T, class ...U> void decrement(T &t, U &...u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	template <class T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	template <class T> typename enable_if<is_printable_v<T>, string>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	template <class T> string bit_vec(T t) { // bit vector to string
		string res = "{"; for (int i = 0; i < (int)t.size(); ++i) res += ts(t[i]);
		res += "}"; return res; }
	string ts(vector<bool> v) { return bit_vec(v); }
	template <std::size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	template <class T, class U> string ts(pair<T, U> p); // pairs
	template <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v); // vectors, arrays
	template <class T, class U> string ts(pair<T, U> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
	template <class T> typename enable_if<is_iterable_v<T>, string>::type ts_sep(T v, string sep) {
		// convert container to string w/ separator sep
		bool fst = 1; string res = "";
		for (const auto &x : v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	template <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v) {
		return "{" + ts_sep(v, ", ") + "}"; }

	// for nested DS
	template <int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type 
	  ts_lev(const T &v) { return {ts(v)}; }
	template <int lev, class T> typename enable_if<needs_output_v<T>, vector<string>>::type 
	  ts_lev(const T &v) {
		if (lev == 0 || !(int)v.size()) return {ts(v)};
		vector<string> res;
		for (const auto &t : v) {
			if ((int)res.size()) res.back() += ",";
			vector<string> tmp = ts_lev<lev - 1>(t);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		for (int i = 0; i < (int)res.size(); ++i) {
			string bef = " "; if (i == 0) bef = "{";
			res[i] = bef + res[i];
		}
		res.back() += "}";
		return res;
	}
}

inline namespace Output {
	template <class T> void pr_sep(ostream &os, string, const T &t) { os << ts(t); }
	template <class T, class... U> void pr_sep(ostream &os, string sep, const T &t, const U &...u) {
		pr_sep(os, sep, t); os << sep; pr_sep(os, sep, u...); }
	// print w/ no spaces
	template <class ...T> void pr(const T &...t) { pr_sep(cout, "", t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template <class ...T> void ps(const T &...t) { pr_sep(cout, " ", t...); ps(); } 
	// debug to cerr
	template <class ...T> void dbg_out(const T &...t) {
		pr_sep(cerr, " | ", t...); cerr << endl; }
	void loc_info(int line, string names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template <int lev, class T> void dbgl_out(const T &t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t), "\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev, x) 0
	#endif
}

inline namespace FileIO {
	void set_in(string s)  { freopen(s.c_str(), "r", stdin); }
	void set_out(string s) { freopen(s.c_str(), "w", stdout); }
	void setIO(string s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (!s.empty()) set_in(s + ".in"), set_out(s + ".out"); // for old USACO
	}
}

const ld PI = acos((ld) -1);

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

typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

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
	setIO("");
	int n;
	re(n);
	vmi fact(n + 1), ifact(n + 1), over(n + 1);
	fact[0] = 1;
	f1r(i, 1, n + 1) {
		fact[i] = fact[i - 1] * i;
	}
	ifact[n] = 1 / fact[n];
	for (int i = n - 1; i >= 0; --i) {
		ifact[i] = ifact[i + 1] * (i + 1);
	}
	f1r(i, 1, n + 1) {
		over[i] = ifact[i] * fact[i - 1];
	}
	auto C = [&](int x, int y) {
		if (x < y) {
			return mi(0);
		} else {
			return fact[x] * ifact[y] * ifact[x - y];
		}
	};
	auto iC = [&](int x, int y) {
		if (x < y) {
			return mi(0);
		} else {
			return ifact[x] * fact[y] * fact[x - y];
		}
	};
	vmi pre(n);
	int h = n / 2;
	f0r(i, n) {
		pre[i] = C(h, i - 1) * iC(n - 1, i - 1);
	}
	mi sub = 0;
	vmi ans(n);
	for (int i = n - 1; i >= 1; --i) {
		ans[i] = pre[i] - sub;
		sub += pre[i] * over[i - 1];
	}
	ans.erase(ans.begin());
	ans.pb(0);
	f0r(i, n) {
		ans[i] *= fact[n - 1];
		pr(ans[i], ' ');
	}
	ps();
	return 0;
}