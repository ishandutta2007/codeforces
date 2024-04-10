#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> p(n);
    queue<int> q;
    for (int i = 0; i < n; ++i)
        q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int k = 0;
        for (auto u: g[v])
            if (p[v] == p[u])
                k++;
        if (k > 1) {
            p[v] = 1-p[v];
            for (auto u: g[v])
                q.push(u);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << p[i];
    return 0;
}