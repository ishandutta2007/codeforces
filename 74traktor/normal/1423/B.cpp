#include <bits/stdc++.h>

using namespace std;
#define int long long
#define x first
#define y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int son[10009];
int par[10009];
vector<pii> g[10009];
int used[10009];
int it = 1;

bool dfs(int v, int w) {
    used[v] = it;
    for (auto u : g[v]) {
        if (u.y > w) continue;
        if (par[u.x] == -1) {
            if (son[v] != -1) par[son[v]] = -1;
            son[v] = u.x;
            par[u.x] = v;
            return 1;
        }
    }

    for (auto u : g[v]) {
        if (u.y > w) continue;
        if (used[par[u.x]] < it && dfs(par[u.x], w)) {
            par[u.x] = v;
            son[v] = u.x;
            return 1;
        }
    }

    return 0;
}

bool solve(int n, int maxw) {
    for (int i = 0; i < n; i ++) {
        son[i] = -1;
        par[i] = -1;
        used[i] = 0;
    }

    bool run = 1;
    while (run) {
        run = 0;
        for (int i = 0; i < n; i ++) {
            if (used[i] < it && son[i] == -1) if (dfs(i, maxw)) run = 1;
        }

        ++it;
    }

    for (int i = 0; i < n; i ++) {
        if (son[i] == -1) return 0;
    }

    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef karpovich
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    vector<int> costs;
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        g[a].push_back({b, c});
        costs.push_back(c);
    }

    sort(costs.begin(), costs.end());

    int l = n-1, r = costs.size();
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (solve(n, costs[mid])) r = mid;
        else l = mid;
    }

    if (r == costs.size()){cout<<-1;return 0;};
    cout << costs[r];

    return 0;
}