#include<bits/stdc++.h>

using namespace std;

int const maxn = 5e5 + 5;
int a[maxn], b[maxn], n, used[(1 << 20)];
int A[maxn], B[maxn], cur, ptr[(1 << 20)];
vector < vector < int > > g[(1 << 20)];
vector < pair < int, int > > ans;

void dfs1(int v) {
    while (ptr[v] < (int)g[v].size()) {
        if (used[g[v][ptr[v]][1]] == cur) {
            ptr[v]++;
            continue;
        }
        used[g[v][ptr[v]][1]] = cur;
        int t = g[v][ptr[v]][1], p = g[v][ptr[v]][2];
        dfs1(g[v][ptr[v]][0]);
        ans.push_back({t, p});
    }
}

void dfs(int v) {
    used[v] = cur;
    for (auto u : g[v]) if (used[u[0]] != cur) dfs(u[0]);
}

inline int oks(int x) {
    cur++;
    int mask = (1 << x) - 1, was = 0;
    for (int i = 0; i <= mask; ++i) g[i] = {};
    for (int i = 1; i <= n; ++i) {
        A[i] = (a[i]&mask), B[i] = (b[i]&mask);
        g[A[i]].push_back({B[i], i, 0});
        g[B[i]].push_back({A[i], i, 0});
    }
    for (int i = 0; i <= mask; ++i) {
        if ((int)g[i].size() % 2 == 1) return 0;
    }
    for (int i = 0; i <= mask; ++i) {
        if (used[i] != cur && (int)g[i].size() > 0) {
            if (was) return 0;
            dfs(i);
            was = 1;
        }
    }
    return 1;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    int lef = 0, righ = 21;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (oks(mid)) lef = mid;
        else righ = mid;
    }
    cout << lef << '\n';
    int mask = (1 << lef) - 1;
    for (int i = 0; i <= mask; ++i) g[i] = {};
    for (int i = 1; i <= n; ++i) {
        A[i] = (a[i]&mask), B[i] = (b[i]&mask);
        g[A[i]].push_back({B[i], i, 0});
        g[B[i]].push_back({A[i], i, 1});
    }
    cur++;
    dfs1(A[1]);
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (ans[i].second == 1) cout << ans[i].first * 2 - 1 << " " << ans[i].first * 2 << " ";
        else cout << ans[i].first * 2 << " " << ans[i].first * 2 - 1 << " ";
    }
    return 0;
}