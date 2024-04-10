#include <bits/stdc++.h>
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    g[0].pb(0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    unordered_map<int, int> dist, pr;
    for(int i = 0; i < n; ++i)
        for (auto j: g[i])
            dist[i*n+j] = -1;
    unordered_set<long long> s;
    for (int i = 0; i < k; ++i) {
        int a1, b1, c1;
        cin >> a1 >> b1 >> c1;
        a1--, b1--, c1--;
        s.insert(1LL*a1*n*n+b1*n+c1);
    }
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        int v1 = v/n, v2 = v%n;
        q.pop();
        for (auto u: g[v1]) {
            if (s.count(1LL*v2*n*n+v1*n+u) == 0 && dist[u*n+v1] == -1)
                dist[u*n+v1] = dist[v]+1, q.push(u*n+v1), pr[u*n+v1] = v;
        }
    }
    int d = -1;
    int v;
    for (auto i: g[n-1])
        if (dist[(n-1)*n+i] != -1 && (d == -1 || dist[(n-1)*n+i] < d))
            d = dist[(n-1)*n+i], v = (n-1)*n+i;
    if (d == -1) {
        cout << d;
        return 0;
    }
    cout << d << '\n';
    vector<int> path;
    while (v != 0) {
        path.pb(v/n);
        v = pr[v];
    }
    path.pb(0);
    reverse(all(path));
    for (auto v: path)
        cout << v+1 << ' ';
    return 0;
}