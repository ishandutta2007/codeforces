#include <bits/stdc++.h>

using namespace std;

const int N = 100'007;

int n;
int ans[N];
vector <int> G[N];

void go(int u, int p, int s) {
    ans[u] = s * (int)G[u].size();
    for (auto v: G[u]) {
        if (v != p) {
            go(v, u, -s);
        }
    }
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        G[u].push_back(v);
        G[v].push_back(u);
    }

    int root = 1;
    go(root, root, 1);
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}