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
    T neutral_tr = 0;

    T merge_tr(T a, T b) {
        return max(a, b);
    }

    template <typename U>
    void build(int v, int vl, int vr, const vector <U>& a) {
        if (vr - vl == 1) {
            tr[v] = a[vl];
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    void upd(int v, int vl, int vr, int i, int x) {
        if (vr - vl == 1) {
            tr[v] = x;
            return;
        }
        int vm = vl + vr >> 1;
        if (i < vm)
            upd(2 * v, vl, vm, i, x);
        else
            upd(2 * v + 1, vm, vr, i, x);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    int get_left(int v, int vl, int vr) {
        if (vr - vl == 1) {
            tr[v] = 0;
            return vl;
        }
        int ans;
        int vm = vl + vr >> 1;
        if (tr[2 * v] > 0)
            ans = get_left(2 * v, vl, vm);
        else
            ans = get_left(2 * v + 1, vm, vr);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
        return ans;
    }

    int get_mx(int v, int vl, int vr) {
        if (vr - vl == 1) {
            tr[v] = 0;
            return vl;
        }
        int ans;
        int vm = vl + vr >> 1;
        if (tr[2 * v] >= tr[2 * v + 1])
            ans = get_mx(2 * v, vl, vm);
        else
            ans = get_mx(2 * v + 1, vm, vr);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
        return ans;
    }
public:
    SegTree(int _n) : n(_n) {
        tr.resize(4 * n, neutral_tr);
    }

    void upd(int i, int x) {
        upd(1, 0, n, i, x);
    }

    int get_left() {
        return get_left(1, 0, n);
    }

    int get_mx() {
        return get_mx(1, 0, n);
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    int lst = 0;
    SegTree<int> tree(q);
    forn (i, 0, q) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int val;
            cin >> val;
            tree.upd(lst++, val);
        } else if (tp == 2) {
            cout << tree.get_left() + 1 << " ";
        } else if (tp == 3) {
            cout << tree.get_mx() + 1 << " ";
        }
    }
    return 0;
}