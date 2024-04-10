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

vector <int> a;

void decrease_cords() {
    vector <int> b = a;
    sort(all(b)), b.erase(unique(all(b)), b.end());
    map <int, int> mp;
    forn (i, 0, sz(b))
        mp[b[i]] = i;
    forn (i, 0, sz(a))
        a[i] = mp[a[i]];
}

vector <ll> tr;

void upd(int v, int vl, int vr, int idx, int val) {
    if (vr - vl == 1) {
        tr[v] += val;
        return;
    }
    int vm = vl + vr >> 1;
    if (idx < vm)
        upd(2 * v, vl, vm, idx, val);
    else 
        upd(2 * v + 1, vm, vr, idx, val);
    tr[v] = tr[2 * v] + tr[2 * v + 1];
}

int get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl)
        return 0;
    if (l <= vl && vr <= r)
        return tr[v];
    int vm = vl + vr >> 1;
    return get(2 * v, vl, vm, l, r) + get(2 * v + 1, vm, vr, l, r);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    forn (i, 0, n)
        cin >> a[i];
    decrease_cords();
    tr.resize(4 * n);
    vector <int> pr(n), sf(n);
    forn (i, 0, n) {
        pr[i] = get(1, 0, n, a[i] + 1, n);
        upd(1, 0, n, a[i], 1);
    }
    tr.clear(), tr.resize(4 * n);
    for (int i = n - 1; i >= 0; i--) {
        sf[i] = get(1, 0, n, 0, a[i]);
        upd(1, 0, n, a[i], 1);
    }
    ll ans = 0;
    forn (i, 0, n)
        ans += 1LL * pr[i] * sf[i];
    cout << ans;
    return 0;
}