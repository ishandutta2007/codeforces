#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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


class SegTree{
private: 
    int n;
    vector <int> tr, to_add;
    int neutral_tr = 0, neutral_to_add = INT_MIN;

    int merge_tr(int a, int b) {
        return a + b;
    }

    int merge_to_add(int a, int b) {
        return max(a, b);
    }

    void build(int v, int vl, int vr, const vector <int>& a) {
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

    int get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }

    void upd(int v, int vl, int vr, int idx, int val) {
        push(v, vl, vr);
        if (vr - vl == 1) {
            tr[v] = val;
            return;
        }
        int vm = vl + vr >> 1;
        if (idx < vm)
            upd(2 * v, vl, vm, idx, val);
        else 
            upd(2 * v + 1, vm, vr, idx, val);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }
public: 
    SegTree(const vector <int>& a) {
        n = sz(a);
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
    }

    void upd(int i, int x) {
        upd(1, 0, n, i, x);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    SegTree b(a);
    int q;
    cin >> q;
    while (q --> 0) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int idx, val;
            cin >> idx >> val, idx--;
            b.upd(idx, val);
        } else {
            int x;
            cin >> x;
            b.upd(0, n, x);
        }
        /*forn (i, 0, n) 
            cout << b.get(i, i + 1) << " ";
        cout << "\n";*/
    }
    forn (i, 0, n) 
        cout << b.get(i, i + 1) << " ";
    return 0;
}