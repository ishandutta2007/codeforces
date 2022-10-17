#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
        mi ans = 1;
        bool neg = (p < 0);
        p = abs(p);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        if (neg) return 1 / ans;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};
const int M = 4e7;
struct Node {
    int lc;
    int rc;
    int prod;
} t[M];
int cnt;
int modify(int p, int l, int r, int x, int v) {
    int u = ++cnt;
    if (l == r) {
        t[u].prod = 1ll * t[p].prod * v % MOD;
    } else {
        int m = (l + r) / 2;
        if (x <= m) {
            t[u].lc = modify(t[p].lc, l, m, x, v);
            t[u].rc = t[p].rc;
        } else {
            t[u].lc = t[p].lc;
            t[u].rc = modify(t[p].rc, m + 1, r, x, v);
        }
        t[u].prod = 1ll * t[t[u].lc].prod * t[t[u].rc].prod % MOD;
    }
    return u;
}
int query(int p, int l, int r, int x) {
    if (x < l) return 1;
    if (r <= x) return t[p].prod;
    int m = (l + r) / 2;
    return 1ll * query(t[p].lc, l, m, x) * query(t[p].rc, m + 1, r, x) % MOD;
}
template<int SZ> struct Sieve {
    int spf[SZ + 1];
    Sieve() {
        spf[1] = 1;
        for (int i = 2; i <= SZ; i++) {
            spf[i] = i;
        }
        for (int i = 4; i <= SZ; i += 2) {
            spf[i] = 2;
        }
        for (int i = 3; i * i <= SZ; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= SZ; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    vector<pair<int, int>> factor(int x) {
        vector<pair<int, int>> res;
        int cur_prime = -1;
        while (spf[x] != 1) {
            if (cur_prime == spf[x]) {
                res.back().second++;
            } else {
                cur_prime = spf[x];
                res.emplace_back(cur_prime, 1);
            }
            x /= spf[x];
        }
        return res;
    }
};
template<int SZ> struct FastPow {
    vector<int> po[SZ];
    vector<int> ipo[SZ];
    vector<int> over;
    FastPow() {
        over.resize(SZ);
        for (int i = 0; i < SZ; i++) {
            if (i) {
                over[i] = (1 / mi(i)).val;
            }
            po[i].push_back(1);
            ipo[i].push_back(1);
        }
    }
    int power(int base, int exp) {
        if (base == 0) {
            return 0;
        }
        if (exp == 0) {
            return 1;
        }
        while ((int) po[base].size() <= abs(exp)) {
            po[base].push_back((1LL * po[base].back() * base) % MOD);
            ipo[base].push_back((1LL * ipo[base].back() * over[base]) % MOD);
        }
        if (exp > 0) {
            return po[base][exp];
        } else {
            return ipo[base][-exp];
        }
    }
};
int main() {
    const int MAX = 2e5 + 5;
    const int INF = 1e9;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pair<int, int>>> factors(n);
    Sieve<MAX> sieve;
    FastPow<MAX> F;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        factors[i] = sieve.factor(a[i]);
    }
    vector<vector<pair<int, int>>> primes(MAX);
    for (int i = 0; i < MAX; i++) {
        primes[i].emplace_back(n, INF);
    }
    vector<int> id(MAX, n);
    t[0].prod = 1;
    vector<int> rt(n + 1, 0);
    int cur_time = 0;
    for (int i = n - 1; i >= 0; i--) {
        rt[i] = rt[i + 1];
        for (auto pp : factors[i]) {
            int p = pp.first;
            int e = pp.second;
            primes[p].emplace_back(i, e);
            int bef = 0;
            int size = (int) primes[p].size();
            while (primes[p][size - 1].second >= primes[p][size - 2].second) {
                int sub = bef - primes[p][size - 2].second;
                rt[i] = modify(rt[i], 0, n - 1, primes[p][size - 2].first, F.power(p, sub));
                bef = primes[p][size - 2].second;
                primes[p][size - 2] = primes[p][size - 1];
                primes[p].pop_back();
                size--;
            }
            rt[i] = modify(rt[i], 0, n - 1, primes[p][size - 1].first, F.power(p, e));
            if (size > 2) {
                int sub = bef - primes[p][size - 1].second;
                rt[i] = modify(rt[i], 0, n - 1, primes[p][size - 2].first, F.power(p, sub));
            }
        }
    }
    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x = (x + last) % n + 1;
        y = (y + last) % n + 1;
        int l = min(x - 1, y - 1);
        int r = max(x - 1, y - 1);
        last = query(rt[l], 0, n - 1, r);
        cout << last << '\n';
    }
    return 0;
}