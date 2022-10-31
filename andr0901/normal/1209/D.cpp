#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

class Dsu {
private:
    int n;
    vector <int> p, sz;
public:
    Dsu(int _n) {
        n = _n;
        p.resize(n, -1);
        sz.resize(n, 1);
    }

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
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    Dsu a(n);
    int ans = m;
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        if (a.get(v) != a.get(u)) {
            ans--;
            a.unite(v, u);
        }
    }
    cout << ans;
    return 0;
}