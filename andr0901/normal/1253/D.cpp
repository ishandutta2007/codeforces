#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
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
    vector <pii> vals;

    Dsu(int _n) {
        n = _n;
        p.resize(n, -1);
        sz.resize(n, 1);
        vals.resize(n);
        forn (i, 0, n)
            vals[i] = {i, i};
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
        vals[u].fs = vals[v].fs = min(vals[u].fs, vals[v].fs);
        vals[u].sc = vals[v].sc = max(vals[u].sc, vals[v].sc);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    Dsu a(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        a.unite(v, u);
    }
    int ans = 0, r = -1;
    forn (i, 0, n) {
        if (i <= r && a.get(i) != a.get(i - 1)) {
            a.unite(i, i - 1);
            ans++;
        }
        r = max(r, a.vals[i].sc);
        //cout << r << " ";
    }
    cout << ans;
    return 0;
}