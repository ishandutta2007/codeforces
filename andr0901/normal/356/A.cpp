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
        to_add[2 * v] = min(to_add[2 * v], to_add[v]), to_add[2 * v + 1] = min(to_add[2 * v + 1], to_add[v]);
    tr[v] = min(tr[v], to_add[v]);
    to_add[v] = INT_MAX;
}

void upd(int v, int vl, int vr, int l, int r, int val) {
    push(v, vl, vr);
    if (vr <= l || r <= vl)
        return;
    if (l <= vl && vr <= r) {
        to_add[v] = min(to_add[v], val);
        push(v, vl, vr);
        return;
    }
    int vm = vl + vr >> 1;
    upd(2 * v, vl, vm, l, r, val), upd(2 * v + 1, vm, vr, l, r, val);
    tr[v] = min(tr[2 * v], tr[2 * v + 1]);
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
    tr.resize(4 * n, INT_MAX), to_add.resize(4 * n, INT_MAX);
    vector <int> q(m);
    forn (i, 0, m) {
        int L, R, M;
        cin >> L >> R >> M;
        q[i] = M;
        L--, M--;
        upd(1, 0, n, L, M, i), upd(1, 0, n, M + 1, R, i);
    }
    forn (i, 0, n) {
        int t = get(1, 0, n, i);
        if (t == INT_MAX)
            cout << "0 ";
        else 
            cout << q[t] << " ";
    }
    return 0;
}