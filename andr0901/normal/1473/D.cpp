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

constexpr int INF = 1e9;

struct Node{
    int lst;
    int mn;
    int mx;
};

Node merge(Node a, Node b) {
    Node c;
    c.lst = a.lst + b.lst;
    c.mn = min(a.mn, a.lst + b.mn);
    c.mx = max(a.mx, a.lst + b.mx);
    return c;
}

template <typename T>
class SegTree{
private:
    int n;
    vector <T> tr;
    T neutral_tr = {0, INF, -INF};

    void build(int v, int vl, int vr, const string& a) {
        if (vr - vl == 1) {
            if (a[vl] == '#')
                tr[v] = {0, 0, 0};
            if (a[vl] == '-')
                tr[v] = {-1, -1, 0};
            if (a[vl] == '+')
                tr[v] = {1, 0, 1};
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge(tr[2 * v], tr[2 * v + 1]);
    }

    T get(int v, int vl, int vr, int l, int r) {
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public:
    SegTree(const string& a) : n(sz(a)) {
        tr.resize(4 * n, neutral_tr);
        build(1, 0, n, a);
    }

    T get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

/*
template <typename T>
class Segtree {
private:
    int n;
    vector <T> tr;
    T neutral_tr = {0, INF, -INF};

    void build(const string& a) {
        forn (i, 0, n) {
            if (a[i] == '#')
                tr[i + n] = {0, 0, 0};
            if (a[i] == '-')
                tr[i + n] = {-1, -1, 0};
            if (a[i] == '+')
                tr[i + n] = {1, 0, 1};
        }
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    Segtree(const string& a) : n(sz(a)) {
        tr.resize(2 * n);
        build(a);
    }

    T get(int l, int r) {
        T ans = neutral_tr;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                ans = merge(tr[l++], ans);
            if (r % 2)
                ans = merge(ans, tr[--r]);
        }
        return ans;
    }
};*/

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "#" + s;
    cerr << s << "\n";
    SegTree<Node> tr(s);
    cerr << tr.get(1, n + 1).mx << " " << tr.get(1, n + 1).mn << " " << tr.get(1, n + 1).lst << ":\n";
    cerr << tr.get(0, n + 1).mx << " " << tr.get(0, n + 1).mn << " " << tr.get(0, n + 1).lst << ":\n";
    while (q --> 0) {
        int l, r;
        cin >> l >> r;
        auto L = tr.get(0, l);
        auto R = tr.get(r + 1, n + 1);
        auto ans = merge(L, R);
        if (r == 1)
            ans = R;
        if (l == n)
            ans = L;
        cerr << ans.mx << " " << ans.mn << " " << ans.lst << "\n";
        cout << ans.mx - ans.mn + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}