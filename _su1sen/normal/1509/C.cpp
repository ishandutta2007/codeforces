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

constexpr long long inf = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<long long> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s.begin(), s.end());
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, inf));
    for (int i = 0; i <= n; ++i) dp[i][i] = 0;
    for (int w = 1; w <= n; ++w) {
        for (int l = 0; l + w <= n; ++l) {
            int r = l + w;
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + s[r - 1] - s[l];
        }
    }
    cout << dp[0][n] << '\n';
    return 0;
}