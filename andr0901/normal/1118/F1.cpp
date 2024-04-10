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

vector <int> a;
vector <vector <int>> gr;
int x = 0, y = 0, ans = 0;

pii dfs(int v, int p) {
    int cur_x = 0, cur_y = 0;
    if (a[v] == 1)
        cur_x++;
    if (a[v] == 2)
        cur_y++;
    for (auto u : gr[v]) {
        if (u == p)
            continue;
        pii p = dfs(u, v);
        if (p.fs == x && p.sc == 0 || p.fs == 0 && p.sc == y)
            ans++;
        cur_x += p.fs, cur_y += p.sc;
    }
    return {cur_x, cur_y};
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n), gr.resize(n);
    forn (i, 0, n) {
        cin >> a[i];
        if (a[i] == 1)
            x++;
        if (a[i] == 2)
            y++;
    }
    forn (i, 0, n - 1) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--, t2--;
        gr[t1].pb(t2), gr[t2].pb(t1);
    }
    dfs(0, -1);
    cout << ans;
    return 0;
}