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
    
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cur = 0;
    vector<vector<int>> ss(n + 1);
    vector<int> pos(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        // leaf
        if (g[u].size() == 1 && g[u][0] == p) {
            pos[u] = cur;
            ss[cur].push_back(1);
            cur++;
            return;
        }

        bool first = true;
        for (int e : g[u]) {
            if (e == p) continue;
            dfs(e, u);
            if (first) {
                first = false;
                pos[u] = pos[e];
            } else {
                // merge
                int a = pos[u];
                int b = pos[e];
                if (ss[a].size() < ss[b].size()) swap(a, b);
                pos[u] = a;
                // merge b into a
                for (int e : ss[b]) {
                    ss[a].push_back(e);
                    if (ss[a].back() > ss[a][0]) swap(ss[a][0], ss[a].back());
                }
                ss[b].clear();
            }
        }
        ss[pos[u]][0]++;
    };

    dfs(1, 0);

    vector<int> foo = ss[pos[1]];
    sort(foo.rbegin(), foo.rend());

    vector<int> dp(k + 1);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        if (i > foo.size()) dp[i] = dp[i - 1];
        else {
            dp[i] = foo[i - 1] + dp[i - 1];
        }
    }

    // debug(dp);

    long long res = -1e18;

    auto eval = [&](long long x, long long a, long long b, long long c) {
        return x * x * a + b * x + c;
    };

    auto getMin = [&](long long a, long long b, long long c, long long l, long long r) {
        long long foo = -b / (2 * a);
        long long best = 1e18;
        for (long long i = max(l, foo - 2); i <= min(r, foo + 2); i++) {
            best = min(best, eval(i, a, b, c));
        }
        best = min({best, eval(l, a, b, c), eval(r, a, b, c)});
        return best;
    };

    for (int i = 1; i <= k; i++) {
        int w = dp[i] - i;
        int r = i, b = (n - dp[i]);
        res = max(res, getMin(1, r + w - b, 1LL * w * (r - b), 0, b));
    }

    cout << res << '\n';

    return 0;
}