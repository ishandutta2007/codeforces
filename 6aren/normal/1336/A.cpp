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
int dep[N], sz[N], f[N];

void dfs(int u, int v) {
    sz[u] = 1;
    for (int e : g[u]) {
        if (e == v) continue;
        dep[e] = dep[u] + 1;
        dfs(e, u);
        sz[u] += sz[e];
    }
}

bool push[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dep[1] = 1;
    dfs(1, 0);
    priority_queue<ii> pq;
    for (int i = 1; i <= n; i++) {
        f[i] = dep[i] - sz[i];
        if (i != 1 && g[i].size() == 1) {
            pq.push({f[i], i});
            push[i] = 1;
        }
    }
    long long ans = 0;
    vector<bool> check(n + 1);
    for (int i = 1; i <= k; i++) {
        auto u = pq.top();
        pq.pop();
        ans += u.x;
        check[u.y] = 1;
        // cout << u.x << ' ' << u.y << endl;
        for (int e : g[u.y]) {
            if (check[e]) continue;
            if (push[e]) continue;
            pq.push({f[e], e});
            push[e] = 1;
        }
    }
    cout << ans;
    return 0;
}