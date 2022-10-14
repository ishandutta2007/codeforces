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
struct Seg {
    // range add value, range query sum
    // 0-indexed, [l, r)
    int l, r, m;
    T val;
    long long lz;
    Seg *ch[2];
    Seg () = default;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val(0), lz(0) {
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
        val = min(ch[0]->val, ch[1]->val);
    }
    void give(long long x) {
        lz += x, val += x;
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz), lz = 0;
    }
    void set(int p, T v) {
        if (r - l == 1) {
            val = v;
        } else {
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

void solve () {
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; ++i)
        cin >> a[i] >> b[i];
    vector <vector <pii>> adj(n);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u].eb(v, w);
    }
    Seg <ll> root(0, n);
    for (int i = 1; i < n; ++i) {
        root.add(i, i + 1, b[i - 1]);
    }
    vector <ll> val(n);
    for (int i = 0; i < n; ++i) {
        for (auto [u, w] : adj[i]) {
            root.add(0, u + 1, w);
        }
        val[i] = root.val;
    }
    multiset <ll> S;
    for (int i = 0; i < n; ++i) {
        S.insert(val[i] + (i + 1 < n ? a[i] : 0));
    }
    cout << *S.begin() << '\n';
    while (q--) {
        int p, x; cin >> p >> x, --p;
        S.erase(S.lower_bound(val[p] + a[p]));
        a[p] = x;
        S.insert(val[p] + x);
        cout << *S.begin() << '\n';
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