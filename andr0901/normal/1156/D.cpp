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
    sz[u] += sz[v], p[v] = u;
}

vector <vector <int>> gr;
vector <bool> used;
int a = 0, b = 0;

void dfs(int v) {
    used[v] = 1;
    a++, b += sz[get(v)] - 1;
    for (auto u : gr[v]) 
        if (!used[u])
            dfs(u);
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    p.resize(n, -1), sz.resize(n, 1);
    forn (i, 1, n) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        if (w)
            unite(v, u);
        else 
            gr[v].pb(u), gr[u].pb(v);
    }
    used.resize(n);
    ll ans = 0;
    forn (i, 0, n) {
        if (used[i])
            continue;
        a = 0, b = 0;
        dfs(i);
        ans += 1LL * a * (a + b - 1);
    }
    cout << ans;
    return 0;
}