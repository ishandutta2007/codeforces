#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;



int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, m, h;
    scanf("%d%d%d", &n, &m, &h);
    vector<int> tmr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmr[i]);
    }
    vector<vector<int>> e(n);
    vector<vector<int>> g(n);
    auto addE = [&](int v, int u) {
        e[v].pb(u);
        g[u].pb(v);
    };


    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        if ((tmr[v] + 1) % h == tmr[u]) {
            addE(v, u);
        }
        if ((tmr[u] + 1) % h == tmr[v]) {
            addE(u, v);
        }
    }
    vector<int> used(n);
    vector<int> st;
    function<void(int)> dfs = [&](int v) {
        used[v] = 1;
        for (auto u: e[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
        st.pb(v);
    };

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(all(st));

    used.assign(n, 0);
    vector<int> who;
    vector<int> color(n);
    vector<vector<int>> where;
    int cc = 0;

    function<void(int)> dfs2 = [&](int v) {
        used[v] = 1;
        color[v] = cc;
        who.pb(v);
        for (auto u: g[v]) {
            if (!used[u]) {
                dfs2(u);
            }
        }
    };


    for (auto v: st) {
        if (!used[v]) {
            who.clear();
            dfs2(v);
            cc++;
            where.pb(who);
        }
    }

    vector<int> bad(cc);
    for (int v = 0; v < n; v++) {
        for (auto u: e[v]) {
            if (color[v] != color[u]) {
                bad[color[v]] = 1;
            }
        }
    }
    int best = -1;
    for (int i = 0; i < cc; i++) {
        if (bad[i] == 0 && (best == -1 || where[best].size() > where[i].size())) {
            best = i;
        }
    }
    assert(best != -1);
    printf("%d\n", sz(where[best]));
    for (auto x: where[best]) {
        printf("%d ", x + 1);
    }
    puts("");











    return 0;
}