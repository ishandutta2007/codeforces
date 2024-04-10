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
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define each(a, x) for (auto& a : x)

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
    template <class T, class ...U> void re(T& t, U&... u);
    template <class T, class U> void re(pair<T, U>& p); // pairs

    // re: read
    template <class T> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
    template <class T> void re(complex<T>& c) { T a, b; re(a, b); c = {a, b}; } // complex
    template <class T> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
    template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }
    template <class T> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
        for (auto& x : i) re(x); }
    template <class T, class ...U> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

    // rv: resize and read vectors
    void rv(size_t) {}
    template <class T, class ...U> void rv(size_t N, vector<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    template <class T, class ...U> void rv(size_t N, vector<T>& t, U&... u) {
        t.resize(N); re(t);
        rv(N, u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2, u...); }

    // dumb shortcuts to read in ints
    void decrement() {} // subtract one from each
    template <class T, class ...U> void decrement(T& t, U&... u) { --t; decrement(u...); }
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
    template<size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
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
    template<int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type 
      ts_lev(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<needs_output_v<T>, vector<string>>::type 
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
    template<class T> void pr_sep(ostream& os, string, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, string sep, const T& t, const U&... u) {
        pr_sep(os, sep, t); os << sep; pr_sep(os, sep, u...); }
    // print w/ no spaces
    template<class ...T> void pr(const T&... t) { pr_sep(cout, "", t...); } 
    // print w/ spaces, end with newline
    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout, " ", t...); ps(); } 
    // debug to cerr
    template<class ...T> void dbg_out(const T&... t) {
        pr_sep(cerr, " | ", t...); cerr << endl; }
    void loc_info(int line, string names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
    template<int lev, class T> void dbgl_out(const T& t) {
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

const int MOD = 998244353;
const ld PI = acos((ld) -1);

typedef std::decay <decltype(MOD)>::type mod_t;
struct mi {
    mod_t val;
    explicit operator mod_t() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend std::istream& operator >> (std::istream& in, mi& a) { 
        long long x; std::cin >> x; a = mi(x); return in; }
    friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
    friend void pr(const mi& a) { pr(a.val); }
    friend void re(mi& a) { long long x; cin >> x; a = mi(x); }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }    
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
    friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
    friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};

typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template <class T> int get_pos(vector<T>& v, T x) { return lb(all(v), x) - v.begin(); }

const int N = 2e5 + 5;
mi fact[N];
mi ifact[N];
mi C(int x, int y) {
    if (x < y) return 0;
    return fact[x] * ifact[y] * ifact[x - y];
}
int main() {
    fact[0] = 1;
    f1r(i, 1, N) fact[i] = fact[i - 1] * i;
    ifact[N - 1] = 1 / fact[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        ifact[i] = ifact[i + 1] * (i + 1);
    }
    setIO("");
    int n, k; re(n, k);
    vi a(n); re(a);
    mi ans = 0;
    vi rev(n + 1);
    f0r(i, n) rev[a[i]] = i;
    rev[n] = -1;
    vi eq;
    int amt = 1;
    f0r(i, n - 1) {
        int x = a[i] + 1;
        int y = a[i + 1] + 1;
        if (rev[x] < rev[y]) {
            eq.pb(0);
        } else {
            eq.pb(1);
            ++amt;
        }
    }
    int place = amt - 1;
    f1r(i, amt, k + 1) {
        ans += C(k, i) * C(n - 1 - place, i - 1 - place);
    }
    ps(ans);

    return 0;
}