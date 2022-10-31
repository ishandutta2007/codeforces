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
#define int long long


struct SegTree{
private: 
    int n;
    vector <int> tr, to_add;
    int neutral_tr = 0, neutral_to_add = 0;

    int merge_tr(int a, int b) {
        return a + b;
    }

    int merge_to_add(int a, int b) {
        return a + b;
    }

    void build(int v, int vl, int vr, vector <int>& a) {
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
public: 
    SegTree(vector <int> a = vector <int> (0)) {
        n = sz(a);
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

vector <vector <int>> gr;
vector <vector <pii>> queries;
vector <int> ans;
SegTree tr;

void dfs(int v, int p, int d) {
    for (pii i : queries[v]) 
        tr.upd(d, d + i.fs + 1, i.sc);
    for (auto u : gr[v])
        if (u != p)
            dfs(u, v, d + 1);
    ans[v] = tr.get(d, d + 1);
    for (pii i : queries[v])
        tr.upd(d, d + i.fs + 1, -i.sc);
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr = vector <vector <int>> (n);
    queries = vector <vector <pii>> (n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), gr[u].pb(v);
    }
    int q;
    cin >> q;
    while (q --> 0) {
        int v, d, x;
        cin >> v >> d >> x, v--;
        queries[v].eb(d, x);
    }
    ans = vector <int> (n);
    tr = SegTree(vector <int> (n));
    dfs(0, -1, 0);
    for (int i : ans)
        cout << i << " ";
    return 0;
}