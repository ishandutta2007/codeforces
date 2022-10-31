#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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
#define int long long

class SegTree{
private: 
    int n;
    vector <int> tr, to_add;
    int neutral_tr = 1e18, neutral_to_add = -1;

    int merge_tr(int a, int b) {
        return min(a, b);
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
        if (to_add[v] == -1)
            return;
        if (vr - vl != 1) {
            to_add[2 * v] = to_add[v];
            to_add[2 * v + 1] = to_add[v];
        }
        tr[v] = to_add[v];
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
    SegTree(const vector <int>& a) {
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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    s += s;
    vector <int> tmp(2 * n, 1e18);
    SegTree dp(tmp);
    SegTree routers(tmp);
    forn (i, 0, n)
        dp.upd(i, i + 1, 0);
    forn (i, 0, n) {
        //cout << n + i << " " << n + i - 1 << " " << n + i - k << " " << n + i -  k - 1 << "\n";
        dp.upd(n + i, n + i + 1, min(dp.get(n + i - 1, n + i) + i + 1, 
                                     routers.get(n + i - k, n + i)));
        if (s[i] == '1') {
            dp.upd(n + i, n + i + 1, min(dp.get(n + i, n + i + 1),
                                         dp.get(max(0LL, n + i - k - 1), n + i) + i + 1));
            routers.upd(n + i, n + i + 1, dp.get(max(0LL, n + i - k - 1), n + i) + i + 1);
        }
        //cout << dp.get(n + i, n + i + 1) << " ";
    }
    cout << dp.get(n + n - 1, n + n);
    return 0;
}