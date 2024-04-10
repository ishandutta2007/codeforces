#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }
const int MOD = 1e9 + 7;
typedef decay<decltype(MOD)>::type T;
struct mi {
    T val;
    explicit operator T() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
    friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
    mi operator-() const { return mi(-val); }
    mi& operator+=(const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator*=(const mi& m) { val = (long long) val * m.val % MOD;
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
int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> pre(4, vector<int>(n, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int val = s[i] - 'a';
        if (val < 0) {
            val = 3;
            cnt++;
        }
        for (int j = 0; j < 4; j++) {
            if (i == 0) {
                pre[j][i] = (val == j);
            } else {
                pre[j][i] = pre[j][i - 1] + (val == j);
            }
        }
    }
    auto sum = [&](int t, int l, int r) -> int {
        if (l == 0) {
            return pre[t][r];
        }
        return pre[t][r] - pre[t][l - 1];
    };
    mi ans = 0;
    vector<mi> po(n + 1);
    po[0] = 1;
    for (int i = 1; i <= n; i++) {
        po[i] = po[i - 1] * 3;
    }
    for (int i = 1; i < n - 1; i++) {
        if (s[i] != 'b' && s[i] != '?') {
            continue;
        }
        int bad = (s[i] == '?');
        for (int j: {0, 3}) {
            for (int k: {2, 3}) {
                if (sum(j, 0, i - 1) == 0 || sum(k, i + 1, n - 1) == 0) {
                    continue;
                }
                int bad = (s[i] == '?') + ((j == 3) + (k == 3));
                ans += po[cnt - bad] * sum(j, 0, i - 1) * sum(k, i + 1, n - 1);
            }
        }
    }
    cout << ans << '\n';
}