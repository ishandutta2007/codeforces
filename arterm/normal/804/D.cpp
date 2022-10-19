// vim:ts=4:sts=4:sw=4:et
// MOSCOW IPT JINOTEGA
// Table #14
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef long long i64;

#define int ll

const int M = 100100;

int n, m, q;
int k = 0;
int d[M], c[M], x[M];
ld b[M];
int diam[M];
vector<int> e[M];
vector<int> g[M];
vector<int> t[M];
vector<ll> pref[M];
map<pair<int, int>, ld> cache;

void add(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void read() {
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        add(u, v);
    }
}

void dfs1(int v, int from, int col, int depth) {
    t[col].push_back(v);
    c[v] = col;
    d[v] = depth;
    x[v] = 0;
    for (int to : g[v])
        if (to != from) {
            dfs1(to, v, col, depth + 1);
        }
}

void dfs2(int v, int from, int cur) {
    x[v] = max(cur, x[v]);
    for (int to : g[v])
        if (to != from) {
            dfs2(to, v, cur + 1);
        }
}

ld fun(int x, int y) {
    if (x == y)
        return -1;

    if (e[x].size() > e[y].size())
        swap(x, y);
    if (e[x].size() == e[y].size() && x > y)
        swap(x, y);
    
    auto enc = make_pair(x, y);
    if (cache.count(enc))
        return cache[enc];

    int D = max(diam[x], diam[y]);
    int sx = e[x].size(), sy = e[y].size();

    ll ans = pref[x].back() * sy + pref[y].back() * sx + 1ll * sx * sy;

    for (int len : e[x]) {
        ++len;
        int j = upper_bound(all(e[y]), D - len) - e[y].begin();
        ans -= len * j + pref[y][j];
        ans += j * D;
    }

    return cache[enc] = 1.0 * ans / sx / sy;
}

void kill() {
    fill(c, c + n, -1);
    for (int i = 0; i < n; ++i) {
        if (c[i] == -1) {
            dfs1(i, -1, k, 0);

            //for (int v : t) {
                //cerr << v << " ";
            //}
            //cerr << "!\n";

            int best = *max_element(all(t[k]),
                    [&](int x, int y) {
                        return d[x] < d[y];
                    });

            dfs2(best, -1, 0);

            best = *max_element(all(t[k]),
                    [&](int a, int b) {
                        return x[a] < x[b];
                    });

            diam[k] = x[best];
            dfs2(best, -1, 0);

            for (int v : t[k])
                e[k].push_back(x[v]);
            sort(all(e[k]));

            pref[k].push_back(0);
            for (int t : e[k])
                pref[k].push_back(pref[k].back() + t);

            //for (int v : t) {
                //cerr << x[v] << " ";
            //}
            //cerr << "!!\n";


            ++k;
        }
    }


    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        //cerr << c[u] << " " << c[v] << endl;

        cout << fun(c[u], c[v]) << "\n";
    }
}

signed main() {
#ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    
    cout.precision(9);
    cout << fixed;

    read();
    kill();

    return 0;
}