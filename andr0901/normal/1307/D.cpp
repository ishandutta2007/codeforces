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

const int INF = 1e9;

void dijkstra(int st, const vector <vector <pii>>& gr, vector <int>& dst) {
    dst.resize(sz(gr), INF);
    set <pii> s;
    s.emplace(0, st);
    dst[st] = 0;
    while (!s.empty()) {
        int v = s.begin() -> sc;
        s.erase(s.begin());
        for (pii u : gr[v]) {
            if (dst[v] + u.sc < dst[u.fs]) {
                s.erase({dst[u.fs], u.fs});
                dst[u.fs] = dst[v] + u.sc;
                s.emplace(dst[u.fs], u.fs);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <bool> can_be_used(n, false);
    forn (i, 0, k) {
        int t;
        cin >> t, --t;
        can_be_used[t] = true;
    }
    vector <vector <pii>> gr(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].eb(u, 1), gr[u].eb(v, 1);
    }
    vector <int> a;
    dijkstra(0, gr, a);
    vector <int> b;
    dijkstra(n - 1, gr, b);
    multiset <int> dst;
    forn (i, 0, n)
        if (can_be_used[i])
            dst.insert(b[i]);
    vector <vector <int>> c(n + 1);
    forn (i, 0, n)
        if (can_be_used[i])
            c[a[i]].pb(i);
    int ans = -1e9;
    forn (i, 0, n) {
        for (int j : c[i])
            dst.erase(dst.find(b[j]));
        if (c[i].size() && !dst.empty())
            ans = max(ans, min(a[n - 1], i + 1 + *dst.rbegin()));
        if (c[i].size() > 1)
            ans = max(ans, a[n - 1]);  
        /*
        cout << i << ":\n";
        for (int j : c[i])
            cout << j << " ";
        cout << "\n";
        for (int j : dst)
            cout << j << " ";
        cout << "\n";*/
    }
    cout << ans;
    return 0;
}