#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1600087, logN = 19, K = 111, M = 1000006, C = 500;

template <typename T>
struct BIT {
    // single point add, prefix query sum
    vector <T> val;
    vector <int> chg;
    int n, offset;
    BIT () = default;
    BIT (int _n, int _offset = 3) : n(_n + _offset * 2), offset(_offset) {
        val.assign(n, -1 << 30);
    }
    void add(int p, T v) {
        chg.pb(p);
        for (p += offset; p < n; p += p & (-p))
            val[p] = max(val[p], v);
    }
    T query(int p) {
        T ans = -1 << 30;
        for (p += offset; p > 0; p -= p & (-p))
            ans = max(ans, val[p]);
        return ans;
    }
    T query(int l, int r) {
        // query [l, r)
        return query(r - 1) - query(l - 1);
    }
    int kth (int k) {
        // 1-index, return kth smallest number
        // 1 <= k && k <= current size
        int ans = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (ans + i < n && val[ans + i] < k) k -= val[ans += i];
        }
        return ans - offset + 1;
    }
    void reset() {
        while (!chg.empty()) {
            int p = chg.back(); chg.pop_back();
            for (p += offset; p < n; p += p & (-p))
                val[p] = -1 << 30;
        }
    }
};

int main () {
    owo;
    // dp[i] = (v * (t[i] - t[j]) >= abs(a[i] - a[j])) dp[j] + 1
    // dp[i] = a[i] >  a[j] : v * t[i] - a[i] >= v * t[j] - a[j]
    //         a[i] <= a[j] : v * t[i] + a[i] >= v * t[j] + a[j]
    int n, v;
    cin >> n >> v;
    vector <lli> t(n + 1), a(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> t[i + 1];
    for (int i = 0; i < n; ++i)
        cin >> a[i + 1];
    vector <int> v1(n + 1), v2(n + 1);
    auto to = [&](vector <lli> a) {
        vector <lli> v = a;
        sort(all(v)), v.resize(unique(all(v)) - v.begin());
        vector <int> res;
        for (lli i : a)
            res.pb(lower_bound(all(v), i) - v.begin());
        return res;
    };
    {
        vector <lli> tmp(n + 1);
        for (int i = 0; i <= n; ++i)
            tmp[i] = t[i] * v - a[i];
        v1 = to(tmp);
    }
    {
        vector <lli> tmp(n + 1);
        for (int i = 0; i <= n; ++i)
            tmp[i] = t[i] * v + a[i];
        v2 = to(tmp);
    }
    vector <int> dp(n + 1, -1 << 30), p(n + 1);
    dp[0] = 0;
    BIT <int> bit(n + 2);
    function <void(int, int)> solve = [&](int l, int r) {
        if (r - l == 1)
            return;
        int m = l + r >> 1;
        solve(l, m);
        iota(p.begin() + l, p.begin() + r, l);
        sort(p.begin() + l, p.begin() + m, [&](int i, int j) {return a[i] < a[j];});
        sort(p.begin() + m, p.begin() + r, [&](int i, int j) {return a[i] < a[j];});
        // caculate ans
        // a[j] < a[i] : v1
        bit.reset();
        for (int i = l, j = m; j < r; ++j) {
            while (i < m && a[p[i]] < a[p[j]]) {
                bit.add(v1[p[i]], dp[p[i]]), i++;
            }
            dp[p[j]] = max(dp[p[j]], bit.query(v1[p[j]]) + 1);
        }
        // a[j] >= a[i] : v2
        bit.reset();
        for (int i = m - 1, j = r - 1; j >= m; --j) {
            while (i >= l && a[p[i]] >= a[p[j]]) {
                bit.add(v2[p[i]], dp[p[i]]), i--;
            }
            dp[p[j]] = max(dp[p[j]], bit.query(v2[p[j]]) + 1);
        }
        solve(m, r);
    };
    solve(0, n + 1);
    test(dp);
    cout << *max_element(all(dp)) << '\n';
}