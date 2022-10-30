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

template <typename T>
class SegTree{
private:
    int n;
    vector <T> tr;
    vector <int> to_add;
    T neutral_tr = {0, 0};
    int neutral_to_add = -1;

    T merge_tr(T a, T b) {
        return {a.fs + b.fs, a.sc + b.sc};
    }

    void build(int v, int vl, int vr, const string& a) {
        if (vr - vl < 1)
            return;
        if (vr - vl == 1) {
            tr[v] = {0, 0};
            if (a[vl] == '0')
                tr[v].fs++;
            else
                tr[v].sc++;
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    void push(int v, int vl, int vr) {
        if (to_add[v] == -1) {
            return;
        }
        if (vr - vl != 1) {
            to_add[2 * v] = to_add[2 * v + 1] = to_add[v];
        }
        if (to_add[v] != -1) {
            tr[v] = {0, 0};
            if (to_add[v] == 0)
                tr[v].fs += vr - vl;
            else
                tr[v].sc += vr - vl;
        }
        to_add[v] = neutral_to_add;
    }

    void upd(int v, int vl, int vr, int l, int r, int x) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return;
        if (l <= vl && vr <= r) {
            to_add[v] = x;
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
    SegTree(const string& a) : n(sz(a)) {
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
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
    string a, b;
    cin >> a >> b;
    vector<pii> queries(q);
    forn (i, 0, q) {
        cin >> queries[i].fs >> queries[i].sc;
        queries[i].fs--;
    }
    SegTree<pii> tr(b);
    for (int i = q - 1; i >= 0; --i) {
        auto [l, r] = queries[i];
        auto [zeroes, ones] = tr.get(l, r);
        if (zeroes > ones)
            tr.upd(l, r, 0);
        if (zeroes == ones) {
            cout << "NO\n";
            return;
        }
        if (zeroes < ones)
            tr.upd(l, r, 1);
        /*forn (j, 0, n) {
            auto [k, m] = tr.get(j, j + 1);
            if (k == 1)
                cerr << '0';
            else
                cerr << '1';
        }
        cerr << "\n";*/
    }
    forn (i, 0, n) {
        auto [zeroes, ones] = tr.get(i, i + 1);
        if (a[i] == '0' && zeroes == 0) {
            cout << "NO\n";
            return;
        }
        if (a[i] == '1' && ones == 0) {
            cout << "NO\n";
            return;
        }
    }
    cerr << "---\n";
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}