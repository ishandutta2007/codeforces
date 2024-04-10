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
#define sz(x) (int) (x).size()
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

namespace input {
    template <class T> void re(complex<T>& x);
    template <class T1, class T2> void re(pair<T1, T2>& p);
    template <class T> void re(vector<T>& a);
    template <class T, int SZ> void re(array<T, SZ>& a);
    template <class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template <class T, class... Ts> void re(T& t, Ts&... ts) {
        re(t); re(ts...); }
    template <class T> void re(complex<T>& x) { T a, b; re(a, b); x = cd(a, b); }
    template <class T1, class T2> void re(pair<T1, T2>& p) { re(p.f, p.s); }
    template <class T> void re(vector<T>& a) { F0R(i, sz(a)) re(a[i]); }
    template <class T, int SZ> void re(array<T, SZ>& a) { F0R(i, SZ) re(a[i]); }
}

using namespace input;

namespace output {
    void pr(int x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(ll x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(ld x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { pr(x ? "true" : "false"); }
    template <class T> void pr(const complex<T>& x) { cout << x; }
    template <class T1, class T2> void pr(const pair<T1, T2>& x);
    template <class T> void pr(const T& x);
    template <class T, class... Ts> void pr(const T& t, const Ts&... ts) {
        pr(t); pr(ts...); }
    template <class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{", x.f, ", ", x.s, "}"); }
    template <class T> void pr(const T& x) {
        pr("{"); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst ? ", " : "", a), fst = 0;
        pr("}"); }
    void ps() { pr("\n"); } // print w/ spaces
    template <class T, class... Ts> void ps(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); }
    void pc() { pr("]\n"); } // debug w/ commas
    template <class T, class... Ts> void pc(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(), "r", stdin); }
    void setOut(string s) { freopen(s.c_str(), "w", stdout); }
    void setIO(string s = "") {
        cin.sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s + ".in"), setOut(s + ".out"); }
    }
}

using namespace io;

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
const int A = 26;
const int N = 401;
const int M = 101;


mi place[N][N][N][4]; // place w, x into length y, previous letter was w, x, of smth else, or blank
// 0 is blank, 1 is w, 2 is x, 3 is smth
// bool vis[N][N][N][4];

mi place2[N][N][3]; // place w into length x, last letter was y
// bool vis2[N][N][3];
mi ways[4*N][4*N];

mi dp[N][N];

mi recurse_place(int w, int x, int y, int z) {
    if (w < 0 || x < 0 || y < 0) return 0;
    if (w + x > y) return 0;
    if (w > (y + 1) / 2 || x > (y + 1) / 2) return 0;
    if (place[w][x][y][z] != 0) return place[w][x][y][z];
    // vis[w][x][y][z] = true;
    if (y == 0) {
        if (w == 0 && x == 0) {
            place[w][x][y][z] = 1;
            return 1;
        }
        return 0;
    }
    auto& res = place[w][x][y][z];
    if (w && z != 1) {
        res += recurse_place(w-1, x, y-1, 1);
    }
    if (x && z != 2) {
        res += recurse_place(w, x-1, y-1, 2);
    }
    if (z == 0) {
        res += recurse_place(w, x, y-1, 3) * (A-2);
    } else if (z == 3) {
        res += recurse_place(w, x, y-1, 3) * (A-3);
    } else {
        res += recurse_place(w, x, y-1, 3) * (A-2);
    }
    return res;
}

mi recurse_place2(int w, int x, int y) {
    if (w < 0 || x < 0) return 0;
    if (w > x) return 0;
    if (w > (x + 1) / 2) return 0;
    if (place2[w][x][y] != 0) return place2[w][x][y];
    // vis2[w][x][y] = true;
    if (x == 0) {
        if (w == 0) {
            place2[w][x][y] = 1;
            return 1;
        }
    }
    auto& res = place2[w][x][y];
    if (w && y != 1) {
        res += recurse_place2(w-1, x-1, 1);
    }
    if (y == 0) {
        res += recurse_place2(w, x-1, 2) * (A-1);
    } else if (y == 2) {
        res += recurse_place2(w, x-1, 2) * (A-2);
    } else {
        res += recurse_place2(w, x-1, 2) * (A-1);        
    }
    return res;
}

int main() {
    setIO("");
    int n; re(n);
    vi c(A);
    f0r(i, A) re(c[i]);
    int n1 = n / 2;
    int n2 = n - n1;
  
    mi ans = A * A;
    f0r(i, n1-1) {
        ans *= (A-1);
    }
    f0r(i, n2-1) {
        ans *= (A-1);
    }
    mi one = 0;
    // ps(recurse_place2(0, 4, 0));
    // ps(recurse_place(100, /100, 200, 0));

    f0r(i, A) { // one of them exceeds
        f1r(j, c[i]+1, n+1) {
            f0r(k, n1+1) {
                one += recurse_place2(k, n1, 0) * recurse_place2(j-k, n2, 0);
            }
        }
    }

    int lo = 0;
    mi two = 0;

    f0r(a, M) {
        f0r(b, M) {
            f0r(c, M) {
                f0r(d, M) {
                    ways[a+b][c+d] += recurse_place(a, c, n1, 0) * recurse_place(b, d, n2, 0);
                }
            }
        }
    }

    for (int i = 4*N-1; i >= 0; i--) {
        mi run = 0;
        for (int j = 4*N-1; j >= 0; j--) {
            run += ways[i][j];
            ways[i][j] = run;
            if (i != 4*N-1) ways[i][j] += ways[i+1][j];
        }
    }
    f0r(i, A) {
        f0r(j, i) { // these two have exceeded
            two += ways[c[i]+1][c[j]+1];
        }
    }
    // ps(one, two);
    ans = ans - one + two;

    ps(ans);

    return 0;
}

/**
 * ans stores total ways
 * count one of them exceeds
 */