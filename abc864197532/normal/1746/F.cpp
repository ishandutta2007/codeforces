#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int mod = 998244353, N = 2e5 + 7, B = 550;

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

mt19937 rng(56562);

void solve() {
    int n, q;
    cin >> n >> q;
    const int C = 30;
    vector <int> v;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], v.pb(a[i]);
    vector <array <int, 4>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0];
        if (queries[i][0] == 1) {
            cin >> queries[i][1] >> queries[i][2], --queries[i][1], v.pb(queries[i][2]);
        } else {
            cin >> queries[i][1] >> queries[i][2] >> queries[i][3], --queries[i][1];
        }
    }
    sort(all(v)), v.resize(unique(all(v)) - v.begin());
    for (int &i : a)
        i = lower_bound(all(v), i) - v.begin();
    for (int i = 0; i < q; ++i) if (queries[i][0] == 1) {
        queries[i][2] = lower_bound(all(v), queries[i][2]) - v.begin();
    }
    int m = v.size();
    vector <bool> ans(q, true);
    for (int t = 0; t < C; ++t) {
        vector <int> val(m);
        for (int i = 0; i < m; ++i)
            val[i] = uniform_int_distribution<int>(0, 1)(rng);
        vector <int> b = a;
        BIT <int> bit(n);
        for (int i = 0; i < n; ++i)
            bit.add(i, val[b[i]]);
        for (int i = 0; i < q; ++i) {
            int t = queries[i][0];
            if (t == 1) {
                int pos = queries[i][1];
                bit.add(pos, val[queries[i][2]] - val[b[pos]]);
                b[pos] = queries[i][2];
            } else {
                int l = queries[i][1], r = queries[i][2], k = queries[i][3];
                if (bit.query(l, r) % k != 0)
                    ans[i] = false;
            }
        }
    }
    for (int i = 0; i < q; ++i) if (queries[i][0] == 2) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}