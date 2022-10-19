#include <bits/stdc++.h>

using namespace std;
vector <vector <int>> g;
vector <int> p, gl;
vector <bool> now;

void dfs(int v) {
    for (int i : g[v]) {
        if (i == p[v]) continue;
        p[i] = v;
        gl[i] = gl[v] + 1;
        dfs(i);
    }
}
int ans = 0;

void dfs1(int v) {
    int cnt = 0;
    for (int i : g[v]) {
        if (i == p[v] || now[i]) continue;
        ++cnt;
        dfs1(i);
    }
    ans += (cnt == 0);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        ans = 0;
        cin >> n;
        g.assign(n, {});
        p.assign(n, -1);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            g[x - 1].push_back(y - 1);
            g[y - 1].push_back(x - 1);
        }
        gl.assign(n, 0);
        dfs(0);
        now.assign(n, false);
        set <pair <int, int>> s;
        for (int i = 0; i < n; ++i) {
            s.insert(make_pair(gl[i], i));
        }
        int sum = 0, cnt = 0;
        while (!s.empty()) {
            auto cha = *s.rbegin();
            if (cha.first <= 1) break;
            int v = p[cha.second];
            ++cnt;
            now[v] = true;
            s.erase(make_pair(gl[v], v));
            for (int i : g[v]) {
                if (i == p[v]) continue;
                sum += !now[i];
                now[i] = true;
                s.erase(make_pair(gl[i], i));
            }
        }
        dfs1(0);
        cout << ans - cnt + sum << "\n";
    }
}