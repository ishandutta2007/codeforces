#pragma GCC optmize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

vector <vector <int>> gr;
set <pii> br;
multiset <pii> edges;
vector <bool> used;
vector <int> tin, fup;
int timer = 0;

void dfs(int v, int p) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for (auto u : gr[v]) {
        if (u == p)
            continue;
        if (used[u])
            fup[v] = min(fup[v], tin[u]);
        else {
            dfs(u, v);
            fup[v] = min(fup[v], fup[u]);
            if (fup[u] > tin[v] && edges.count({min(v, u), max(v, u)}) <= 1)
                br.insert({min(v, u), max(v, u)});
        }
    }
}

vector <int> colors;
void dfs2(int v, int col) {
    colors[v] = col;
    for (auto u : gr[v])
        if (!colors[u] && br.find({min(v, u), max(v, u)}) == br.end())
            dfs2(u, col);
}

vector <vector <int>> gr2;
vector <pii> dp;
vector <bool> used2;

void dfs3(int v, int par) {
    used2[v] = 1;
    pii m = {-1, -1};
    for (auto u : gr2[v]) {
        if (u == par)
            continue;
        dfs3(u, v);
        if (dp[u].fs >= m.fs) {
            m.sc = m.fs;
            m.fs = dp[u].fs;
        } else if (dp[u].fs >= m.sc) {
            m.sc = dp[u].fs;
        }
    }
    dp[v] = {m.fs + 1, m.sc + 1};
    if (par == -1) {
        if (gr2[v].size() == 1)
            dp[v].sc = 0;
        if (gr2[v].size() == 0)
            dp[v].fs = dp[v].sc = 0;
        return;
    }
    if (gr2[v].size() == 1)
        dp[v].fs = dp[v].sc = 0;
    if (gr2[v].size() == 2)
        dp[v].sc = 0;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    forn (i, 0, m) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--, t2--;
        gr[t1].pb(t2), gr[t2].pb(t1);
        edges.insert({min(t1, t2), max(t1, t2)});
    }
    used.resize(n), tin.resize(n), fup.resize(n);
    forn (i, 0, n)
        if (!used[i])
            dfs(i, -1);
    colors.resize(n);
    int cur = 1;
    forn (i, 0, n)
        if (!colors[i])
            dfs2(i, cur++);
    gr2.resize(cur);
    for (auto i : br) {
        gr2[colors[i.fs] - 1].pb(colors[i.sc] - 1);
        gr2[colors[i.sc] - 1].pb(colors[i.fs] - 1);
    }
    dp.resize(cur), used2.resize(cur);
    forn (i, 0, cur)
        if (!used2[i])
            dfs3(i, -1);
    int mx = -1;
    forn (i, 0, cur)
        mx = max(mx, dp[i].fs + dp[i].sc);
    //cout << br.size() << " " << mx << "\n";
    cout <<  mx;
    return 0;
}