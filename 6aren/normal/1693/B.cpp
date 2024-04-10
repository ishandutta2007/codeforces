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
    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    vector<int> a(n);
    
    function<void(int)> dfs = [&](int u) {
        long long foo = 0;
        for (int e : g[u]) {
            dfs(e);
            foo += a[e];
        }
        if (g[u].size() == 0) {
            a[u] = r[u];
            return;
        }
        if (l[u] <= foo) {
            a[u] = min<long long>(foo, r[u]);
        } else {
            a[u] = r[u];
        }
    };

    dfs(0);
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += (g[i].size() == 0);
        if (g[i].size()) {
            long long mn = 0;
            for (int e : g[i]) {
                mn += a[e];
            }
            res += (a[i] > mn);
        }
    }

    cout << res << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}