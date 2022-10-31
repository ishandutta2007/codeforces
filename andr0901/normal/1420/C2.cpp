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
        T ans;
        ans[0][0] = x, ans[1][1] = -x;
        ans[0][1] = ans[1][0] = -INF;
        return ans;
    }

    T merge_tr(T a, T b) {
        T ans;
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    cin >> a;
    Segtree <array <array <int, 2>, 2>> tr(a);
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