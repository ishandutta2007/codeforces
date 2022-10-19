#include <bits/stdc++.h>

using namespace std;
int ans = 0;
vector <vector <int>> a;
vector <int> pr, gl;
set <pair <int, int>> b;
void dfs(int v, int p, int now) {
    if (now > 2) b.insert({now, v});
    pr[v] = p;
    gl[v] = now;
    for (int i : a[v]) {
        if (i != p) dfs(i, v, now + 1);
    }
}


signed main() {
    int n;
    cin >> n;
    a.resize(n);
    pr.resize(n, -1);
    gl.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
    dfs(0, -1, 0);
    while (!b.empty()) {
        ++ans;
        auto tmp = *b.rbegin();
        int now = pr[tmp.second];
        b.erase({gl[now], now});
        for (int i : a[now]) {
            b.erase({gl[i], i});
        }
    }
    cout << ans;
}