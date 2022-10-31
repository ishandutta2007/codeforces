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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> edges(m);
    vector <int> a(n);
    forn (i, 0, k) {
        int t;
        cin >> t;
        t--;
        a[t]++;
    }
    forn (i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        edges[i] = {v, u, w};
    }
    sort(all(edges), [&](const vector <int>& a, const vector <int>& b){return a[2] < b[2];});
    int ans = 0;
    p.resize(n, -1), sz.resize(n, 1);
    forn (i, 0, m) { 
        int v = get(edges[i][0]), u = get(edges[i][1]), w = edges[i][2];
        if (v != u) {
            unite(v, u);
            if (sz[v] > sz[u]) 
                a[v] += a[u];
            else 
                a[u] += a[v];
            if (a[v] == k or a[u] == k) {
                ans = w;
                break;
            }
        }
    }
    forn (i, 0, k)
        cout << ans << " "; 
    return 0;
}