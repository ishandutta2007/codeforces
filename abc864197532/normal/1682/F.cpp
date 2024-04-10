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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200005, logN = 20, K = 48763;

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
            (val[p] += v) %= mod;
    }
    T query(int p) {
        T ans = 0;
        for (p += offset; p > 0; p -= p & (-p))
            (ans += val[p]) %= mod;
        return ans;
    }
    T query(int l, int r) {
        // query [l, r)
        return (query(r - 1) - query(l - 1) + mod) % mod;
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

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <lli> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector <lli> pre = {0};
    for (int i : b)
        pre.pb(pre.back() + i);
    // abs(pre[i] - pre[l]) * (a[i] - a[i - 1]), i in [l + 1, r)
    vector <array <int, 3>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1], queries[i][2] = i, --queries[i][0];
    }
    sort(all(queries), [&](array <int, 3> i, array <int, 3> j) {
        return pre[i[0]] < pre[j[0]];
    });
    vector <int> p(n);
    iota(all(p), 1);
    sort(all(p), [&](int i, int j) {
        return pre[i] < pre[j];
    });
    BIT <lli> bit1(n), bit2(n);
    for (int i = 1; i < n; ++i) {
        bit1.add(i, -(a[i] - a[i - 1])), bit2.add(i, pre[i] % mod * (a[i] - a[i - 1]) % mod);
    }
    vector <lli> ans(q);
    for (int i = 0, j = 0; i < q; ++i) {
        while (j < p.size() && pre[p[j]] <= pre[queries[i][0]]) {
            int now = p[j];
            bit1.add(now, 2 * (a[now] - a[now - 1])), bit2.add(now, -2 * pre[now] % mod * (a[now] - a[now - 1]) % mod);
            j++;
        }
        lli now1 = bit1.query(queries[i][0] + 1, queries[i][1]);
        lli now2 = bit2.query(queries[i][0] + 1, queries[i][1]);
        ans[queries[i][2]] = (now1 * (pre[queries[i][0]] % mod) + now2) % mod;
    }
    for (lli i : ans) {
        if (i < 0)
            i += mod;
        cout << i << '\n';
    }
}