#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXV = 50;

ll f[MAXV][MAXV], c[MAXV][MAXV], g[MAXV][MAXV];
bool used[MAXV];
int pr[MAXV];
ll MIN_C = INT_MAX;
ll n, m, x;

bool bfs(int s, int t) {
    memset(used, 0, sizeof used);
    queue <int> q;
    q.push(s);
    used[s] = 1;
    pr[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        if (v == t) 
            return true;
        q.pop();
        for (int i = 0; i < n; i++) {
            if (c[v][i] - f[v][i] > 0) {
                if (!used[i]) {
                    q.push(i);
                    used[i] = 1;
                    pr[i] = v;
                }
            }
        }
    }
    return false;
}

ll edkarp(int s, int t) {
    memset(f, 0, sizeof f);
    while (bfs(s, t)) {
        MIN_C = LLONG_MAX;
        int v = t;
        while (v != s) {
            MIN_C = min(c[pr[v]][v] - f[pr[v]][v], MIN_C);
            v = pr[v];
        }
        v = t;
        while (v != s) {
            int u = pr[v];
            f[u][v] += MIN_C;
            f[v][u] -= MIN_C;
            v = pr[v];
        }
    }
    ll flow = 0;
    for (int i = 0; i < n; i++)
        if (c[s][i] > 0)
            flow += f[s][i];
    return flow;
}

bool check(double v) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = (ll) (g[i][j] / v);
        }
    }
    return edkarp(0, n - 1) >= x;
}

int main() {
    int a, b, w;
    cin >> n >> m >> x;
    while (m--) {
        cin >> a >> b >> w;
        a--, b--;
        g[a][b] = w;
    }
    double l = 0;
    double r = 1000000000;
    for (int it = 0; it < 1000; it++) {
        double vm = (l + r) / 2;
        if (check(vm))
            l = vm;
        else
            r = vm;
    }
    cout << setprecision(7) << fixed << l * x << endl;
}