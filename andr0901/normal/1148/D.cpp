#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()


struct SegTree{
private: 
    int n;
    vector <pii> tr;
    vector <int> to_add;
    pii neutral_tr = {INT_MAX, INT_MAX};
    int neutral_to_add = INT_MIN;

    pii merge_tr(pii a, pii b) {
        if (a.fs < b.fs)
            return a;
        else 
            return b;
    }

    int merge_to_add(int a, int b) {
        return max(a, b);
    }

    void build(int v, int vl, int vr, const vector <pii>& a) {
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
        tr[v].fs = merge_to_add(tr[v].fs, to_add[v]);
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

    pii get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public: 
    SegTree(const vector <pii>& a) {
        n = sz(a);
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    pii get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};


struct SegTree1 {
private: 
    int n;
    vector <pii> tr;
    vector <int> to_add;
    pii neutral_tr = {INT_MAX, INT_MAX};
    int neutral_to_add = INT_MIN;

    pii merge_tr(pii a, pii b) {
        if (a.sc < b.sc)
            return a;
        else 
            return b;
    }

    int merge_to_add(int a, int b) {
        return max(a, b);
    }

    void build(int v, int vl, int vr, const vector <pii>& a) {
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
        tr[v].sc = merge_to_add(tr[v].sc, to_add[v]);
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

    pii get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public: 
    SegTree1(const vector <pii>& a) {
        n = sz(a);
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    pii get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a, b;
    vector <int> where(2 * n + 1);
    forn (i, 0, n) {
        pii c;
        cin >> c.fs >> c.sc;
        if (c.fs < c.sc) 
            a.pb(c);
        else 
            b.pb(c);
        where[c.fs] = where[c.sc] = i;
    } 
    vector <int> ans1;
    if (sz(a)) {
        sort(all(a), [&](pii a, pii b){return a.fs < b.fs;});
        vector <int> where_fs(2 * n + 1), where_sc(2 * n + 1);
        forn (i, 0, sz(a))
            where_fs[a[i].fs] = i, where_sc[a[i].sc] = i;
        SegTree tr(a);
        
        int prev = 0;
        while (true) {
            pii q = tr.get(prev, sz(a));
            //cout << q.fs << " " << q.sc << "\n";
            if (q.fs == INT_MAX)
                break;
            ans1.pb(where[q.fs]);
            prev = where_sc[q.fs];
            tr.upd(where_fs[q.fs], where_fs[q.fs] + 1, INT_MAX);
        }
    }
    vector <int> ans2;
    if (sz(b)) {
        sort(all(b), [&](pii a, pii b){return a.sc < b.sc;});
        vector <int> where_fs(2 * n + 1), where_sc(2 * n + 1);
        forn (i, 0, sz(b))
            where_fs[b[i].fs] = i, where_sc[b[i].sc] = i;
        SegTree1 tr(b);
        int prev = 0;
        while (true) {
            pii q = tr.get(prev, sz(b));
            //cout << q.fs << " " << q.sc << "\n";
            if (q.sc == INT_MAX)
                break;
            ans2.pb(where[q.fs]);
            prev = where_fs[q.sc];
            tr.upd(where_sc[q.sc], where_sc[q.sc] + 1, INT_MAX);
        }
    }
    if (sz(ans1) > sz(ans2)) {
        cout << sz(ans1) << "\n";
        reverse(all(ans1));
        for (int i : ans1)
            cout << i + 1 << " ";
    } else {
        cout << sz(ans2) << '\n';
        for (int i : ans2)
            cout << i + 1 << " ";
    }
    return 0;
}