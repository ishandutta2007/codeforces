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

const int INF = 1e9;

template <typename T>
class SegTree{
private: 
    int n;
    vector <T> tr;
    vector <int> to_add;
    T neutral_tr = INF;
    int neutral_to_add = 0;

    T merge_tr(T a, T b) {
        return min(a, b);
    }

    int merge_to_add(int a, int b) {
        return a + b;
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
        tr[v] += to_add[v];
        to_add[v] = 0;
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

    int find_zero(int v, int vl, int vr) {
        push(v, vl, vr);
        if (vr - vl == 1)
            return vl;
        int vm = vl + vr >> 1;
        push(2 * v + 1, vm, vr);
        if (tr[2 * v + 1] == 0)
            return find_zero(2 * v + 1, vm, vr);
        else
            return find_zero(2 * v, vl, vm);
    }

public:
    template <typename U>
    SegTree(const vector <U>& a) : n(sz(a)) {
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
    }

    SegTree(int _n) : n(_n) {
        tr.resize(4 * n, 0), to_add.resize(4 * n, neutral_to_add);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    T get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    int find_zero() {
        if (get(0, n) > 0)
            return -1;
        return find_zero(1, 0, n);
    }
};

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    forn (i, 0, n) {
        cin >> a[i];
        a[i]--;
        a[i] = i - a[i];
        if (a[i] < 0)
            a[i] = INF;
    }
    vector <pii> b(q);
    forn (i, 0, q) {
        cin >> b[i].fs >> b[i].sc;
        b[i].sc = n - b[i].sc - 1;
    }
    SegTree <int> queries(q);
    vector <pii> l(q), r(q);
    vector <int> where(q);
    forn (i, 0, q) {
        l[i] = {b[i].fs, i};
        r[i] = {b[i].sc, i};
        cerr << l[i].fs << " " << r[i].fs << "\n";
    }
    cerr << "---\n---\n";
    sort(rall(l)), sort(all(r));
    forn (i, 0, q)
        where[r[i].sc] = i;
    vector <int> ans(q, -1);
    SegTree <int> tr(a);
    int k = 0;
    while (true) {
        int i = tr.find_zero();
        cerr << i << ":\n";
        if (i == -1)
            break;
        while (k < q && l[k].fs > i) {
            int idx = l[k].sc;
            ans[idx] = queries.get(where[idx], where[idx] + 1);
            ++k;
        }
        int j = lower_bound(all(r), make_pair(i, -INF)) - r.begin();
        queries.upd(j, q, 1);
        tr.upd(i, i + 1, INF);
        tr.upd(i + 1, n, -1);
        cerr << "\n";
        /*forn (t, 0, q)
            cerr << queries.get(t, t + 1) << " ";*/
        cerr << "\n---\n";
    }
    forn (i, 0, q) {
        if (ans[i] == -1)
            cout << queries.get(where[i], where[i] + 1);
        else
            cout << ans[i];
        cout << "\n";
    }
    return 0;
}