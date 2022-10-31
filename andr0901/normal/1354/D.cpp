#pragma GCC optimize("Ofast")
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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}


template <typename T>
class SegTree{
private: 
    int n;
    vector <T> tr;
    T neutral_tr = INT_MAX;

    T merge_tr(T a, T b) {
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

    void upd(int v, int vl, int vr, int idx, int delta) {
        if (vr - vl == 1) {
            tr[v] += delta;
            return;
        }
        int vm = vl + vr >> 1;
        if (idx < vm) 
            upd(2 * v, vl, vm, idx, delta);
        else
            upd(2 * v + 1, vm, vr, idx, delta);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    T remove(int v, int vl, int vr, int k) {
        if (vr - vl == 1) {
            upd(vl, -1);
            return vl;
        }
        int vm = vl + vr >> 1;
        if (tr[2 * v] >= k)
            return remove(2 * v, vl, vm, k);
        else
            return remove(2 * v + 1, vm, vr, k - tr[2 * v]);
    }

    T get(int v, int vl, int vr, int idx) {
        if (vr - vl == 1)
            return tr[v];
        int vm = vl + vr >> 1;
        if (idx < vm)
            return get(2 * v, vl, vm, idx);
        else
            return get(2 * v + 1, vm, vr, idx);
    }
public:
    template <typename U>
    SegTree(const vector <U>& a) : n(sz(a)) {
        tr.resize(4 * n, neutral_tr);
        build(1, 0, n, a);
    }

    void upd(int idx, int x) {
        upd(1, 0, n, idx, x);
    }

    T remove(int k) {
        return remove(1, 0, n, k);
    }

    T get(int idx) {
        return get(1, 0, n, idx);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1);
    forn (i, 0, n) {
        int x;
        cin >> x;
        a[x]++;
    }
    SegTree <int> tr(a);
    auto output = [&]() -> void {
        forn (i, 1, n + 1)
            cout << tr.get(i) << " ";
        cout << "\n";
    };
    while (q --> 0) {
        int x;
        cin >> x;
        if (x > 0)
            tr.upd(x, 1);
        else
            tr.remove(-x);
        //output();
    }
    forn (i, 1, n + 1)
        if (tr.get(i))
            return cout << i, 0;
    cout << 0;
    return 0;
}