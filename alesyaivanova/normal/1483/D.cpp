#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 609;
int g[maxn][maxn];
int d[maxn][maxn];
int need[maxn][maxn];
int n, m, q;
int inf = 1e18;
bool ok[maxn][maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < n; e++) {
            g[i][e] = inf;
            need[i][e] = -inf;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        g[a][b] = min(g[a][b], w);
        g[b][a] = min(g[b][a], w);
    }
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < n; e++) {
            d[i][e] = g[i][e];
        }
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int e = 0; e < n; e++) {
                d[i][e] = min(d[i][e], d[i][k] + d[k][e]);
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        need[a][b] = max(need[a][b], l);
        need[b][a] = max(need[b][a], l);
    }
    for (int u = 0; u < n; u++) {
        for (int a = 0; a < n; a++) {
            int ma = -inf;
            for (int v = 0; v < n; v++) {
                ma = max(ma, need[u][v] - d[a][v]);
            }
//            cout << u + 1 << " " << a + 1 << " " << ma << "\n";
            for (int b = 0; b < n; b++) {
                if (d[u][b] + g[a][b] <= ma) {
                    ok[a][b] = 1;
                    ok[b][a] = 1;
//                    cout << " " << b + 1 << "\n";
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < n; e++) {
            if (i != e)
                ans += ok[i][e];
        }
    }
    cout << ans / 2;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}