#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

typedef long long ll;

vector <int> a, b;
vector <vector <int>> gr;

void dfs(int v, int p, int h) {
    int m = 1e18;
    for (auto u : gr[v])
        m = min(m, a[u] - a[p]);
    //cout << v << " " << p << "  " << a[v] << " " << a[p] << "\n";
    if (h % 2 == 0)
        b[v] = a[v] - a[p];
    else {
        if (!gr[v].size())
            return;
        if (m < 0)
            cout << -1, exit(0);
        b[v] = m;
        a[v] = a[p] + b[v];
    }
    for (auto u : gr[v])
        dfs(u, v, h + 1);
    //cout << v << " " << p << "  " << a[v] << " " << a[p] << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n), gr.resize(n), b.resize(n);
    forn (i, 1, n) {
        int t;
        cin >> t;
        t--;
        gr[t].pb(i);
    }
    forn (i, 0, n) {
        cin >> a[i];
        if (a[i] == -1)
            a[i] = 0;
    }
    a.pb(0), b.pb(0);
    dfs(0, n, 0);
    int ans = 0;
    forn (i, 0, n)
        ans += b[i];
    /*forn (i, 0, n)
        cout << a[i] << " ";
    cout << "\n";
    forn (i, 0, n)
        cout << b[i] << " ";*/
    cout << ans;
    return 0;
}