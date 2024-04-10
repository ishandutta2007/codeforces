#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 400005;

int n, m, v, N, b[MN], par[MN], deg[MN], low[MN], num[MN], vis[MN], sand[MN], dag[MN], cnt = 1, scc = 1;
char c;
vector<int> adj[MN], s;

int conv(int r, int c) {
    return (r - 1) * m + c;
}

void tarjan(int cur) {
    low[cur] = num[cur] = cnt++;
    s.push_back(cur);
    vis[cur] = 1;
    for (int i : adj[cur]) {
        if (!num[i]) {
            tarjan(i);
        }
        if (vis[i]) {
            low[cur] = min(low[cur], low[i]);
        }
    }
    if (low[cur] == num[cur]) {
        while (1) {
            v = s.back();
            s.pop_back();
            vis[v] = 0;
            dag[v] = scc;
            if (cur == v) {
                scc++;
                break;
            }
        }
    }
}

int32_t main() {
    boost();

    cin >> n >> m;
    N = n * m;
    int a[n + 5][m + 5];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '#') a[i][j] = 1;
        }
    }
    for (int i = 1; i <= m; i++) cin >> b[i]; //useless
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!a[i][j]) continue;
            int id = conv(i, j);
            sand[id] = 1;
            if (a[i][j - 1]) adj[id].push_back(conv(i, j - 1));
            if (a[i][j + 1]) adj[id].push_back(conv(i, j + 1));
            if (a[i + 1][j]) adj[id].push_back(conv(i + 1, j));
            if (a[i - 1][j]) adj[id].push_back(conv(i - 1, j));
            if (par[j - 1]) adj[par[j - 1]].push_back(id);
            if (par[j]) adj[par[j]].push_back(id);
            if (par[j + 1]) adj[par[j + 1]].push_back(id);
        }
        for (int j = 1; j <= m; j++) if (a[i][j]) par[j] = conv(i, j);
    }
    //compress to scc then count leaves
    for (int i = 1; i < MN; i++) if (sand[i] && !dag[i]) tarjan(i);
    for (int i = 1; i < MN; i++) {
        if (!sand[i]) continue;
        for (int nxt : adj[i]) {
            if (dag[i] != dag[nxt]) deg[dag[nxt]]++;
            //printf("%d %d\n", i, nxt);
        }
    }
    int ans = 0;
    for (int i = 1; i < scc; i++) if (!deg[i]) ans++;
    printf("%lld\n", ans);

    return 0;
}