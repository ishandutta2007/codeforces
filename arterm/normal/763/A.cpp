#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
typedef long double ld;
typedef long long ll;
typedef long long i64;

const int M = 100100;
typedef pair<int, int> pii;

int n, c[M];
vector<int> g[M];
int ans = -1;
int a[M];

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
        cin >> c[i];
}

int merge(int x, int y) {
    if (x == -2)
        return y;

    if (y == -2)
        return x;

    if (x == y)
        return x;
    else
        return -1;
}

int dfs(int v, int from) {
    a[v] = c[v];
    for (int to : g[v]) {
        if (to != from)
            a[v] = merge(a[v], dfs(to, v));
    }
    return a[v];
}

void dfs2(int v, int from, int up) {
    vector<int> cs;
    vector<int> ts;
    vector<int> pref, suff;

    int is = false;

    for (int to : g[v])
        if (to != from) {
            cs.push_back(a[to]);
            ts.push_back(to);
            is |= a[to] == -1;
        }

    if (up != -1 && !is) {
        ans = v;
        //cerr << "v = " << v << ", up = " << up << endl;
    }

    pref.push_back(merge(up, c[v]));
    for (int x : cs) {
        pref.push_back(merge(pref.back(), x));
    }

    reverse(cs.begin(), cs.end());
    suff.push_back(merge(up, c[v]));
    for (int x : cs)
        suff.push_back(merge(suff.back(), x));

    int m = ts.size();
    for (int i = 0; i < m; ++i) {
        dfs2(ts[i], v, merge(pref[i], suff[m - i - 1]));
    }
}

void kill() {
    dfs(0, 0);
    dfs2(0, 0, -2);
    if (ans == -1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        cout << ans + 1 << endl;
    }
}

int main() {
#ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);

    read();
    kill();

}