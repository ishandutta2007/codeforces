#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(char c) { return string(1, c); }
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
#ifdef GAREN
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void run_case(int test) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> is_leaf(n, true), is_bud(n);
    vector<int> par(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    is_leaf[0] = false;

    function<void(int, int)> dfs = [&](int u, int p) {
        for (int e : g[u]) {
            if (e == p) continue;
            par[e] = u;
            dfs(e, u);
        };
        is_bud[u] = (u != 0 && !is_leaf[u]);
        for (int e : g[u]) {
            if (e == p) continue;
            if (is_leaf[e]) {
                is_leaf[u] = false;
                break;
            }
        }
        is_bud[u] = !is_leaf[u];
    };

    dfs(0, -1);

    int cnt_bud = 0;
    int cnt_leaf = 0;
    bool leaf_not_bud = false;
    is_bud[0] = is_leaf[0] = false;
    for (int i = 1; i < n; i++) {
        cnt_bud += is_bud[i];
        cnt_leaf += is_leaf[i];
        if (is_leaf[i] && !is_bud[par[i]]) leaf_not_bud = true;
    }
    // debug(is_leaf);
    // debug(is_bud);
    // debug(leaf_not_bud);
    cout << cnt_leaf - cnt_bud + (1 - leaf_not_bud) << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    cin >> tests;
    for (int test = 1; test <= tests; test++) run_case(test);
    return 0;
}