#include <bits/stdc++.h>

using namespace std;

int const maxn = 200005;
int p[maxn];
int q[maxn];
vector < int > g[maxn];
vector < int > G[maxn];
vector < int > new_g[maxn];
int used[maxn];
int go[maxn];
vector < int > topsort;
int numb[maxn];
int cur;
char get_ans[maxn];

void dfs4(int v, int h) {
    used[v] = 4;
    h = max(h, 0);
    get_ans[v] = char('a' + h);
    for (auto u : new_g[v]) if (used[u] != 4) dfs4(u, h - 1);
}

void dfs3(int v) {
    used[v] = 3;
    for (auto u : new_g[v]) if (used[u] != 3) dfs3(u);
    topsort.push_back(v);
}

void dfs2(int v) {
    used[v] = 2;
    numb[v] = cur;
    for (auto u : g[v]) if (used[u] == 1) dfs2(u);
}

void dfs1(int v) {
    used[v] = 1;
    for (auto u : G[v]) {
        if (used[u] != 1) dfs1(u);
    }
    topsort.push_back(v);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> q[i];
    if (n == 1) {
        if (k == 1) {
            cout << "YES" << '\n';
            cout << "a" << '\n';
            return 0;
        }
        cout << "NO" << '\n';
        return 0;
    }
    for (int i = 2; i <= n; ++i) {
        g[p[i]].push_back(p[i - 1]);
        g[q[i]].push_back(q[i - 1]);
        G[p[i - 1]].push_back(p[i]);
        G[q[i - 1]].push_back(q[i]);
    }
    for (int i = 1; i <= n; ++i) if (used[i] == 0) dfs1(i);
    for (int i = n - 1; i >= 0; --i) {
        if (used[topsort[i]] == 1) cur++, dfs2(topsort[i]);
    }
    if (cur < k) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    for (int i = 2; i <= n; ++i) {
        if (numb[p[i]] != numb[p[i - 1]]) new_g[numb[p[i]]].push_back(numb[p[i - 1]]), go[numb[p[i - 1]]]++;
        if (numb[q[i]] != numb[q[i - 1]]) new_g[numb[q[i]]].push_back(numb[q[i - 1]]), go[numb[q[i - 1]]]++;
    }
    /*topsort = {};
    for (int i = 1; i <= cur; ++i) dfs3(i);
    for (int i = cur - 1; i >= 0; --i) {
        if (used[topsort[i]] != 4) dfs4(topsort[i], 25);
    }*/
    for (int i = 1; i <= cur; ++i) if (go[i] == 0) dfs4(i, 25);
    for (int i = 1; i <= n; ++i) {
        cout << get_ans[numb[i]];
    }
    return 0;
}