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

template <typename T>
class SegTree{
private:
    int n;
    vector <T> tr;
    vector <int> to_add;
    T neutral_tr = INT_MAX;

    int merge_tr(int a, int b) {
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
            to_add[2 * v] += to_add[v];
            to_add[2 * v + 1] += to_add[v];
        }
        tr[v] += to_add[v];
        to_add[v] = 0;
    }

    void upd(int v, int vl, int vr, int l, int r, int x) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return;
        if (l <= vl && vr <= r) {
            to_add[v] += x;
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
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, 0);
        build(1, 0, n, a);
    }

    SegTree(int _n) : n(_n) {
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, 0);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    T get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};


signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<pii> a(n);
    forn (i, 0, n) {
        cin >> a[i].fs;
        a[i].sc = i;
    }
    sort(rall(a));
    SegTree<int> tr(vector<int>(n, 0));
    int ans = 0;
    for (auto [x, i] : a) {
        if (x + tr.get(i, n) >= 0) {
            ++ans;
            tr.upd(i, n, x);
        }
        // forn (j, 0, n) {
        //     cerr << tr.get(j, j + 1) << " ";
        // }
        // cerr << "\n";
    }
    cout << ans << "\n";
    return 0;
}