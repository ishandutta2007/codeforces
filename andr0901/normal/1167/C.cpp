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
    int n, m;
    cin >> n >> m;
    p.resize(n + m, -1), sz.resize(n + m);
    forn (i, 0, n)
        sz[i] = 1;
    forn (i, 0, m) {
        int k;
        cin >> k;
        forn (j, 0, k) {
            int t;
            cin >> t;
            t--;
            unite(t, i + n);
        }
    }
    forn (i, 0, n)
        cout << sz[get(i)] << " ";
    return 0;
}