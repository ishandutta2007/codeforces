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
    vector<vector<int>> pos(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        dp[r][r] = 0;
        for (int l = r - 1; l >= 0; l--) {
            dp[l][r] = 1 + dp[l + 1][r];
            for (int p : pos[a[l]]) {
                if (p > l && p <= r) {
                    dp[l][r] = min(dp[l][r], dp[l][p - 1] + dp[p][r]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
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