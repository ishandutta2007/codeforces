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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(n, vector<int>(n));
    vector<vector<int>> res(n, vector<int>(n));

    auto get = [&](int x, int y) {
        return (x > 0 ? res[x - 1][y] : 0) ^ (y > 0 ? res[x][y - 1] : 0) ^ (x != n - 1 ? res[x + 1][y] : 0) ^ (y != n - 1 ? res[x][y + 1] : 0);
    };
    
    auto calc = [&]() {
        for (int c = 0; c < 2; c++) {
            res[0][0] = c;
            for (int i = 2; i < n; i += 2) {
                res[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    res[i - j][j] = b[i - j][j - 1] ^ res[i - j + 1][j - 1] ^ (i - j > 0 ? res[i - j - 1][j - 1] : 0) ^ (j - 1 > 0 ? res[i - j][j - 2] : 0);
                }
            }
            for (int i = (n - 1) - (n - 1) % 2 + 2; i <= 2 * (n - 1); i += 2) {
                for (int j = i - n + 1; j < n; j++) {
                    res[i - j][j] = b[i - j][j - 1] ^ res[i - j - 1][j - 1] ^ (j - 1 > 0 ? res[i - j][j - 2] : 0) ^ (i - j == n - 1 ? 0 : res[i - j + 1][j - 1]);
                }
            }
            bool ok = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 2 && get(i, j) != b[i][j]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) break;
        }
        bool found = false;
        for (int u = 0; u < 2; u++) {
            for (int v = 0; v < 2; v++) {
                res[0][1] = u; res[1][0] = v;
                for (int i = 3; i < n; i += 2) {
                    res[i][0] = 1;
                    for (int j = 1; j <= i; j++) {
                        res[i - j][j] = b[i - j][j - 1] ^ res[i - j + 1][j - 1] ^ (i - j > 0 ? res[i - j - 1][j - 1] : 0) ^ (j - 1 > 0 ? res[i - j][j - 2] : 0);
                    }
                } 
                int from = (n % 2 ? n : n + 1);
                for (int i = from; i <= 2 * (n - 1); i += 2) {
                    for (int j = i - n + 1; j < n; j++) {
                        res[i - j][j] = b[i - j][j - 1] ^ res[i - j - 1][j - 1] ^ (j - 1 > 0 ? res[i - j][j - 2] : 0) ^ (i - j == n - 1 ? 0 : res[i - j + 1][j - 1]);
                    }
                } 
                bool ok = 1;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if ((i + j) % 2 == 0 && get(i, j) != b[i][j]) {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        // debug(res);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) ans ^= res[i][j];
        }
        return ans;
    };

    int ans = 0;

    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                b[j][k] = (a[j][k] >> i) & 1;
            }
        }
        ans += (calc() << i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}