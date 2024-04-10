#include <bits/stdc++.h>

using namespace std;

#define M 100100

int n, m;
vector<int> g[M], h[M];
int used[M], num[M], c = 1, size[M];
bool cycle[M];

void read() {
    cin >> n >> m;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);

        h[x].push_back(y);
        h[y].push_back(x);
    }
}

void dfsc(int v) {
    num[v] = c;
    size[c]++;
    for (int to : h[v])
        if (num[to] == 0)
            dfsc(to);
}

void dfs(int v) {
    int c = num[v];
    used[v] = 1;

    for (int to : g[v]) {
        if (used[to] == 0)
            dfs(to);
        else if (used[to] == 1)
            cycle[c] = true;
    }

    used[v] = 2;
}

int main() {
    read();
    for (int i = 1; i <= n; ++i)
        if (num[i] == 0) {
            dfsc(i);
            ++c;
        }

    for (int i = 1; i <= n; ++i)
        if (used[i] == 0)
            dfs(i);
    int ans = 0;
    for (int i = 1; i < c; ++i)
        if (cycle[i])
            ans += size[i];
        else
            ans += size[i] - 1;

    cout << ans << "\n";
    return 0;
}