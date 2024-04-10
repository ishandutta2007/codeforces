#include <bits/stdc++.h>

using namespace std;

const int M = 1010;

int n, m;
vector<int> g[M];
bool used[M];
int d[M], color[M];
int q[M], qs, qf;
int best[M], v[M];

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int v, int c) {
    used[v] = true;
    color[v] = c;
    for (auto to : g[v])
        if (!used[to])
            dfs(to, c);
}

int bfs(int v) {
    fill(used, used + n, false);
    fill(d, d + n, 0);
    qs = qf = 0;
    q[qf++] = v;
    used[v] = true;
    d[v] = 0;
    while (qs < qf) {
        int v = q[qs++];
        for (auto to : g[v])
            if (!used[to]) {
                used[to] = true;
                d[to] = d[v] + 1;
                q[qf++] = to;
            }
    }
    return *max_element(d, d + n);
}

int main() {
    read();

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i, cnt++);

    for (int i = 0; i < n; ++i) {
        int t = bfs(i);
        int c = color[i];
        if (t > best[c]) {
            best[c] = t;
            v[c] = i;
        }
    }



    for (int i = 0; i < cnt; ++i)
        bfs(v[i]);

    bool good = true;
    for (int i = 0; i < n; ++i)
        if (used[i])
            for (auto to : g[i])
                if (abs(d[to] - d[i]) != 1)
                    good = false;

    if (!good)
        cout << "-1\n";
    else {
        int sum = 0;
        for (int i = 0; i < cnt; ++i)
            sum += best[i];
        cout << sum << "\n";
    }
    return 0;
}