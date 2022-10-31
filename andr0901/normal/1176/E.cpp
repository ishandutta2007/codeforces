#pragma GCC optimize("Ofast")
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

const int INF = 1e6;

vector <vector <int>> gr;

vector <int> bfs(int st) {
    vector <int> dst(sz(gr), INF);
    deque <int> q;
    dst[st] = 0;
    q.pb(st);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto u : gr[v]) {
            if (dst[v] + 1 < dst[u]) {
                dst[u] = dst[v] + 1;
                q.pb(u);
            }
        }
    }
    return dst;
}

void solve() {
    int n, m;
    cin >> n >> m;
    gr = vector <vector <int>> (n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), gr[u].pb(v);
    }
    vector <int> dst = bfs(0);
    int x = 0;
    forn (i, 0, n) 
        x += (dst[i] % 2);
    if (x <= n / 2) {
        cout << x << "\n";
        forn (i, 0, n) 
            if (dst[i] % 2)
                cout << i + 1 << " ";
    } else {
        cout << n - x << "\n";
        forn (i, 0, n) 
            if (!(dst[i] % 2))
                cout << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}