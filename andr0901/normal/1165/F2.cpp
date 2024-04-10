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

int n, m;
vector <pii> q;

bool check(int mid, vector <int> a) {
    vector <int> b(n);
    forn (i, 0, m) 
        if (q[i].fs <= mid)
            b[q[i].sc] = max(b[q[i].sc], q[i].fs);
    vector <vector <int>> last(mid + 1);
    forn (i, 0, n)
        if (b[i])
            last[b[i]].pb(i);
    int bal = 0;
    forn (i, 1, mid + 1) {
        bal++;
        for (auto j : last[i]) {
            int t = min(bal, a[j]);
            a[j] -= t, bal -= t;
        }
    }
    int sum = 0;
    forn (i, 0, n)
        sum += a[i];
    return bal >= 2 * sum;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    q.resize(m);
    forn (i, 0, m) 
        cin >> q[i].fs >> q[i].sc, q[i].sc--;
    int l = 0, r = 1e6;
    while (r - l > 1) {
        int mid = l + r >> 1;
        if (!check(mid, a)) 
            l = mid;
        else 
            r = mid;
    }
    cout << r;
    return 0;
}