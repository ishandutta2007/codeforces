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
    pii neutral_tr = {INT_MAX, INT_MIN};
    int neutral_to_add = 0;

    pii merge_tr(pii a, pii b) {
        return {min(a.fs, b.fs), max(a.sc, b.sc)};
    }

    int merge_to_add(int a, int b) {
        return a + b;
    }

    void build(int v, int vl, int vr, const vector <int>& a) {
        if (vr - vl < 1)
            return;
        if (vr - vl == 1) {
            tr[v] = {a[vl], a[vl]};
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
    SegTree(const vector <int>& a) {
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
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <pii> b(m);
    set <int> events;
    events.insert(0);
    forn (i, 0, m) {
        cin >> b[i].fs >> b[i].sc, b[i].fs--, b[i].sc--;
        events.insert(b[i].fs), events.insert(b[i].fs - 1), events.insert(b[i].fs + 1);
        events.insert(b[i].sc), events.insert(b[i].sc - 1), events.insert(b[i].sc + 1);
    }
    int ans = -1, ans_idx;
    SegTree c(a);
    for (auto i : events) {
        if (!(0 <= i && i < n))
            continue;
        forn (j, 0, m) 
            if (!(b[j].fs <= i && i <= b[j].sc))
                c.upd(b[j].fs, b[j].sc + 1, -1);
        pii q = c.get(0, sz(a));
        //cout << q.fs << " " << q.sc << "\n";
        if (q.sc - q.fs > ans) 
            ans = q.sc - q.fs, ans_idx = i;
        forn (j, 0, m) 
            if (!(b[j].fs <= i && i <= b[j].sc))
                c.upd(b[j].fs, b[j].sc + 1, 1);
    }
    cout << ans << "\n";
    int cnt = 0;
    forn (j, 0, m) 
        if (!(b[j].fs <= ans_idx && ans_idx <= b[j].sc))
            cnt++;
    cout << cnt << "\n";
    forn (j, 0, m) 
        if (!(b[j].fs <= ans_idx && ans_idx <= b[j].sc))
            cout << j + 1 << " ";
    return 0;
}