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
const int mod = 998244353, N = 100005, logN = 20, M = 6e6;

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

int main () {
    owo;
    // min(r_i, r_j) >= |x_i - x_j|, |f_i - f_j| <= k
    // r_i >= |x_i - x_j|
    int n, k;
    cin >> n >> k;
    vector <int> x(n), r(n), f(n);
    vector <vector <int>> v(10001);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> r[i] >> f[i], v[f[i]].pb(x[i]);
    vector <BIT <int>> bit(10001);
    for (int i = 1; i <= 10000; ++i) if (!v[i].empty()) {
        sort(all(v[i])), v[i].resize(unique(all(v[i])) - v[i].begin());
        bit[i] = BIT <int> (v[i].size());
    }
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return r[i] > r[j];
    });
    lli ans = 0;
    for (int i : p) {
        for (int j = f[i] - k; j <= f[i] + k; ++j) if (j >= 1 && j <= 10000) {
            // r_i >= |x_i - x_j|
            // query sum [x_i - r_i, x_i + r_i]
            int L = lower_bound(all(v[j]), x[i] - r[i]) - v[j].begin();
            int R = lower_bound(all(v[j]), x[i] + r[i] + 1) - v[j].begin();
            ans += bit[j].query(L, R);
        }
        bit[f[i]].add(lower_bound(all(v[f[i]]), x[i]) - v[f[i]].begin(), 1);
    }
    cout << ans << endl;
}