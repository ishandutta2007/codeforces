#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<int> G[300005], vec;
int dis[300005], lst[300005], vis[300005];

void dfs(int u) {
    vis[u] = 1;
    vec.pb(u);
    for (int i : G[u])
        if (!vis[i])
            dfs(i);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    for (int i = 1; i <= n; ++i)
        sort(ALL(G[i]));
    fill(dis + 1, dis + n + 1, -1);
    queue<int> q;
    q.push(1), dis[1] = 0, lst[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : G[u])
            if (!~dis[i])
                q.push(i), dis[i] = dis[u] + 1, lst[i] = u;
    }
    vector<int> ans;
    if (dis[n] != -1 && dis[n] <= 4) {
        while (n != 0)
            ans.pb(n), n = lst[n];
        cout << SZ(ans) - 1 << "\n";
        for (int i = SZ(ans) - 1; i >= 0; --i)
            cout << ans[i] << " \n"[i == 0];
        exit(0);
    }
    for (int i = 2; i < n; ++i)
        if (dis[i] == 2) {
            cout << "4\n";
            cout << "1 " << lst[i] << " " << i << " 1 " << n << "\n";
            exit(0);
        }
    vis[1] = 1;
    for (int i : G[1]) {
        if (!vis[i]) {
            vec.clear();
            dfs(i);
            for (int j : vec) {
                int cnt = 0;
                for (int k : G[j])
                    if (dis[k] == 1)
                        ++cnt;
                if (cnt != SZ(vec) - 1) {
                    fill(dis + 1, dis + n + 1, -1);
                    q.push(j), dis[j] = 0, lst[j] = 0;
                    while (!q.empty()) {
                        int u = q.front();
                        q.pop();
                        for (int x : G[u])
                            if (!~dis[x] && x != 1)
                                q.push(x), dis[x] = dis[u] + 1, lst[x] = u;
                    }
                    for (int k = 2; k < n; ++k)
                        if (dis[k] == 2) {
                            cout << "5\n";
                            cout << "1 " << j << " " << lst[k] << " " << k << " " << j << " " << n << "\n";
                            exit(0);
                        }
                    assert(0);
                }
            }
        }
    }
    cout << "-1\n";
}