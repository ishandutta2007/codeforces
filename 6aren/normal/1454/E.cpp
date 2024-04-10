#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

vector<int> g[N];
bool inCircle[N];
ii specialEdge;
int n;
int par[N];
bool visited[N];
int cnt;

void dfs1(int u, int p) {
    visited[u] = 1;
    for (int e : g[u]) {
        if (e == p) continue;
        if (visited[e] == 1) {
            specialEdge = {u, e};
        } else {
            dfs1(e, u);
            par[e] = u;
        }
    }
}

void dfs2(int u, int p) {
    cnt++;
    for (int e : g[u]) {
        if (e == p) continue;
        if (inCircle[e]) continue;
        dfs2(e, u);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(1, 0);
        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
            par[i] = 0;
        }
        dfs1(specialEdge.x, 0);
        do {
            inCircle[specialEdge.x] = 1;
            inCircle[specialEdge.y] = 1;
            specialEdge = {par[specialEdge.x], par[specialEdge.y]};
        } while (specialEdge != ii(0, 0));

        long long ans = 1LL * n * (n - 1);
        for (int i = 1; i <= n; i++) {
            // cout << inCircle[i] << ' ';
            cnt = 0;
            if (inCircle[i]) dfs2(i, 0);
            // cout << cnt << '\n';
            ans -= 1LL * cnt * (cnt - 1) / 2;
        }

        cout << ans << '\n';

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            visited[i] = 0;
            inCircle[i] = 0;
        }

    }

    return 0;
}