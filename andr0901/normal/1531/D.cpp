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

struct Node {
    string col = "";
    int pos_col = -INF;
    bool open = false;
    int mn_unlock = INF;
    int size = 1;
};

Node merge(Node l, Node r) {
    Node ans;
    r.pos_col += l.size;
    r.mn_unlock += l.size;
    if (r.col.empty()) {
        ans.col = l.col;
        ans.pos_col = l.pos_col; 
    } else {
        if (l.open) {
            if (r.mn_unlock < r.pos_col) {
                ans.col = r.col;
                ans.pos_col = r.pos_col;
            } else {
                ans.col = l.col;
                ans.pos_col = l.pos_col;
            }
        } else {
            ans.col = r.col;
            ans.pos_col = r.pos_col;
        }
    }
    ans.mn_unlock = min(l.mn_unlock, r.mn_unlock);
    ans.size = l.size + r.size;
    if (!r.open) {
        if (r.mn_unlock >= INF) {
            ans.open = l.open;
        } else {
            ans.open = false;
        }
    } else {
        ans.open = true;
    }
    return ans;
}

template <typename T>
class SegTree{
private:
    int n;
    vector <T> tr;
    T neutral_tr = Node();

    void upd_node(int i, const string& x) {
        if (x == "lock") {
            tr[i] = {"", -1, true, INF, 1};
        } else if (x == "unlock") {
            tr[i] = {"", -1, false, 0, 1};
        } else {
            tr[i] = {x, 0, false, INF, 1};
        }
    }

    void upd(int v, int vl, int vr, int idx, const string& val) {
        if (vr - vl == 1) {
            upd_node(v, val);
            return;
        }
        int vm = vl + vr >> 1;
        if (idx < vm) {
            upd(2 * v, vl, vm, idx, val);
        } else {
            upd(2 * v + 1, vm, vr, idx, val);
        }
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

    SegTree(int _n) : n(_n) {
        tr.resize(4 * n, neutral_tr);
    }

    void upd(int idx, const string& val) {
        upd(1, 0, n, idx, val);
    }

    T get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};


// template <typename T>
// class Segtree {
// private:
//     int n;
//     vector <T> tr;
//     T neutral_tr = Node();

//     template <typename U>
//     void build(const vector <U>& a) {
//         forn (i, 0, n)
//             tr[i + n] = a[i];
//         for (int i = n - 1; i > 0; i--)
//             tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
//     }
// public:

//     Segtree(int _n) : n(_n) {
//         tr.resize(2 * n, neutral_tr);
//     }

//     T get(int l, int r) {
//         T ans = neutral_tr;
//         for (l += n, r += n; l < r; l /= 2, r /= 2) {
//             if (l % 2)
//                 ans = merge(ans, tr[l++]);
//             if (r % 2)
//                 ans = merge(ans, tr[--r]);
//         }
//         return ans;
//     }

//     void upd_node(int i, const string& x) {
//         if (x == "lock") {
//             tr[i] = {"", -1, true, INF, 1};
//         } else if (x == "unlock") {
//             tr[i] = {"", -1, false, 0, 1};
//         } else {
//             tr[i] = {x, 0, false, INF, 1};
//         }
//     }

//     void upd(int i, const string& x) {
//         for (i += n, upd_node(i, x); i /= 2; i > 0)
//             tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
//     }
// };


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    SegTree<Node> tr(n + 1);
    string tmp = "blue";
    tr.upd(0, tmp);
    for (int i = 0; i < n; ++i) {
        string cur;
        cin >> cur;
        tr.upd(i + 1, cur);
    }
    cout << tr.get(0, n + 1).col << "\n";
    int q;
    cin >> q;
    while (q --> 0) {
        int i;
        string cur;
        cin >> i >> cur;
        tr.upd(i, cur);
        cout << tr.get(0, n + 1).col << "\n";
    }
    return 0;
}