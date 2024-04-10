#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define foi(n) for (int i = 0; i < n; i++)
#define foj(n) for (int j = 0; j < n; j++)
#define fo(i, n) for (int i = 0; i < n; i++)
#define vei vector<int>
#define pii pair<int, int>
#define mp make_pair
#define fs first
#define sc second
#define null NULL

typedef long long ll;

using namespace std;

struct Dsu {
    vei a;

    void init(int n) {
        a.resize(n);
        foi(n) a[i] = i;
    }

    int get(int x) {
        return x == a[x] ? x : (a[x] = get(a[x]));
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (rand() & 1) {
            a[x] = y;
        } else {
            a[y] = x;
        }
    }
};

vector<vei> g;
vector<bool> used;

void dfs(int v, int p, int d, int &mi, int &md) {
    used[v] = true;
    if (d > md) {
        md = d;
        mi = v;
    }
    for (auto i : g[v]) {
        if (i != p) {
            dfs(i, v, d + 1, mi, md);
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vei mm(n);
    Dsu dsu;
    dsu.init(n);
    g.resize(n);
    foi(m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        dsu.unite(x, y);
        g[x].pb(y);
        g[y].pb(x);
    }
    used.resize(n);
    foi(n) {
        if (!used[i]) {
            int mi = -1, md = -1;
            dfs(i, -1, 0, mi, md);
            dfs(mi, -1, 0, mi, md);
            mm[dsu.get(i)] = md;
        }
    }

    foi(q) {
        int t, x, y;
        cin >> t >> x;
        --x;
        if (t == 1) {
            cout << mm[dsu.get(x)] << endl;
        } else {
            cin >> y;
            --y;
            x = dsu.get(x);
            y = dsu.get(y);
            if (x != y) {
                int m = max((mm[x] + 1) / 2 + (mm[y] + 1) / 2 + 1, max(mm[x], mm[y]));
                dsu.unite(x, y);
                mm[dsu.get(x)] = m;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}