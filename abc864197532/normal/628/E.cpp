#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300005;

template <typename T>
struct BIT {
    // single point add, prefix query sum
    vector <T> val;
    int n, offset;
    BIT () = default;
    BIT (int _n, int _offset = 3) : n(_n + _offset * 2), offset(_offset) {
        val.assign(n, 0);
    }
    void add(int p, T v) {
        for (p += offset; p < n; p += p & (-p))
            val[p] += v;
    }
    T query(int p) {
        T ans = 0;
        for (p += offset; p > 0; p -= p & (-p))
            ans += val[p];
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
};

void solve () {
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vv <int> a(n, m, 1 << 30), b(n, m, 1 << 30);
    for (int i = 0; i < n; ++i) {
        int now = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'z')
                now++;
            else
                now = 0;
            a[i][j] = min(a[i][j], now);
        }
        now = 0;
        for (int j = m - 1; ~j; --j) {
            if (s[i][j] == 'z')
                now++;
            else
                now = 0;
            b[i][j] = min(b[i][j], now);
        }
    }
    for (int d = 0; d < n + m - 1; ++d) {
        int now = 0;
        for (int i = 0; i < n; ++i) {
            int j = d - i;
            if (j < 0 || j >= m)
                continue;
            if (s[i][j] == 'z')
                now++;
            else
                now = 0;
            b[i][j] = min(b[i][j], now);
        }
        now = 0;
        for (int i = n - 1; ~i; --i) {
            int j = d - i;
            if (j < 0 || j >= m)
                continue;
            if (s[i][j] == 'z')
                now++;
            else
                now = 0;
            a[i][j] = min(a[i][j], now);
        }
    }
    ll ans = 0;
    for (int d = 0; d < n + m - 1; ++d) {
        vector <pii> val;
        for (int i = 0; i < n; ++i) {
            int j = d - i;
            if (j < 0 || j >= m)
                continue;
            val.eb(a[i][j], b[i][j]);
        }
        int sz = val.size();
        vector <vector <int>> pos(sz + 1);
        for (int i = 0; i < sz; ++i) if (val[i].Y) {
            int l = i - val[i].Y + 1;
            pos[l].pb(i);
        }
        BIT <int> bit(sz);
        for (int i = 0; i < sz; ++i) {
            for (int p : pos[i])
                bit.add(p, 1);
            int r = i + val[i].X;
            ans += bit.query(i, r);
        }
    }
    cout << ans << '\n';
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}