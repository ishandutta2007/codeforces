#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 150005, K = 80;
int a[maxn], f[maxn];
int ans = 0, R, good = 0, ptr, numb = 1, uk = 0;
int best[maxn], sz[maxn];
vector < int > g[maxn];
pair < int, int > lines[maxn];
int need[maxn], oks[maxn];

long double inter(pair < int, int > s1, pair < int, int > s2) {
    return (s1.second - s2.second) / (long double)(s2.first - s1.first);
}

void build(int v, int p) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (u == p || f[u]) continue;
        build(u, v);
        sz[v] += sz[u];
    }
}

void calc(int v, int p, int sum, int pref) {
    pref += a[v];
    sum += pref;
    ans = max(ans, sum);
    for (auto u : g[v]) if (u != p && f[u] == 0) calc(u, v, sum, pref);
}

void calc1(int v, int p, int sum, int h) {
    sum += h * a[v];
    ans = max(ans, sum);
    for (auto u : g[v]) {
        if (u == p || f[u]) continue;
        calc1(u, v, sum, h + 1);
    }
}

void dfs1(int v, int p, int sum, int pref, int h) {
    sum += a[v] * h;
    pref += a[v];
    /*for (int i = 1; i <= R; ++i) {
        ans = max(ans, i * pref + sum + best[i]);
    }*/
    for (int j = 1; j < ptr; ++j) {
        int i = need[j];
        ans = max(ans, i * pref + sum + best[i]);
    }
    int lef = 0, righ = uk;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (inter(lines[mid - 1], lines[mid]) <= pref) lef = mid;
        else righ = mid;
    }
    if (lef < uk) ans = max(ans, lines[lef].first * pref + lines[lef].second + sum);
    for (auto u : g[v]) {
        if (u == p || f[u]) continue;
        dfs1(u, v, sum, pref, h + 1);
    }
}

void add(int v, int p, int sum, int pref, int h) {
    pref += a[v];
    sum += pref;
    R = max(R, h);
    if (sum > best[h]) {
        best[h] = max(best[h], sum);
        if (oks[h] != numb) {
            need[ptr++] = h;
            good++;
            oks[h] = numb;
        }
    }
    for (auto u : g[v]) {
        if (u == p || f[u]) continue;
        add(u, v, sum, pref, h + 1);
    }
}

void dfs(int v) {
    build(v, -1);
    int N = sz[v], p = -1;
    bool find = true;
    while (find) {
        find = false;
        for (auto u : g[v]) {
            if (u == p || f[u]) continue;
            if (sz[u] >= N / 2) {
                p = v, v = u, find = true;
                break;
            }
        }
    }
    ans = max(ans, a[v]);
    for (auto u : g[v]) {
        if (f[u]) continue;
        calc(u, v, a[v], a[v]);
        calc1(u, v, a[v], 2);
    }
    R = 0, uk = 0;
    ptr = 1, good = 0;
    numb++;
    for (auto u : g[v]) {
        if (f[u]) continue;
        dfs1(u, v, 0, 0, 1);
        add(u, v, a[v], a[v], 2);
        if (good >= K) {
            ptr = 1, good = 0, numb++, uk = 0;
            for (int i = 1; i <= R; ++i) {
                while (uk > 1) {
                    if (inter(lines[uk - 1], {i, best[i]}) <= inter(lines[uk - 1], lines[uk - 2])) uk--;
                    else break;
                }
                lines[uk++] = {i, best[i]};
            }
        }
    }
    for (int i = 1; i <= R; ++i) best[i] = 0;
    reverse(g[v].begin(), g[v].end());
    R = 0, uk = 0;
    ptr = 1, good = 0;
    numb++;
    for (auto u : g[v]) {
        if (f[u]) continue;
        dfs1(u, v, 0, 0, 1);
        add(u, v, a[v], a[v], 2);
        if (good >= K) {
            ptr = 1, good = 0, numb++, uk = 0;
            for (int i = 1; i <= R; ++i) {
                while (uk > 1) {
                    if (inter(lines[uk - 1], {i, best[i]}) <= inter(lines[uk - 1], lines[uk - 2])) uk--;
                    else break;
                }
                lines[uk++] = {i, best[i]};
            }
        }
    }
    for (int i = 1; i <= R; ++i) best[i] = 0;
    f[v] = 1;
    for (auto u : g[v]) if (f[u] == 0) dfs(u);
}

main() {
#ifdef HOME
    freopen("input.txt", "r",  stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1);
    cout << ans << '\n';
    return 0;
}