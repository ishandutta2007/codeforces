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

vector <int> tr, a, to_add;

int merge(int a, int b) {
    return min(a, b);
}

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tr[v] = a[vl];
        return;
    }
    int vm = vl + vr >> 1;
    build(2 * v, vl, vm), build(2 * v + 1, vm, vr);
    tr[v] = merge(tr[2 * v], tr[2 * v + 1]);
}

void push(int v, int vl, int vr) {
    if (vr - vl != 1) {
        to_add[2 * v] += to_add[v];
        to_add[2 * v + 1] += to_add[v];
    }
    tr[v]+= to_add[v];
    to_add[v] = 0; 
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
    tr[v] = merge(tr[2 * v], tr[2 * v + 1]);
}

int get(int v, int vl, int vr, int l, int r) {
    push(v, vl, vr);
    if (vr <= l || r <= vl)
        return INT_MAX;
    if (l <= vl && vr <= r)
        return tr[v];
    int vm = vl + vr >> 1;
    return merge(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    n++;
    a.resize(n);
    forn (i, 0, n - 1) {
        if (s[i] == '(')
            a[i + 1] = a[i] + 1;
        else 
            a[i + 1] = a[i] - 1;
    }
    tr.resize(4 * n, INT_MAX), to_add.resize(4 * n);
    build(1, 0, n);
    int ans = 0;
    forn (i, 1, n) {
        if (s[i - 1] == '(') {
            upd(1, 0, n, i, n, -2);
            if (get(1, 0, n, 0, n) >= 0 && get(1, 0, n, n - 1, n) == 0)
                ans++;
            upd(1, 0, n, i, n, 2); 
        } else {
            upd(1, 0, n, i, n, 2);
            if (get(1, 0, n, 0, n) >= 0 && get(1, 0, n, n - 1, n) == 0)
                ans++;
            upd(1, 0, n, i, n, -2);
        }
    }
    cout << ans;
    return 0;
}