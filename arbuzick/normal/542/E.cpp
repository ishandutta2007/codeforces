#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

const int maxn = 1e3 + 5;
int col[maxn];
int c1[maxn];
vector<int> g[maxn];

void dfs(int v, int c, int c2) {
    c1[v] = c2;
    col[v] = c;
    for (auto u: g[v]) {
        if (col[u] == 0) {
            dfs(u, 3 - c, c2);
        } else if (col[u] == col[v]) {
            cout << -1;
            exit(0);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].pb(b - 1);
        g[b - 1].pb(a - 1);
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            dfs(i, 1, c++);
        }
    }
    vector<int> ans1(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> dist(n, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        int ans2 = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u: g[v]) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    ans2 = max(ans2, dist[u]);
                    q.push(u);
                }
            }
        }
        ans1[c1[i]] = max(ans1[c1[i]], ans2);
    }
    for (int i = 0; i < n; ++i) {
        ans += ans1[i];
    }
    cout << ans;
    return 0;
}