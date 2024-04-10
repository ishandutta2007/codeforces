#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 605;

long long d[N][N];
long long d2[N][N];


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = 1e18;
            d2[i][j] = 1e18;
        }
    }    

    vector<tuple<int, int, int>> edges;

    for (int i = 1; i <= m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        d[v][u] = min(d[v][u], l);
        d[u][v] = min(d[u][v], l);
        d2[u][v] = d[u][v];
        d2[v][u] = d[v][u];
        edges.push_back(make_tuple(u, v, l));
    }

    // cout << d[1][2] << endl;

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        d2[u][v] = d2[v][u] = -l;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // cout << d[1][2] << endl;
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int foo = min(d[i][k] + d2[k][j], d2[i][k] + d[k][j]);
                // if (i == 1 && j == 2 && k == 4) {
                //     cout << d2[i][k] << ' ' << d[k][j] << endl;
                //     cout << foo << endl;
                // }
                // if (foo > 0) continue;
                d2[i][j] = min(d2[i][j], foo);
            }
        }
    }

    // cout << d2[1][2] << endl;

    int ans = 0;
    for (auto e : edges) {
        int u = get<0>(e);
        int v = get<1>(e);
        int l = get<2>(e);
        if (min(d2[u][v], d2[v][u]) <= -l) ans++;
    }

    cout << ans << '\n';

    return 0;
}