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

const int MOD = 1e9 + 7; // 998244353


typedef std::decay<decltype(MOD)>::type mod_t; 
struct mi {
	mod_t v;
	explicit operator mod_t() const { return v; }
	explicit operator bool() const { return v != 0; }
	mi() { v = 0; }
	mi(const long long& _v) {
		v = (-MOD <= _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD; }
	friend std::istream& operator>>(std::istream& in, mi& a) { 
		long long x; std::cin >> x; a = mi(x); return in; }
	friend std::ostream& operator<<(std::ostream& os, const mi& a) { return os << a.v; }
	friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }    
	friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
	friend bool operator>(const mi& a, const mi& b) { return a.v > b.v; }
	friend bool operator<=(const mi& a, const mi& b) { return a.v <= b.v; }
	friend bool operator>=(const mi& a, const mi& b) { return a.v >= b.v; }
	mi operator-() const { return mi(-v); }
	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD) v -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0) v += MOD;
		return *this; }
	mi& operator*=(const mi& m) { v = (long long)v * m.v % MOD;
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

const ld PI = acos((ld)-1);

typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template <class C, bool directed> struct Dijkstra {
	int SZ; std::vector<C> dist;
	std::vector<std::vector<std::pair<int, C>>> adj;

	void init(int _SZ) {
		SZ = _SZ;
		adj.clear();
		adj.resize(SZ);
	}

	void ae(int u, int v, C cost) {
		adj[u].emplace_back(v, cost);
		if (!directed) adj[v].emplace_back(u, cost);
	}

	void gen(int st) {
		dist = std::vector<C>(SZ, std::numeric_limits<C>::max());
		typedef std::pair<C, int> T;
		std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
		auto ad = [&](int a, C b) {
			if (dist[a] <= b) return;
			pq.push({dist[a] = b, a});
		};
		ad(st, 0);
		while (!pq.empty()) {
			auto x = pq.top();
			pq.pop();
			if (dist[x.second] < x.first) continue;
			for (auto& y: adj[x.second]) {
				ad(y.first, x.first + y.second);
			}
		}
	}
};

const long long INF = 1e18;

struct Line {
	mutable long long a, b, lst;

	long long eval(long long x) {
		return a * x + b;
	}

	bool operator<(const Line& y) const {
		return a < y.a;
	}

	long long floor_div(long long a, long long b) {
		return a / b - ((a ^ b) < 0 && a % b);
	}

	long long bet(const Line& y) {
		assert(a <= y.a);
		return a == y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);
	}
};

struct ConvexHullDeque : std::deque<Line> {
	void add_back(Line L) {
		while (true) {
			auto a = back();
			pop_back();
			a.lst = a.bet(L);
			if (size() && back().lst >= a.lst) {
				continue;
			}
			push_back(a);
			break;
		}
		L.lst = INF;
		push_back(L);
	}

	void add_front(Line L) {
		while (true) {
			if (!size()) {
				L.lst = INF;
				break;
			}
			if ((L.lst = L.bet(front())) >= front().lst) {
				pop_front();
			} else {
				break;
			}
		}
		push_front(L);
	}

	void add(long long a, long long b) {
		// comment this out for max

		a = -a; b = -b;
		if (!size() || a <= front().a) {
			add_front({a, b, 0});
		} else {
			assert(a >= back().a);
			add_back({a, b, 0});
		}
	}

	int ord = 1; // 1 = increasing, -1 = decreasing

	long long query(long long x) {
		// flip negatives for max

		assert(ord);
		if (ord == 1) {
			while (front().lst < x) {
				pop_front();
			}
			return -front().eval(x);
		} else {
			while (size() > 1 && prev(prev(end()))->lst >= x) {
				pop_back();
			}
			return -back().eval(x);
		}
	}
};

void solve_case(int tc = 0) {
	int n, m, k;
	re(n, m, k);
	V<array<int, 3>> edges;
	f0r(i, m) {
		int u, v, w;
		re(u, v, w);
		--u, --v;
		edges.pb({u, v, w});
	}
	vl ans(n, INF);
	vl dist(n, INF);
	Dijkstra<ll, false> d;
	auto run = [&]() {
		d.init(n);
		for (auto [u, v, w] : edges) {
			d.ae(u, v, w);
		}
		f1r(i, 1, n) {
			d.ae(0, i, dist[i]);
		}
		d.gen(0);
		dist = d.dist;
		f0r(i, n) {
			ckmin(ans[i], dist[i]);
		}
	};
	run();
	ConvexHullDeque chd;
	f1r(e, 1, k + 1) { // using exactly e edges
		auto go = [&](vl dist) {
			chd.clear();
			vl dp = dist;
			f0r(i, n) {
				if (i) {
					ckmin(dp[i], chd.query(i) + 1ll * i * i);
				}
				chd.add(-2 * i, 1ll * i * i + dist[i]);
			}
			return dp;
		};
		auto prv = dist;
		dist = go(prv);
		reverse(all(prv));
		auto rev = go(prv);
		reverse(all(rev));
		f0r(i, n) {
			ckmin(dist[i], rev[i]);
		}
		run();
	}
	f0r(i, n) {
		pr(ans[i], ' ');
	}
	ps();
}

int main() {
	set_io();
	int tt = 1;
	// re(tt);
	f1r(tc, 1, tt + 1) {
		solve_case(tc);
	}
	return 0;
}