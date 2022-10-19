#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(2 * n + m + 1);
        map<pair<int, int>, int> res;
        vector<pair<int, int>> edges;
        int cur = n;
        for (int i = 1; i < n; i++) {
            int u, v, x;
            cin >> u >> v >> x;
            edges.push_back({u, v});
            if (x >= 0) {
                int xx = __builtin_popcount(x);
                res[{u, v}] = res[{v, u}] = x + 1;
                if (xx % 2) {
                    g[u].push_back(v), g[v].push_back(u);
                } else {
                    cur++;
                    g[u].push_back(cur), g[v].push_back(cur);
                    g[cur].push_back(u), g[cur].push_back(v);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            if (p == 0) {
                cur++;
                g[a].push_back(cur);
                g[cur].push_back(a);
                g[b].push_back(cur);
                g[cur].push_back(b);
            } else {
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }

        vector<int> col(cur + 1);

        bool ok = true;
        
        function<void(int, int)> dfs = [&](int u, int color) {
            col[u] = color;
            for (int e : g[u]) {
                if (col[e] == 0) dfs(e, 3 - color);
                else if (col[e] == color) ok = false;
            }
        };

        for (int i = 1; i <= cur; i++) {
            if (!col[i]) dfs(i, 1);
        }

        if (ok == false) {
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
            for (auto e : edges) {
                if (res[e] > 0) {
                    cout << e.first << ' ' << e.second << ' ' << res[e] - 1 << '\n';
                } else {
                    cout << e.first << ' ' << e.second << ' ' << (col[e.first] != col[e.second] ? 1 : 0) << '\n';
                }
            }
        }

    }
    return 0;
}