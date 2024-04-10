#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 500 + 7;
vector <int> g[MAXN];
vector <int> r[MAXN];
bool used[MAXN];
int mt[MAXN];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (auto to : g[v]) {
        if (mt[to] == -1 || dfs(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false; 
}

int main() {
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        r[u].pb(v);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        memset(used, 0, sizeof used);
        memset(mt, -1, sizeof mt);
        int cnt = 0;
        for (int v = 1; v <= n; v++) {
            g[v].clear();
        }
        for (int v = 1; v <= n; v++) {
            for (auto to : r[v]) {
                cnt += (to == i || v == i);
                if (to != i && v != i) g[v].pb(to);
            }
        }
        int len_mt = 0;
        for (int v = 1; v <= n; v++) {
            if (v == i) continue;
            if (dfs(v))  memset(used, 0, sizeof used);
        }
        for (int v = 1; v <= n; v++) if (mt[v] != -1) len_mt++;
        ans = min(ans, 2 * n - 1 - cnt + (m - cnt) - len_mt + (n - 1) - len_mt);
    }
    printf("%d\n", ans);
}