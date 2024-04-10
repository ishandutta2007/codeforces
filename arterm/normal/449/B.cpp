#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <queue>

using namespace std;

#define long long long
#define INF 1000000000000000000ll
#define M 100100

int n, m, k, s[M];
vector<int> h[M], hw[M], g[M], gw[M];
bool u[M];
priority_queue<pair<long, int>> q;
long d[M];
pair<long, int> e[M];

void addh(int x, int y, int we) {
    h[x].push_back(y);
    hw[x].push_back(we);
}

void addg(int x, int y, int we) {
    g[x].push_back(y);
    gw[x].push_back(we);
}

void read() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, x, y, w; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &w);
        addh(x, y, w);
        addh(y, x, w);

        addg(x, y, w);
        addg(y, x, w);
    }

    for (int i = 0, y, w; i < k; ++i) {
        scanf("%d%d", &y, &w);
        s[y]++;

        addg(1, y, w);
        addg(y, 1, w);
    }
}

void relax(int v) {
    u[v] = true;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        int w = gw[v][i];
        if (d[to] > d[v] + w) {
            d[to] = d[v] + w;
            q.push(make_pair(-d[to], to));
        }
    }
}

void dijkstra() {
    fill(d, d + M, INF);
    d[1] = 0;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
        if (!u[v])
            relax(v);
    }
}

void kill() {
    for (int i = 1; i <= n; ++i)
        e[i] = make_pair(d[i], i);
    sort(e + 1, e + n + 1);

    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        int v = e[i].second;
        bool c = 1;
        for (int j = 0; j < (int) h[v].size(); ++j) {
            int to = h[v][j];
            int w = hw[v][j];
            if (d[to] + w == d[v])
                c = 0;
        }
        ans += (s[v] - c);
    }

    cout << ans << "\n";
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);
    read();
    dijkstra();
    kill();

    return 0;
}