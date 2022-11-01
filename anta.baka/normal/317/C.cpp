#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

struct mv {
    int u, v, w;
};

int n, v, e, a[300], b[300];
vector<int> g[300], was, p[300][300], path;
vector<mv> way;
ll A, B;

void dfs0(int v, int rt) {
    was[v] = 1;
    path.push_back(v);
    p[rt][v] = path;
    for(int to : g[v]) if(!was[to]) dfs0(to, rt);
    path.pop_back();
}

void dfs(int v) {
    was[v] = 1;
    A += a[v]; B += b[v];
    for(int to : g[v]) if(!was[to]) dfs(to);
}

void go(int i, int d) {
    if(i == 0) return;
    int u = path[i - 1], v = path[i];
    if(a[u] >= d) {
        way.push_back({u, v, d});
        a[u] -= d;
        a[v] += d;
        go(i - 1, d);
    } else {
        way.push_back({u, v, a[u]});
        int mem = a[u];
        a[v] += a[u];
        a[u] = 0;
        go(i - 1, d);
        way.push_back({u, v, d - mem});
        a[u] -= d - mem;
        a[v] += d - mem;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> v >> e;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < e; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int u = 0; u < n; u++) {
        was.assign(n, 0);
        dfs0(u, u);
    }
    was.assign(n, 0);
    for(int u = 0; u < n; u++) {
        if(was[u]) continue;
        A = B = 0; dfs(u);
        if (A != B) return cout << "NO", 0;
        while(true) {
            for(int u = 0; u < n; u++) {
                if(a[u] <= b[u] || !was[u]) continue;
                for(int v = 0; v < n; v++) {
                    if(a[v] >= b[v] || !was[v]) continue;
                    path = p[u][v];
                    int d = min(a[u] - b[u], b[v] - a[v]);
                    go(sz(path) - 1, d);
                    break;
                }
                goto HELL;
            }
            break;
            HELL:;
        }
    }
    cout << way.size() << '\n';
    for(mv x : way) cout << x.u + 1 << ' ' << x.v + 1 << ' ' << x.w << '\n';
}