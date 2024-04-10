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

class Segtree {
private:
    int n;
    vector <long long> tr, to_add;

    void push(int v, int vl, int vr) {
        if (vr - vl != 1) {
            to_add[2 * v] += to_add[v];
            to_add[2 * v + 1] += to_add[v];
        }
        tr[v] += to_add[v];
        to_add[v] = 0;
    }

    long long get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return -1e18;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return max(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }

    void upd(int v, int vl, int vr, int l, int r, int x) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return;
        if (l <= vl && vr <= r) {
            to_add[v] += x;
            push(v, vl, vr);
            return;
        }
        int vm = vl + vr >> 1;
        upd(2 * v, vl, vm, l, r, x), upd(2 * v + 1, vm, vr, l, r, x);
        tr[v] = max(tr[2 * v], tr[2 * v + 1]);
    }

public:
    Segtree(int _n) : n(_n) {
        tr.resize(4 * n), to_add.resize(4 * n);
    }

    long long get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }
};



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <pii> a(n);
    forn (i, 0, n)
        cin >> a[i].fs >> a[i].sc;
    vector <pii> b(m);
    forn (i, 0, m)
        cin >> b[i].fs >> b[i].sc;
    vector <vector <int>> c(k, vector <int> (3));
    forn (i, 0, k)
        forn (j, 0, 3)
            cin >> c[i][j];

    sort(all(a)), sort(all(b)), sort(all(c));
    vector <int> bb(m);
    forn (i, 0, m)
        bb[i] = b[i].fs;

    Segtree tr(m);
    forn (i, 0, m)
        tr.upd(i, i + 1, -b[i].sc);
    long long ans = -1e18;
    int j = 0;
    forn (i, 0, n) {
        while (j < k && c[j][0] < a[i].fs) {
            tr.upd(upper_bound(all(bb), c[j][1]) - bb.begin(), m, c[j][2]);
            ++j;
        }
        ans = max(ans, tr.get(0, m) - a[i].sc);
    }
    cout << ans;
    return 0;
}