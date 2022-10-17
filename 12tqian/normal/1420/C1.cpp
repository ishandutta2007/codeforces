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
const int MOD = 998244353;
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
            queries[i].first--;
            queries[i].second--;
        }
        if (n == 1) {
            for (int i = 0; i <= q; i++) {
                cout << 1 << '\n';
            }
            continue;
        }
        auto up = [&](int id) -> bool {
            bool b1 = (id == n - 1 ? true : (a[id] > a[id + 1]));
            bool b2 = (id == 0 ? true : a[id] > a[id - 1]);
            return b1 && b2;
        };
        auto down = [&](int id) -> bool {
            bool b1 = (id == n - 1 ? true : (a[id] < a[id + 1]));
            bool b2 = (id == 0 ? true : a[id] < a[id - 1]);
            return b1 && b2;
        };
        auto value = [&](int id) -> int {
            if (id == 0 || id == n - 1) {
                if (down(id)) return 0;
                return a[id];
            } else {
                if (up(id)) {
                    return a[id];
                } else if (down(id)){
                    return -a[id];
                }
            }
            return 0;
        };
        auto valid = [&](int id) -> bool {
            return id >= 0 && id < n;
        };
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += value(i);
        }
        cout << ans << '\n';
        for (auto qq: queries) {
            set<int> use;
            int l = qq.first;
            int r = qq.second;
            for (int d = -1; d <= 1; d++) {
                use.insert(l + d);
                use.insert(r + d);
            }
            for (int x: use) {
                if (valid(x)) {
                    ans -= value(x);
                }
            }
            swap(a[l], a[r]);
            for (int x: use) {
                if (valid(x)) {
                    ans += value(x);
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}