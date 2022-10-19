#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int maxn = 1000005;
vector<int> g[maxn], g2[maxn];
vector<vector<int>> cm;
int used[maxn], dist[maxn];
void dfs1(int v) {
    used[v] = 1;
    cm.back().pb(v);
    for (auto u: g2[v])
        if (!used[u])
            dfs1(u);
}
pair<int, int> dfs2(int v, int a) {
    used[v] = a;
    if (used[g[v][0]] > 0) {
        return {g[v][0], a+1-used[g[v][0]]};
    }
    return dfs2(g[v][0], a+1);
}
void dfs3(int v, int m) {
    if (dist[g[v][0]] == -1)
        dfs3(g[v][0], m);
    dist[v] = (dist[g[v][0]]+1)%m;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n*m; ++i)
            used[i] = 0, g[i].clear(), g2[i].clear(), dist[i] = -1;
        cm.clear();
        vector<string> c(n);
        for (int i = 0; i < n; ++i)
            cin >> c[i];
        vector<string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == 'R')
                    g[i*m+j].pb(i*m+j+1), g2[i*m+j].pb(i*m+j+1), g2[i*m+j+1].pb(i*m+j);
                else if (s[i][j] == 'L')
                    g[i*m+j].pb(i*m+j-1), g2[i*m+j].pb(i*m+j-1), g2[i*m+j-1].pb(i*m+j);
                else if (s[i][j] == 'U')
                    g[i*m+j].pb(i*m+j-m), g2[i*m+j].pb(i*m+j-m), g2[i*m+j-m].pb(i*m+j);
                else
                    g[i*m+j].pb(i*m+j+m), g2[i*m+j].pb(i*m+j+m), g2[i*m+j+m].pb(i*m+j);
            }
        }
        for (int i = 0; i < n*m; ++i) {
            if (!used[i]) {
                cm.pb({}), dfs1(i);
            }
        }
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < cm.size(); ++i) {
            for (auto j: cm[i])
                used[j] = 0;
            pair<int, int> a = dfs2(cm[i][0], 1);
            dist[a.f] = 0;
            for (auto j: cm[i])
                if (dist[j] == -1)
                    dfs3(j, a.s);
            ans1 += a.s;
            vector<int> used2(a.s);
            for (auto j: cm[i]) {
                if (c[j/m][j%m] == '0')
                    used2[dist[j]] = 1;
            }
            for (int j = 0; j < a.s; ++j)
                ans2 += used2[j];
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
    return 0;
}