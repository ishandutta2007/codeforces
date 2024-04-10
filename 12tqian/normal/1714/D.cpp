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
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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
#define r1f(i, a, b) for (int i = (b); i --> (a); )
#define r0f(i, a) r1f(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define each(a, x) for (auto& a : x)

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<V<V<T>>>;
template <class T> using VVVV = V<V<V<V<T>>>>;

template <typename T, typename S> ostream& operator << (ostream& os, const pair<T, S>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream& os, const C& c) { bool f = true; os << "{"; for (const auto& x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
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
	template <class T, class... U> void re(T& t, U&... u);
	template <class T, class U> void re(pair<T, U>& p); // pairs


	// re: read

	template <class T> typename enable_if<is_readable_v<T>, void>::type re(T& x) { cin >> x; } // default

	template <class T> void re(complex<T>& c) { T a, b; re(a, b); c = {a, b}; } // complex

	template <class T> typename enable_if<needs_input_v<T>, void>::type re(T& i); // ex. vectors, arrays

	template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }
	template <class T> typename enable_if<needs_input_v<T>, void>::type re(T& i) {
		for (auto& x : i) re(x); }
	template <class T, class... U> void re(T& t, U&... u) { re(t); re(u...); } // read multiple


	// rv: resize and read vectors

	void rv(std::size_t) {}
	template <class T, class... U> void rv(std::size_t N, vector<T>& t, U&... u);
	template <class...U> void rv(std::size_t, std::size_t N2, U&... u);
	template <class T, class... U> void rv(std::size_t N, vector<T>& t, U&... u) {
		t.resize(N); re(t);
		rv(N, u...); }
	template <class...U> void rv(std::size_t, std::size_t N2, U&... u) {
		rv(N2, u...); }

	// dumb shortcuts to read in ints

	void decrement() {} // subtract one from each

	template <class T, class... U> void decrement(T& t, U&... u) { --t; decrement(u...); }
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
		for (const auto& x : v) { 
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	template <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v) {
		return "{" + ts_sep(v, ", ") + "}"; } 

	// for nested DS

	template <int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template <int lev, class T> typename enable_if<needs_output_v<T>, vector<string>>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !(int)v.size()) return {ts(v)};
		vector<string> res;
		for (const auto& t : v) {
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
	template <class T> void pr_sep(ostream& os, string, const T& t) { os << ts(t); }
	template <class T, class... U> void pr_sep(ostream& os, string sep, const T& t, const U&... u) {
		pr_sep(os, sep, t); os << sep; pr_sep(os, sep, u...); }
	// print w/ no spaces

	template <class... T> void pr(const T&... t) { pr_sep(cout, "", t...); } 
	// print w/ spaces, end with newline

	void ps() { cout << "\n"; }
	template <class... T> void ps(const T&... t) { pr_sep(cout, " ", t...); ps(); } 
	// debug to cerr

	template <class... T> void dbg_out(const T&... t) {
		pr_sep(cerr, " | ", t...); cerr << endl; }
	void loc_info(int line, string names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template <int lev, class T> void dbgl_out(const T& t) {
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
	void set_in(string s)  { (void)!freopen(s.c_str(), "r", stdin); }
	void set_out(string s) { (void)!freopen(s.c_str(), "w", stdout); }
	void set_io(string s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams

		// cin.exceptions(cin.failbit);

		// throws exception when do smth illegal

		// ex. try to read letter into int

		if (!s.empty()) set_in(s + ".in"), set_out(s + ".out"); // for old USACO

	}
}

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

const ld PI = acos((ld)-1);

namespace Hashing {

const int MOD = 1e9 + 7;

std::mt19937 rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const std::array<int, 2> base = {BDIST(rng), BDIST(rng)};
std::vector<std::array<int, 2>> pows = {{1, 1}};

std::array<int, 2> operator+(std::array<int, 2> l, std::array<int, 2> r) {
	for (int i = 0; i < 2; i++)
		if ((l[i] += r[i]) >= MOD)
			l[i] -= MOD;
	return l;
}

std::array<int, 2> operator-(std::array<int, 2> l, std::array<int, 2> r) {
	for (int i = 0; i < 2; i++)
		if ((l[i] -= r[i]) < 0)
			l[i] += MOD;
	return l;
}

std::array<int, 2> operator*(std::array<int, 2> l, std::array<int, 2> r) {
	for (int i = 0; i < 2; i++)
		l[i] = (long long) l[i] * r[i] % MOD;
	return l;
}

std::array<int, 2> make_hash(char c) {
	return {c, c};
}

struct HashRange {
	std::vector<std::array<int, 2>> pre = {{0, 0}};
	std::string s;

	void add(char c) {
		s += c;
		pre.push_back(base * pre.back() + make_hash(c));
	}

	void add(std::string t) {
		for (auto& c : t)
			add(c);
	}

	void extend(int len) {
		while ((int)pows.size() <= len)
			pows.push_back(base * pows.back());
	}
	
	std::array<int, 2> hash(int l, int r) {
		int len = r + 1 - l;
		extend(len);
		return pre[r + 1] - pows[len] * pre[l];
	}
};

} // Hashing

using namespace Hashing;

void solve_case(int tc = 0) {
	const int INF = 1e9;
	string t;
	re(t);
	int n; 
	re(n);
	vs s(n);
	re(s);
	int sz = sz(t);
	HashRange ht;
	ht.add(t);
	V<HashRange> st(n);
	f0r(i, n) {
		st[i].add(s[i]);
	}
	vi dp(sz, INF);
	V<array<int, 3>> use(sz);
	auto check = [&](int a, int i) {
		int j = a + sz(s[i]) - 1;
		if (j >= sz(t)) {
			return false;
		}
		return ht.hash(a, j) == st[i].hash(0, sz(s[i]) - 1);
	};
	auto mash = [&]() {
		r0f(i, sz - 1) {
			if (ckmin(dp[i], dp[i + 1])) {
				use[i] = use[i + 1];
			}
		}
	};
	f0r(i, n) {
		if (check(0, i)) {
			if (ckmin(dp[sz(s[i]) - 1], 1)) {
				use[sz(s[i]) - 1] = {0, i, -1};
			}
		}
	}
	mash();
	f1r(i, 1, sz) {
		f0r(j, n) {
			if (check(i, j)) {
				if (ckmin(dp[sz(s[j]) - 1 + i], dp[i - 1] + 1)) {
					use[sz(s[j]) - 1 + i] = {i, j, i - 1};
				}
			}
		}
		mash();
	}
	int ans = dp.bk;
	if (ans == INF) {
		ps(-1);
		return;
	} 
	ps(ans);
	int cur = sz - 1;
	while (cur != -1) {
		ps(use[cur][1] + 1, use[cur][0] + 1);
		cur = use[cur][2];
	}
}

int main() {
	set_io();
	int tt = 1;
	re(tt);
	f1r(tc, 1, tt + 1) {
		solve_case(tc);
	}
	return 0;
}