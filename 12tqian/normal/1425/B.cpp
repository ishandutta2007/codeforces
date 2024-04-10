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
template<class T> struct nvector {
    vector<T> pos;
    T zero;
    vector<T> neg;
    nvector() {
        zero = T();
    }
    nvector(int sz) {
        zero = T();
        resize(sz);
    }
    nvector(int sz, T val) {
        resize(sz);
        zero = val;
        for (int i = 0; i < (int) pos.size(); i++) {
            pos[i] = val;
            neg[i] = val;
        }
    }
    void resize(int sz) {
        pos.resize(sz);
        neg.resize(sz);
    }
    void reset() {
        zero = T();
        for (int i = 0; i < (int) pos.size(); i++) {
            pos[i] = T();
        }
        for (int i = 0; i < (int) neg.size(); i++) {
            neg[i] = T();
        }
    }
    T& operator[] (int i) {
        if (i == 0) {
            return zero;
        } else if (i > 0) {
            while ((int) pos.size() <= i - 1) {
                pos.push_back(T());
            }
            return pos[i - 1];
        } else {
            while ((int) neg.size() <= -i - 1) {
                neg.push_back(T());
            }
            return neg[-i - 1];
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);
    vis[0] = true;
    vector<int> a;
    for (int i = 1; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        int cnt = 1;
        function<void(int)> dfs = [&](int src) {
            cnt++;
            vis[src] = true;
            for (int nxt: adj[src]) {
                if (vis[nxt]) {
                    continue;
                }
                dfs(nxt);
            }
        };
        dfs(i);
        a.push_back(cnt);
    }
    int sz = (int) a.size();
    if (sz == 0) {
        cout << 0 << '\n';
        return 0;
    }
    if (sz == 1) {
        cout << 2 << '\n';
        return 0;
    }
    sort(a.begin(), a.end());
    vector<nvector<mi>> pre(sz);
    vector<nvector<mi>> suf(sz);
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            pre[i][a[i]] = 1;
            pre[i][-a[i]] = 1;
            pre[i][0] = 1;
        } else {
            for (int j = -m; j <= m; j++) {
                if (pre[i - 1][j] == 0) {
                    continue;
                }
                pre[i][j + a[i]] += pre[i - 1][j];
                pre[i][j - a[i]] += pre[i - 1][j];
                pre[i][j] += pre[i - 1][j];
            }
        }
    }
    for (int i = sz - 1; i >= 0; i--) {
        if (i == sz - 1) {
            suf[i][a[i]] = 1;
            suf[i][-a[i]] = 1;
            suf[i][0] = 1;
        } else {
            for (int j = -m; j <= m; j++) {
                if (suf[i + 1][j] == 0) {
                    continue;
                }
                suf[i][j + a[i]] += suf[i + 1][j];
                suf[i][j - a[i]] += suf[i + 1][j];
                suf[i][j] += suf[i + 1][j];
            }
        }
    }
    mi ans = 0;
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            for (int j = -m; j <= m; j++) {
                if (abs(j) < a[i] - 1) {
                    ans += 2 * suf[i + 1][j];
                }
            }
        } else if (i == sz - 1) {
            for (int j = -m; j <= m; j++ ){
                if (abs(j) < a[i] - 1) {
                    ans += 2 * pre[i - 1][j];
                }
            }
        } else {
            nvector<mi> sum;
            for (int j = -m; j <= m; j++) {
                sum[j] = sum[j - 1] + suf[i + 1][j];
            }
            auto get = [&](int l, int r) -> mi {
                l = max(l, -m);
                r = min(r, m);
                if (l > r) {
                    return 0;
                }
                return sum[r] - sum[l - 1];
            };
            for (int j = -m; j <= m; j++) {
                ans += 2 * pre[i - 1][j] * get(1 - a[i] - j + 1, a[i] - 1 - j - 1);
            }
        }
    }
    for (int i = 0; i < sz; i++) {
        pre[i].reset();
        suf[i].reset();
    }
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            pre[i][a[i]] = 1;
            pre[i][-a[i]] = 1;
        } else {
            for (int j = -m; j <= m; j++) {
                if (pre[i - 1][j] == 0) {
                    continue;
                }
                pre[i][j + a[i]] += pre[i - 1][j];
                pre[i][j - a[i]] += pre[i - 1][j];
            }
        }
    }
    for (int i = sz - 1; i >= 0; i--) {
        if (i == sz - 1) {
            suf[i][a[i]] = 1;
            suf[i][-a[i]] = 1;
        } else {
            for (int j = -m; j <= m; j++) {
                if (suf[i + 1][j] == 0) {
                    continue;
                } 
                suf[i][j + a[i]] += suf[i + 1][j];
                suf[i][j - a[i]] += suf[i + 1][j];
            }
        }
    }
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            ans += 2 * suf[i + 1][a[i] - 1];
            if (a[i] != 1) {
                ans += 2 * suf[i + 1][1 - a[i]];
            }
        } else if (i == sz - 1) {
            ans += 2 * pre[i - 1][a[i] - 1];
            if (a[i] != 1) {
                ans += 2 * pre[i - 1][1 - a[i]];
            }
        } else {
            for (int j = -m; j <= m; j++) {
                int k1 = a[i] - 1 - j;
                int k2 = 1 - a[i] - j;
                if (-m <= k1 && k1 <= m) {
                    ans += 2 * pre[i - 1][j] * suf[i + 1][k1];
                    if (pre[i - 1][j] != 0 && suf[i + 1][k1] != 0) {
                        dbg(i, j, k1);
                    }
                }
                if (a[i] != 1 && -m <= k2 && k2 <= m) {
                    ans += 2 * pre[i - 1][j] * suf[i + 1][k2];
                }   
            }
        }
    }
    ans += pre[sz - 1][0];
    cout << ans << '\n';
    return 0;
}