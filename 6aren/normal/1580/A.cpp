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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> pref(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) pref[i][j] = s[i][j] - '0';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i][j] += (i > 0 ? pref[i - 1][j] : 0) + (j > 0 ? pref[i][j - 1] : 0) - (i > 0 && j > 0 ? pref[i - 1][j - 1] : 0);
        }
    }

    auto calc = [&](int x, int y, int xx, int yy) {
        return pref[xx][yy] - (x > 0 ? pref[x - 1][yy] : 0) - (y > 0 ? pref[xx][y - 1] : 0) + (x > 0 && y > 0 ? pref[x - 1][y - 1] : 0);
    };

    auto icalc = [&](int x, int y, int xx, int yy) {
        return (xx - x + 1) * (yy - y + 1) - calc(x, y, xx, yy);
    };

    // debug(pref[0]);

    int res = 1e9;
    for (int i = 1; i + 1 < n; i++) {
        for (int j = 1; j + 1 < m; j++) {
            for (int x = i + 2; x + 1 < n; x++) {
                for (int y = j + 1; y + 1 < m; y++) {
                    int foo = calc(i, j, x, y) + icalc(i - 1, j, i - 1, y) + icalc(i, j - 1, x, j - 1); 
                    // debug(calc(i, j, x, y));
                    // debug(calc(i - 1, j, i - 1, y));
                    // debug(i - 1, j, i - 1, y);
                    int tmp = foo + icalc(x + 1, j, x + 1, y) + icalc(i, y + 1, x, y + 1);
                    if (tmp < res) res = tmp;
                    if (foo >= 20) break;
                }
            }
        }
    }
    cout << res << '\n';
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