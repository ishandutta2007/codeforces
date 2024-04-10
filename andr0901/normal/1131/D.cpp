#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <int> p, sz;

int get(int v) {
    if (p[v] == -1)
        return v;
    return p[v] = get(p[v]);
}

void unite(int v, int u) {
    v = get(v), u = get(u);
    if (v == u)
        return;
    if (sz[v] > sz[u])
        swap(v, u);
    p[v] = u;
    sz[u] += sz[v];
}

vector <vector <int>> gr;
vector <int> used, ord;

void dfs_ord(int v) {
    used[v] = 1;
    for (auto u : gr[v]) {
        if (used[u] == 2)
            continue;
        if (used[u] == 1) 
            cout << "No", exit(0);
        dfs_ord(u);
    }
    ord.pb(v);
    used[v] = 2;
}

vector <int> dp;

int dfs(int v) {
    if (dp[v])
        return dp[v];
    if (!sz(gr[v])) 
        return dp[v] = 1;
    for (auto u : gr[v])
        dp[v] = max(dp[v], dfs(u));
    return ++dp[v];
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    forn (i, 0, n) 
        forn (j, 0, m) 
            cin >> a[i][j];
    p.resize(n + m, -1), sz.resize(n + m, 1);
    forn (i, 0, n) 
        forn (j, 0, m)
            if (a[i][j] == '=')
                unite(i, n + j);
    gr.resize(n + m);
    forn (i, 0, n) {
        forn (j, 0, m) {
            if (a[i][j] == '>') 
                gr[get(i)].pb(get(n + j));
            if (a[i][j] == '<')
                gr[get(n + j)].pb(get(i));
        }
    }
    used.resize(n + m);
    forn (i, 0, n + m)
        if (!used[i])
            dfs_ord(i);
    reverse(all(ord));
    dp.resize(n + m);
    forn (i, 0, n + m) 
        dfs(ord[i]);
    cout << "Yes\n";
    forn (i, 0, n)
        cout << dp[get(i)] << " ";
    cout << "\n";
    forn (i, n, n + m)
        cout << dp[get(i)] << " ";
    return 0;
}