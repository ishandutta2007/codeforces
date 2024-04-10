#include <bits/stdc++.h>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) iterable.begin(), iterable.end()

template <typename T>
void print_vector(vector<T>& vec, string sep = " ", string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}

constexpr int M = 100000;
constexpr long long INF = 1LL << 60;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(M, 0), y(M, 0), h(k + 1, 0);
    rep(i, n * k) {
        int t;
        cin >> t;
        ++x[t - 1];
    }
    rep(i, n) {
        int f;
        cin >> f;
        ++y[f - 1];
    }
    rep(i, k) { cin >> h[i + 1]; }
    vector<vector<long long>> dp(n + 1, vector<long long>(n * k + 1, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n * k; ++j) {
            for (int t = 0; t <= min(j, k); ++t) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - t] + h[t]);
            }
        }
    }
    long long ans = 0;
    rep(i, M) {
        ans += dp[y[i]][min(k * y[i], x[i])];
    }
    cout << ans << '\n';
    return 0;
}