#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

const int MAXN = 1 << 20;

vector<int> g[MAXN];
int deg[MAXN];
int used[MAXN];

struct Edge {
    int to, i, j, id;
};

vector<Edge> edges;
vector<int> perm;

void euler(int v) {
    while (sz(g[v]) > 0) {
        int id = g[v].back();
        g[v].pop_back();
        if (!used[edges[id].id]) {
            used[edges[id].id] = 1;
            euler(edges[id].to);
            perm.push_back(edges[id].j);
            perm.push_back(edges[id].i);
        }
    }
}


void solve() {
    int n;
    cin >> n;
    vector<pii> p(n);

    // vector<int> val;

    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        // val.push_back(p[i].first);
        // val.push_back(p[i].second);
    }

    int res = 0;

    for (int k = 1; k <= 20; ++k) {

        for (auto [x, y] : p) {
            x &= (1 << k) - 1;
            y &= (1 << k) - 1;
            g[x].push_back(y);
            g[y].push_back(x);
            ++deg[x];
            ++deg[y];
        }

        bool ok = true;
        int cnt = 0;
        int st = 0;

        for (int v = 0; v < (1 << k); ++v) {
            ok &= (deg[v] & 1) == 0;
            if (deg[v] > 0) {
                ++cnt;
                st = v;
            }
        }

        queue<int> q;
        q.push(st);
        used[st] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            --cnt;

            for (int u : g[v]) {
                if (!used[u]) {
                    used[u] = 1;
                    q.push(u);
                }
            }
        }

        memset(deg, 0, sizeof(int) * (1 << k));
        memset(used, 0, sizeof(int) * (1 << k));
        for (int v = 0; v < (1 << k); ++v) {
            g[v].clear();
        }

        ok &= cnt == 0;

        if (!ok) {
            break;
        }

        ++res;
    }

    int st = 0;
    for (int i = 0; i < n; ++i) {
        auto [x, y] = p[i];
        x &= (1 << res) - 1;
        y &= (1 << res) - 1;
        g[x].push_back(sz(edges));
        edges.push_back({y, 2 * i, 2 * i + 1, i});
        g[y].push_back(sz(edges));
        edges.push_back({x, 2 * i + 1, 2 * i, i});
        st = x;
    }

    euler(st);

    cout << res << "\n";
    for (int x : perm) {
        cout << x + 1 << " ";
    }
    cout << "\n";

    // for (int x : perm) {
    //     cout << val[x] << " ";
    // }
    // cout << "\n";


}