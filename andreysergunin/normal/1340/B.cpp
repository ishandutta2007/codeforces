#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

vector<string> dig = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

const int MAXN = 2002;
int dp[MAXN][MAXN];
int delta[MAXN][10];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int t = 0; t < 10; ++t) {
            string d = dig[t];
            int x = 0;
            for (int j = 0; j < 7; ++j) {
                if (s[i][j] == '1' && d[j] == '0') {
                    x = -1;
                    break;
                } else if (s[i][j] != d[j]) {
                    ++x;
                }
            }
            delta[i][t] = x;
        }
        for (int j = 0; j <= k; ++j) {
            for (int d = 0; d < 10; ++d) {
                if (delta[i][d] == -1 || j < delta[i][d]) {
                    continue;
                }
                dp[i][j] |= dp[i + 1][j - delta[i][d]];
            }
        }
    }

    if (!dp[0][k]) {
        cout << -1 << "\n";
        return;
    }

    string res;
    for (int i = 0; i < n; ++i) {
        for (int d = 9; d >= 0; --d) {
            if (delta[i][d] == -1 || delta[i][d] > k) {
                continue;
            }
            if (dp[i + 1][k - delta[i][d]]) {
                k -= delta[i][d];
                res += char('0' + d);
                break;
            }
        }
    }

    cout << res << endl;


}