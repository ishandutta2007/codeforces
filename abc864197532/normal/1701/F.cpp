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
const int mod = 998244353, N = 200087;

array <ll, 3> operator + (array <ll, 3> a, array <ll, 3> b) {
    return {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
}

template <typename T>
struct Seg {
    // range add value, range query sum
    // 0-indexed, [l, r)
    int l, r, m;
    T val;
    long long lz;
    Seg *ch[2];
    Seg () = default;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val({0, 0, 0}), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    Seg (int _l, int _r, vector <T> &a) : l(_l), r(_r), m(l + r >> 1), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            val = a[l];
        }
    }
    void pull() {
        val = ch[0]->val + ch[1]->val;
    }
    void give(long long x) {
        lz += x;
        val[2] += (val[1] + val[1] + (x - 1) * val[0]) * x / 2;
        val[1] += x * val[0];
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz), lz = 0;
    }
    void set(int p, T v) {
        if (r - l == 1) {
            val = v;
        } else {
            push();
            ch[p >= m]->set(p, v), pull();
        }
    }
    void add(int a, int b, long long v) {
        if (a <= l && r <= b) {
            give(v);
        } else {
            push();
            if (a < m)
                ch[0]->add(a, b, v);
            if (m < b)
                ch[1]->add(a, b, v);
            pull();
        }
    }
    T query(int a, int b) {
        if (a <= l && r <= b)
            return val;
        push();
        T ans = 0;
        if (a < m)
            ans = ans + ch[0]->query(a, b);
        if (m < b)
            ans = ans + ch[1]->query(a, b);
        return ans;
    }
};

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

void solve() {
    int q, d;
    cin >> q >> d;
    Seg <array <ll, 3>> root(0, N);
    BIT <int> bit(N);
    vector <bool> vis(N);
    while (q--) {
        int x; cin >> x;
        if (!vis[x]) {
            vis[x] = true;
            root.add(max(x - d, 0), x, 1);
            bit.add(x, 1);
            int res = bit.query(x + 1, min(x + d + 1, N));
            root.set(x, {1, res, 1ll * res * (res - 1) / 2});
        } else {
            vis[x] = false;
            root.add(max(x - d, 0), x, -1);
            bit.add(x, -1);
            root.set(x, {0, 0, 0});
        }
        cout << root.val[2] << '\n';
    }
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}