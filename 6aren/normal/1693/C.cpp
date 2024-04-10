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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dg(n);
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[v].push_back(u);
        deg[u]++;
    }
    vector<int> d(n, 1e9);
    d[n - 1] = 0;
    set<pair<int, int>> s;
    vector<int> done(n);
    s.insert({0, n - 1});
    while (!s.empty()) {
        auto [dis, v] = *s.begin();
        s.erase(s.begin());
        if (done[v]) continue;
        done[v] = true;
        for (int e : g[v]) {
            deg[e]--;
        }
        for (int e : g[v]) {
            if (d[e] > deg[e] + dis + 1) {
                s.insert({deg[e] + dis + 1, e});
            }
            d[e] = min(d[e], deg[e] + dis + 1);
        }
    }
    cout << d[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}