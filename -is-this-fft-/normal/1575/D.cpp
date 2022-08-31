// region Import
#pragma warning(disable : 4068) /* disable unknown pragma warnings */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#ifdef _MSC_VER

#include <intrin.h>

#endif

#include <cassert>
#include <set>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

namespace /* Using */ {
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;
using vd = vector<ld>;
using vvd = vector<vd>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
}
// endregion
// region Config
constexpr ll operator"" _b(unsigned long long int pow) { return 1ll << pow; }
constexpr ll IO_Void = 0_b;
constexpr ll IO_Interactive = 1_b;
constexpr ll IO_GCJ = 2_b;
constexpr ll IO_Multi = 3_b;
constexpr ll IO_Files = 4_b;
constexpr ll IO_LocalCin = 5_b;
constexpr ll IO_LocalCout = 6_b;
constexpr ll Mod_998244353 = 7_b;
constexpr ll Mod_1000000007 = 8_b;
constexpr ll Mod_1000000009 = 9_b;
constexpr ll Mod_1000000000000037 = 10_b;
constexpr ll RunningLocally = 11_b;
constexpr auto Config =
#ifdef RUNNING_LOCALLY
    RunningLocally +
#else
    0 +
#endif
    /* endregion*/
    Mod_998244353;
constexpr auto Input = "input.txt", Output = "output.txt";
// region Library
namespace /* Constants */ {
constexpr ll Mod998244353 = 998244353;
constexpr ll Mod1000000007 = 1000000007;
constexpr ll Mod1000000009 = 1000000009;
constexpr ll Mod1000000000000037 = 1000000000000037;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
#pragma ide diagnostic ignored "Simplify"

constexpr ll Mod = Config & Mod_998244353          ? Mod998244353
                   : Config & Mod_1000000007       ? Mod1000000007
                   : Config & Mod_1000000009       ? Mod1000000009
                   : Config & Mod_1000000000000037 ? Mod1000000000000037
                                                   : throw;
#pragma clang diagnostic pop
}

namespace /* Utility */ {
template <class X, class P> X power(X x, P p) {
    if (p == 0) return P(1);
    if (p == 1) return x;
    return power(x * x, p / 2) * power(x, p % 2);
}

template <typename T = int> T binary_string_to_integer(const string &s) {
    T ans = 0;
    for (char c : s) {
        ans <<= 1;
        if (c == '1') ans += 1;
    }
    return ans;
}

int popcnt(int n) {
#ifndef _MSC_VER
    return __builtin_popcount(n);
#else
    return int(__popcnt(n));
#endif
}
}

namespace /* ReadWrite */ {
template <class T> istream &operator>>(istream &stream, vector<T> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        stream >> vec[i];
    }
    return stream;
}
template <class T1, class T2> istream &operator>>(istream &stream, pair<T1, T2> &p) {
    stream >> p.first >> p.second;
    return stream;
}

template <class T> ostream &operator<<(ostream &stream, vector<T> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        stream << vec[i];
        if (i + 1 != vec.size()) stream << ' ';
    }
    return stream;
}

template <class T>
ostream &operator<<(ostream &stream, vector<vector<T>> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        stream << vec[i] << '\n';
    }
    return stream;
}
} // namespace

namespace /* VectorOperations */ {
template <class T> T min(vector<T> vec) {
    assert(vec.size() > 0);
    T ans = vec[0];
    for (int i = 1; i < vec.size(); ++i)
        ans = min(ans, vec[i]);
    return ans;
}

template <class T> T max(vector<T> vec) {
    assert(vec.size() > 0);
    T ans = vec[0];
    for (int i = 1; i < vec.size(); ++i)
        ans = max(ans, vec[i]);
    return ans;
}

template <class T> T sum(vector<T> vec) {
    T ans = T(0);
    for (auto x : vec)
        ans += x;
    return ans;
}
}

namespace /* NumberTheory */ {
template <typename T = ll> T ext_euclid(T a, T b, T c, T d) {
    if (c == T(0)) return b;
    return ext_euclid(c, d, a % c, b - a / c * d);
}

template <typename T = ll> T mod_inverse(T x, const T mod = Mod) {
    return (ext_euclid(mod, T(0), x, T(1)) + mod) % mod;
}

template <typename T = ll, T MOD = Mod> struct Factorial {
    vector<T> fact, ifact;

    T comb(T n, T m) {
        assert(n >= m);
        assert(n < sz(fact));
        return fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
    }

    explicit Factorial(T n) {
        fact.resize(n + T(1));
        ifact.resize(n + T(1));
        fact[0] = T(1);
        for (auto i = T(1); i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        ifact[n] = mod_inverse(fact[n], MOD);
        for (T i = n - T(1); i >= T(0); --i)
            ifact[i] = (i + T(1u)) * ifact[i + T(1)] % MOD;
    }
};

template <typename T = ll, T MOD = Mod> struct ModInt {
    T Value;
    void normalize(){
        if(abs(Value) >= MOD){
            Value %= MOD;
        }
        if(Value < 0){
            Value += MOD;
        }
    }
    ModInt(){
        Value = 0;
    }
    ModInt(T a) {
        Value = a;
        normalize();
    }
    friend ostream &operator<<(ostream &stream, const ModInt &a) {
        stream << a.Value;
        return stream;
    }
    friend istream &operator>>(istream &stream, ModInt &a) {
        stream >> a.Value;
        return stream;
    }
    ModInt operator*=(const ModInt &rhs) {
        Value = (Value * rhs.Value) % MOD;
        return *this;
    }
    ModInt operator+=(const ModInt &rhs) {
        Value += rhs.Value;
        if (Value >= MOD) { Value -= MOD; }
        return *this;
    }
    ModInt operator-=(const ModInt &rhs) {
        Value -= rhs.Value;
        if (Value < 0) { Value += MOD; }
        return *this;
    }
    ModInt operator+(const ModInt &rhs) {
        ModInt ans(Value);
        return ans += rhs;
    }
    ModInt operator-(const ModInt &rhs) {
        ModInt ans(Value);
        return ans -= rhs;
    }
    ModInt operator*(const ModInt &rhs) {
        ModInt ans(Value);
        return ans *= rhs;
    }
};
using mi = ModInt<ll,Mod>;
using vmi = vector<mi>;
}
//endregion


bool match(const string &s, const string &t){
    if(s.size() != t.size()) return false;
    int xmin = 999, xmax = -999;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'X'){
            xmin = min(xmin,(int)t[i]);
            xmax = max(xmax,(int)t[i]);
        }
        else if(s[i] != '_'){
            if(s[i] != t[i]){
                return false;
            }
        }
    }
    if(xmin != 999 && xmin != xmax) return false;
    return true;
}
int run(istream &in, ostream &out) {
    string s;
    in >> s;
    int ans = 0;
    for(int i = 0; i <= 99999999; i += 25){
        string t = to_string(i);
        if(match(s,t)){
            ++ans;
        }
    }
    return ans;
}
//region IO
namespace /* IO */ {
void fast_io() { ios_base::sync_with_stdio(false); }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "Simplify"
#pragma ide diagnostic ignored "UnreachableCode"

void run_io() {
    auto path = filesystem::current_path().parent_path();
    filesystem::path iFile(Input);
    filesystem::path oFile(Output);
    bool iFileUsed = (Config & IO_Files) ||
                     ((Config & RunningLocally) && !(Config & IO_LocalCin));
    bool oFileUsed = (Config & IO_Files) ||
                     ((Config & RunningLocally) && !(Config & IO_LocalCout));
    ifstream fin;
    ofstream fout;
    istream &in = iFileUsed ? fin : cin;
    ostream &out = oFileUsed ? fout : cout;
    if (iFileUsed) fin.open(path / iFile);
    if (oFileUsed) fout.open(path / oFile);
    if (!(Config & IO_Interactive)) { fast_io(); }
    int test_cases = 1;
    if (Config & IO_Multi) { in >> test_cases; }
    for (int i = 1; i <= test_cases; ++i) {
        if (!(Config & IO_Void)) {
            if (Config & IO_GCJ) { out << "Case #" << i << ": "; }
            out << run(in, out) << '\n';
        }
    }
}

#pragma clang diagnostic pop
#pragma clang diagnostic pop
}
//endregion
int main() { run_io(); }