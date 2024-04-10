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

vector <vector <int>> gr;
vector <int> par, d;

void dfs_parents(int v, int p = -1) {
    if (p != -1)
        par[v] = p, d[v] = d[p] + 1;
    for (int u : gr[v])
        if (u != p)
            dfs_parents(u, v);
}

vector <int> sz;
vector <bool> is_deleted;

int recalc_sz(int v, int p) {
    sz[v] = 1;
    for (int u : gr[v]) 
        if (u != p && !is_deleted[u])
            sz[v] += recalc_sz(u, v);
    return sz[v];
}

int find_centroid(int v, int p, int subtree_sz) {
    for (int u : gr[v])
        if (u != p && !is_deleted[u] && 2 * sz[u] >= subtree_sz)
            return find_centroid(u, v, subtree_sz);
    return v;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), gr[u].pb(v);
    }
    par = d = sz = vector <int> (n);
    is_deleted = vector <bool> (n);
    dfs_parents(0);
    int v = 0, depth;
    cout << "d 1" << endl;
    cin >> depth;
    while (true) {
        recalc_sz(v, -1);
        if (sz[v] == 1)
            return cout << "! " << v + 1 << endl, 0;
        v = find_centroid(v, -1, sz[v]);
        is_deleted[v] = 1;
        cout << "d " << v + 1 << endl;
        int ans;
        cin >> ans;
        if (!ans)
            return cout << "! " << v + 1 << endl, 0;
        if (d[v] + ans != depth) {
            v = par[v];
        } else {
            cout << "s " << v + 1 << endl;
            int u;
            cin >> u, u--;
            v = u;
        }
    }
    return 0;
}