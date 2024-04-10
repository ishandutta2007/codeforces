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

const int M = 300100;
const int ROOT = 2;

int n, m;
int c[M];
vector<int> g[M];
vector<int> s[M];

void add(int u, int v) {
    //cerr << u << " - " << v << endl;
    g[u].push_back(v);
    g[v].push_back(u);
}

void read() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            --x;
            s[i].push_back(x);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        add(u, v);
    }
}

void dfs(int v, int from) {
    //cerr << v << " " << from << endl;

    int k = s[v].size();
    vector<bool> cur(k, false);
    for (int j : s[v])
        if (c[j] != -1 && c[j] < k)
            cur[c[j]] = true;

    int last = 0;
    for (int j : s[v])
        if (c[j] == -1) {
            while (cur[last])
                ++last;
            c[j] = last;
            assert(last < k);
            cur[last] = true;
        }

    for (int to : g[v])
        if (to != from)
            dfs(to, v);
}

void kill() {
    fill(c, c + m, -1);
    int root = ROOT % n;
    dfs(root, -1);

    for (int i = 0; i < m; ++i)
        if (c[i] == -1)
            c[i] = 0;
    cout << 1 + (*max_element(c, c + m)) << "\n";
    for (int i = 0; i < m; ++i)
        cout << 1 + c[i] << " ";
    cout << "\n";
}

int main() {
#ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);

    read();
    kill();

    return 0;
}