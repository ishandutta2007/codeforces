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

#define int long long

const int INF = 2e18;

void run_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> segs;
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int cnt = upper_bound(a.begin(), a.end(), v) - lower_bound(a.begin(), a.end(), u);
        if (!cnt) segs.emplace_back(u, v);
    }
    sort(segs.begin(), segs.end(), [](pair<int, int> lhs, pair<int, int> rhs) {
        return lhs.second < rhs.second;
    });
    int mx = -INF;
    vector<pair<int, int>> new_segs;
    for (auto &seg : segs) {
        if (seg.first >= mx) {
            new_segs.push_back(seg);
            mx = seg.first;
        }
    }
    swap(new_segs, segs);
    if (segs.size() == 0) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<long long>> dp(n, vector<long long>(2));

    if (segs[0].first < a[0]) dp[0][0] = a[0] - segs[0].second, dp[0][1] = 2 * dp[0][0];

    for (int i = 1; i < n; i++) {
        int l = lower_bound(segs.begin(), segs.end(), make_pair(a[i - 1], INF)) - segs.begin();
        dp[i][0] = dp[i][1] = INF;
        int mx_j = -1;
        for (int j = l; j < segs.size() && segs[j].first < a[i]; j++) {
            if (j == l) {
                dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[i] - segs[j].second);
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * (a[i] - segs[j].second));
            } else {
                dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i] - segs[j].second + segs[j - 1].first - a[i - 1]);
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + 2 * (a[i] - segs[j].second) + segs[j - 1].first - a[i - 1]);
                dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[i] - segs[j].second + 2 * (segs[j - 1].first - a[i - 1]));
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * (a[i] - segs[j].second) + 2 * (segs[j - 1].first - a[i - 1]));
            }
            mx_j = j;
        }
        if (mx_j != -1) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + segs[mx_j].first - a[i - 1]);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + segs[mx_j].first - a[i - 1]);
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2 * (segs[mx_j].first - a[i - 1]));
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * (segs[mx_j].first - a[i - 1]));
        } else {
            dp[i][0] = dp[i][1] = dp[i - 1][0];
        }
        assert(dp[i][0] <= dp[i][1]);
    }
    long long res = -1;
    if (segs.back().first > a.back())
        cout << min(dp[n - 1][1] + segs.back().first - a.back(), dp[n - 1][0] + 2 * (segs.back().first - a.back())) << '\n';
    else
        cout << dp[n - 1][0] << '\n';
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