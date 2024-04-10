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

typedef long long ll;

vector <vector <int>> gr;
vector <bool> used;

void dfs(int v) {
    used[v] = 1;
    for (auto u : gr[v])
        if (!used[u])
            dfs(u);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    gr.resize(n + m);
    forn (i, 0, q) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--, t2--;
        gr[t1].pb(t2 + n), gr[t2 + n].pb(t1);
    }
    int ans = -1;
    used.resize(n + m);
    forn (i, 0, n + m) {
        if (!used[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}