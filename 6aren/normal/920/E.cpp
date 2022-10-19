#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 200005;
vector<int> g[N];
int n, m;

long long Rand(long long l, long long h) {
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

struct DSU {
    int n;
    vector<int> p;

    DSU(int _n) {
        n = _n;
        p.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    int root(int x) {
        return (p[x] == x) ? x : (p[x] = root(p[x]));
    }

    void merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return;
        p[x] = y;
    }

    bool inTheSameSet(int x, int y) {
        return (root(x) == root(y));
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m;  
    DSU dsu = DSU(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        g[i].pb(0);
        g[i].pb(n + 1);
        g[i].pb(i);
        sort(all(g[i]));
    }
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(all(g[i]), i) - g[i].begin();
        for (int j = k; j > 0; j--) {
            if (g[i][j] - g[i][j - 1] > 1) {
                for (int rep = 0; rep < 10; rep++) {
                    int foo = Rand(g[i][j - 1] + 1, g[i][j] - 1);
                    dsu.merge(foo, i);
                }
            }
        }
        for (int j = k + 1; j < sz(g[i]) - 1; j++) {
            if (g[i][j + 1] - g[i][j] > 1) {
                for (int rep = 0; rep < 10; rep++) {
                    int foo = Rand(g[i][j] + 1, g[i][j] - 1);
                    dsu.merge(foo, i);
                }
            }
        }
    }
    vector<int> check(n + 1);
    for (int i = 1; i <= n; i++) {
        check[dsu.root(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += !!check[i];
    }
    sort(all(check));
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        if (check[i]) cout << check[i] << ' ';
    }
    return 0;
}