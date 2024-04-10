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

int mex(vector<int> a) {
    vector<int> check(3);
    for (int e : a) check[e] = true;
    for (int i = 0; i < 3; i++) if (!check[i]) return i;
    return 3;
}

void run_case(int test) {
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<int> last(2, -1), dp(n);
    for (int i = 0; i < n; i++) {
        vector<int> foo = {s[0][i] - '0', s[1][i] - '0'};
        dp[i] = (i > 0 ? dp[i - 1] : 0) + mex(foo);
        last[s[0][i] - '0'] = i;
        last[s[1][i] - '0'] = i;
        if (last[0] != -1) dp[i] = max(dp[i], (last[0] > 0 ? dp[last[0] - 1] : 0) + 1);
        int baz = min(last[0], last[1]);
        if (baz != -1) dp[i] = max(dp[i], (baz > 0 ? dp[baz - 1] : 0) + 2);
    }
    cout << dp[n - 1] << '\n';
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