//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

#define int long long

constexpr int INF = 1e18;

template <typename T>
class Segtree {
private:
    int n;
    vector <T> tr;

    T single(int x) {
        return {{x, -INF}, {-INF, -x}};
    }

    T merge_tr(T a, T b) {
        T ans(2, vector <int> (2, -INF));
        ans[0][0] = max({a[0][0], b[0][0],
                         a[0][1] + b[0][0],
                         a[0][0] + b[1][0]});
        ans[0][1] = max({a[0][1], b[0][1],
                         a[0][1] + b[0][1],
                         a[0][0] + b[1][1]});
        ans[1][0] = max({a[1][0], b[1][0],
                         a[1][1] + b[0][0],
                         a[1][0] + b[1][0]});
        ans[1][1] = max({a[1][1], b[1][1],
                         a[1][1] + b[0][1],
                         a[1][0] + b[1][1]});
        return ans;
    }

    template <typename U>
    void build(int v, int vl, int vr, const vector <U>& a) {
        if (vr - vl == 1) {
            tr[v] = single(a[vl]);
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }
    
    void upd(int v, int vl, int vr, int idx, int x) {
        if (vr - vl == 1) {
            tr[v] = single(x);
            return;
        }
        int vm = vl + vr >> 1;
        if (idx < vm)
            upd(2 * v, vl, vm, idx, x);
        else
            upd(2 * v + 1, vm, vr, idx, x);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }
public:
    template <typename U>
    Segtree(const vector <U>& a) : n(sz(a)) {
        tr.resize(4 * n);
        build(1, 0, n, a);
    }

    T get() {
        return tr[1];
    }

    void upd(int i, int x) {
        upd(1, 0, n, i, x);
    }
};

template <typename T>
class SegTree{
private:
    int n;
    vector <T> tr;
    vector <int> to_add;
    T neutral_tr = INT_MAX;
    int neutral_to_add = INT_MAX;

    T merge_tr(T a, T b) {
        return min(a, b);
    }

    int merge_to_add(int a, int b) {
        return min(a, b);
    }

    template <typename U>
    void build(int v, int vl, int vr, const vector <U>& a) {
        if (vr - vl < 1)
            return;
        if (vr - vl == 1) {
            tr[v] = a[vl];
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    void push(int v, int vl, int vr) {
        if (vr - vl != 1) {
            to_add[2 * v] = merge_to_add(to_add[2 * v], to_add[v]);
            to_add[2 * v + 1] = merge_to_add(to_add[2 * v + 1], to_add[v]);
        }
        tr[v] = merge_to_add(tr[v], to_add[v]);
        to_add[v] = neutral_to_add;
    }

    void upd(int v, int vl, int vr, int l, int r, int x) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return;
        if (l <= vl && vr <= r) {
            to_add[v] = merge_to_add(to_add[v], x);
            push(v, vl, vr);
            return;
        }
        int vm = vl + vr >> 1;
        upd(2 * v, vl, vm, l, r, x), upd(2 * v + 1, vm, vr, l, r, x);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    T get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public:
    template <typename U>
    SegTree(const vector <U>& a) : n(sz(a)) {
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
    }

    SegTree(int _n) : n(_n) {
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    T get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    cin >> a;
    Segtree <vector <vector <int>>> tr(a);
    cout << max(tr.get()[0][0], tr.get()[0][1]) << "\n";
    while (q --> 0) {
        int l, r;
        cin >> l >> r, --l, --r;
        tr.upd(l, a[r]);
        tr.upd(r, a[l]);
        swap(a[l], a[r]);
        cout << max(tr.get()[0][0], tr.get()[0][1]) << "\n";
        cerr << a << "\n";
    }
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}