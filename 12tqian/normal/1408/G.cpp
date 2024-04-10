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
struct DSU {
    vector<int> e;
    void init(int n) {
        e = vector<int>(n, -1);
    }
    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    bool same_set(int a, int b) {
        return get(a) == get(b);
    }
    int size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3>> edges;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == j || i > j) {
                continue;
            }
            edges.push_back({a[i][j], i, j});
        }
    }
    sort(edges.begin(), edges.end());
    auto multiply = [&](vector<mi> x, vector<mi> y) -> vector<mi> { 
        vector<mi> res((int) x.size() + (int) y.size() - 1);
        for (int i = 0; i < (int) x.size(); i++) {
            for (int j = 0; j < (int) y.size(); j++) {
                res[i + j] += x[i] * y[j];
            }
        }
        return res;
    };
    DSU D;
    D.init(n);
    map<int, vector<mi>> dp;
    map<int, int> num;
    for (int i = 0; i < n; i++) {
        dp[i] = {0, 1};
        num[i] = 0;
    }
    for (auto e: edges) {
        int u = e[1];
        int v = e[2];
        if (D.same_set(u, v)) {
            num[D.get(u)]++;
        } else {
            int x = D.get(u);
            int y = D.get(v);
            int new_num = num[x] + num[y] + 1;
            D.unite(u, v);
            int z = D.get(u);
            dp[z] = multiply(dp[x], dp[y]);
            num[z] = new_num;
        }
        if (num[D.get(u)] == D.size(u) * (D.size(u) - 1) / 2) {
            dp[D.get(u)][1] += 1;
        }
    }
    vector<mi> res = dp[D.get(0)];
    res.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
    return 0;
}