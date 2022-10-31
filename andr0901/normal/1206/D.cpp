#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int m = 63;
    //cout << (1LL << 61);
    vector <int> a;
    vector <vector <int>> b(m);
    forn (i, 0, n) {
        int t;
        cin >> t;
        forn (j, 0, m) 
            if ((t >> j) & (1LL)) 
                b[j].pb(i);
        if (t)
            a.pb(t);
    }
    forn (i, 0, m) 
        if (sz(b[i]) > 2)
            return cout << 3, 0;
    n = sz(a);
    vector <vector <int>> gr(n);
    forn (i, 0, n) 
        forn (j, 0, n) 
            if (i != j && (a[i] & a[j])) 
                gr[i].pb(j);
    int INF = 1e9;
    int ans = INF;
    forn (i, 0, n) {
        deque <int> q;
        q.pb(i);
        vector <int> dst(n, INF);
        vector <int> par(n, -1);
        dst[i] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop_f();
            for (int u : gr[v]) {
                if (dst[u] == INF) {
                    q.pb(u);
                    dst[u] = dst[v] + 1;
                    par[u] = v;
                } else {
                    if (u != par[v] && dst[u] + dst[v] + 1 > 2) {
                        //cout << v << " " << u << "  " << dst[v] << " " << dst[u] << "\n";
                        ans = min(ans, dst[u] + dst[v] + 1); 
                    }
                }
            }
        }
        /*forn (j, 0, n)
            cout << dst[j] << " ";
        cout << "\n\n";*/
    }
    if (ans == INF)
        cout << -1;
    else 
        cout << ans;
    return 0;
}