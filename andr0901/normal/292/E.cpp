#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <int> tr, to_add;

void push(int v, int vl, int vr) {
    if (vr - vl != 1) 
        to_add[2 * v] = max(to_add[2 * v], to_add[v]), to_add[2 * v + 1] = max(to_add[2 * v + 1], to_add[v]);
    tr[v] = max(tr[v], to_add[v]);
    to_add[v] = INT_MIN;
}

void upd(int v, int vl, int vr, int l, int r, int val) {
    push(v, vl, vr);
    if (vr <= l || r <= vl)
        return;
    if (l <= vl && vr <= r) {
        to_add[v] = max(to_add[v], val);
        push(v, vl, vr);
        return;
    }
    int vm = vl + vr >> 1;
    upd(2 * v, vl, vm, l, r, val), upd(2 * v + 1, vm, vr, l, r, val);
}

int get(int v, int vl, int vr, int idx) {
    push(v, vl, vr);
    if (vr - vl == 1)
        return tr[v];
    int vm = vl + vr >> 1;
    if (idx < vm)
        return get(2 * v, vl, vm, idx);
    else 
        return get(2 * v + 1, vm, vr, idx);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <int> b(n);
    forn (i, 0, n)
        cin >> b[i];
    tr.resize(4 * n, INT_MIN), to_add.resize(4 * n, INT_MIN);
    vector <pii> q(m);
    forn (i, 0, m) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            x--, y--;
            upd(1, 0, n, y, y + k, i);
            q[i] = {x, y};
        } else {
            int idx;
            cin >> idx;
            idx--;
            int ans = get(1, 0, n, idx);
            if (ans == INT_MIN)
                cout << b[idx];
            else 
                cout << a[idx - q[ans].sc + q[ans].fs];
            cout << "\n";
        }
    }
    return 0;
}