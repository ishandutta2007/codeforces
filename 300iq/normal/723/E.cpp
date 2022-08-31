#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

const int N = (int) 200 + 7;
int d[N];
int d_in[N], d_out[N];
multiset <int> g[N];
vector <pair <int, int> > go;

void dfs(int v) {
    while (g[v].size() > 0) {
        int to = *g[v].begin();
        go.pb({v, to});
        g[to].erase(g[to].find(v));
        g[v].erase(g[v].begin());
        dfs(to);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(d, 0, sizeof d);
        memset(d_in, 0, sizeof d_in);
        memset(d_out, 0, sizeof d_out);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            d[u]++, d[v]++;
            g[u].insert(v);
            g[v].insert(u);
        }
        int t = n;
        for (int i = 0; i < n; i++) {
            if (d[i] % 2 == 1) {
                g[i].insert(t);
                g[t].insert(i);
            }
        }
        go.clear();
        for (int i = 0; i <= n; i++) dfs(i);
        vector <pair <int, int> > res;
        for (auto f : go) {
            if (f.fc != t && f.sc != t) {
                d_out[f.fc]++;
                d_in[f.sc]++;
                res.pb(f);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans += (d_in[i] == d_out[i]);
        printf("%d\n", ans);
        for (auto f : res) {
            printf("%d %d\n", f.fc + 1, f.sc + 1);
        }
    }
}